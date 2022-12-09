/*
 * FreeRTOS Kernel V10.1.1
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

// Author:      Mohd A. Zainol
// Date:        1 Oct 2018
// Chip:        MSP432P401R LaunchPad Development Kit (MSP-EXP432P401R) for TI-RSLK
// File:        main_program.c
// Function:    The main function of our code in FreeRTOS

/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* TI includes. */
#include "gpio.h"

/* ARM Cortex */
#include <stdint.h>
#include "msp.h"
#include "SysTick.h"
#include "./inc/CortexM.h"

#include "./inc/songFile.h"
#include "./inc/dcMotor.h"
#include "./inc/bumpSwitch.h"
#include "./inc/outputLED.h"
#include "./inc/SysTick.h"

#define SW1IN ((*((volatile uint8_t *)(0x42098004)))^1)
#define SW2IN ((*((volatile uint8_t *)(0x42098010)))^1)

uint8_t bumpSwitch_status;
uint8_t status;
int mode;

static void Switch_Init(void);
static void taskMasterThread( void *pvParameters );
static void taskBumpSwitch (void *pvParameters);
static void taskPlaySong (void *pvParameters);
static void taskdcMotor (void *pvParameters);
static void taskReadInputSwitch (void *pvParameters);
SemaphoreHandle_t xSemaphore;
BaseType_t xHigherPriorityTaskWoken;
/*
 * Called by main() to create the main program application
 */
void main_program( void );




/*
 * The configuration of clocks for frequency.
 */
static void prvConfigureClocks( void );
xTaskHandle taskHandle_BlinkRedLED;
xTaskHandle taskHandle_BumpSwitch;
xTaskHandle taskHandle_PlaySong;
xTaskHandle taskHandle_dcMotor;
xTaskHandle taskHandle_InputSwitch;
xTaskHandle taskHandle_OutputLED;



static void taskDisplayOutputLED(void *pvParameters){
    if (mode==1){
        for( ;; ){
            outputLED_response_interrupt(status);
        }
    }
    else if (mode==2){
        for( ;; ){
            outputLED_response(bumpSwitch_status);
        }
    }
}



void main_program( void )
{
    prvConfigureClocks();
    Switch_Init();
    SysTick_Init();
    xTaskCreate(taskMasterThread, "taskT", 128, NULL, 2, &taskHandle_BlinkRedLED);
    xTaskCreate(taskBumpSwitch, "taskB", 128, NULL, 1, &taskHandle_BumpSwitch);
    xTaskCreate(taskPlaySong, "taskS", 128, NULL, 1, &taskHandle_PlaySong);
    xTaskCreate(taskdcMotor, "taskM", 128, NULL, 1, &taskHandle_dcMotor);
    xTaskCreate(taskReadInputSwitch, "taskR", 128, NULL, 1, &taskHandle_InputSwitch);
    xTaskCreate(taskDisplayOutputLED, "taskD", 128, NULL, 1, &taskHandle_OutputLED);
    vTaskStartScheduler();
    for( ;; );
}



/*-----------------------------------------------------------------*/
/*------------------- FreeRTOS configuration ----------------------*/
/*-------------   DO NOT MODIFY ANYTHING BELOW HERE   -------------*/
/*-----------------------------------------------------------------*/
// The configuration clock to be used for the board
static void prvConfigureClocks( void )
{
    // Set Flash wait state for high clock frequency
    FlashCtl_setWaitState( FLASH_BANK0, 2 );
    FlashCtl_setWaitState( FLASH_BANK1, 2 );

    // This clock configuration uses maximum frequency.
    // Maximum frequency also needs more voltage.

    // From the datasheet: For AM_LDO_VCORE1 and AM_DCDC_VCORE1 modes,
    // the maximum CPU operating frequency is 48 MHz
    // and maximum input clock frequency for peripherals is 24 MHz.
    PCM_setCoreVoltageLevel( PCM_VCORE1 );
    CS_setDCOCenteredFrequency( CS_DCO_FREQUENCY_48 );
    CS_initClockSignal( CS_HSMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
    CS_initClockSignal( CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
    CS_initClockSignal( CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
    CS_initClockSignal( CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1 );
}

// The sleep processing for MSP432 board
void vPreSleepProcessing( uint32_t ulExpectedIdleTime ){}

#if( configCREATE_SIMPLE_TICKLESS_DEMO == 1 )
    void vApplicationTickHook( void )
    {
        /* This function will be called by each tick interrupt if
        configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
        added here, but the tick hook is called from an interrupt context, so
        code must not attempt to block, and only the interrupt safe FreeRTOS API
        functions can be used (those that end in FromISR()). */
        /* Only the full demo uses the tick hook so there is no code is
        executed here. */
    }
#endif
/*-----------------------------------------------------------------*/
/*-------------   DO NOT MODIFY ANYTHING ABOVE HERE   -------------*/
/*--------------------------- END ---------------------------------*/
/*-----------------------------------------------------------------*/



static void Switch_Init(void){
    // negative logic built-in Button 1 connected to P1.1
    // negative logic built-in Button 2 connected to P1.4
    P1->SEL0 &= ~0x12;
    P1->SEL1 &= ~0x12;      // configure P1.4 and P1.1 as GPIO
    P1->DIR &= ~0x12;       // make P1.4 and P1.1 in
    P1->REN |= 0x12;        // enable pull resistors on P1.4 and P1.1
    P1->OUT |= 0x12;        // P1.4 and P1.1 are pull-up
}



static void taskReadInputSwitch( void *pvParameters ){

    char i_SW1=0;
    int i;

    for( ;; )
    {
        if (SW1IN == 1) {
            i_SW1 ^= 1;                 // toggle the variable i_SW1
            for (i=0; i<500000; i++);  // this waiting loop is used
        }
        if (i_SW1 == 1) {
            REDLED = 1;
            vTaskSuspend( taskHandle_PlaySong );
        }
        else {
            REDLED = 0;
            vTaskResume( taskHandle_PlaySong );
        }

    }
}



static void taskPlaySong(void *pvParameters){
    init_song_pwm();
    while (1){
        play_song();
    }
}



void BumpEdgeTrigger_Init(void){
    P4->SEL0 &= ~0xED;
    P4->SEL1 &= ~0xED;      // configure as GPIO
    P4->DIR &= ~0xED;       // make in
    P4->REN |= 0xED;        // enable pull resistors
    P4->OUT |= 0xED;        // pull-up
    P4->IES |= 0xED;        // falling edge event
    P4->IFG &= ~0xED;       // clear flag
    P4->IE |= 0xED;         // arm the interrupt
    // priority 2 on port4
    NVIC->IP[9] = (NVIC->IP[9]&0xFF00FFFF)|0x00400000;
    // enable interrupt 38 in NVIC on port4
    NVIC->ISER[1] = 0x00000040;
}



static void taskMasterThread( void *pvParameters )
{
    int i;

    ColorLED_Init();
    RedLED_Init();
    while(!SW2IN&&!SW1IN){                  // Wait for SW2 switch
        for (i=0; i<500000; i++);  // Wait here waiting for command
        REDLED = !REDLED;           // The red LED is blinking
    }
    if SW1IN{
        mode=1;
        xSemaphore = xSemaphoreCreateBinary();
    }
    else if SW2IN{
        mode=2;
    }
    REDLED=0;
    for (i=0; i<1000000; i++);  // Wait here waiting for command
    vTaskSuspend( taskHandle_BlinkRedLED );
}



//void turn_direction(int direction, int time){
//    if (direction==1){                      // direction 1 means turning left
//        Port2_Output2(GREEN);                // LED green means moving backward
//        dcMotor_Backward(500,10);
//        Port2_Output2(RED);                  // LED red means motor stops
//        dcMotor_Stop(500);
//        Port2_Output2(YELLOW);               // LED yellow means turning left
//        dcMotor_Left(500,time);        // turns left using "time" passed by function
//        Port2_Output2(RED);
//        dcMotor_Stop(500);
//    }
//    if (direction==2){                      // direction 2 means turning right
//        Port2_Output2(GREEN);                // LED green means moving backward
//        dcMotor_Backward(500,10);
//        Port2_Output2(RED);                  // LED red means motor stops
//        dcMotor_Stop(500);
//        Port2_Output2(BLUE);                 // LED blue means turning right
//        dcMotor_Right(500,time);       // turns right using "time" passed by function
//        Port2_Output2(RED);
//        dcMotor_Stop(500);
//    }
//}



void PORT4_IRQHandler(void){
    xHigherPriorityTaskWoken = pdFALSE;
    status = P4->IV;
    P4->IFG &= ~0xED; // clear flag
    xSemaphoreGiveFromISR(xSemaphore,&xHigherPriorityTaskWoken);
}



static void taskBumpSwitch(void *pvParameters){
    if (mode==1){
        BumpEdgeTrigger_Init();
        for( ;; ){
            if( xSemaphoreTakeFromISR( xSemaphore, &xHigherPriorityTaskWoken ) == pdTRUE){
                Port2_Output2(GREEN);
                interrupt_response(status);
            }
        }
    }
    else if (mode==2){
        BumpSwitch_Init();
        for( ;; ){
            bumpSwitch_status = Bump_Read_Input();
        }
    }
}



static void taskdcMotor(void *pvParameters){
    dcMotor_Init();
    if (mode==1){
        while (1){
            dcMotor_Forward(500, 1);
        }
    }
    else if (mode==2){
        while (1){
            dcMotor_response(bumpSwitch_status);
        }
    }
}
