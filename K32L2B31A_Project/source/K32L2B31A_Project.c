/*! @file : K32L2B31A_Project.c
 * @author  Luis Ospino
 * @version 0.0.000
 * @date    31/08/2021
 * @brief   Funcion principal main
 * @details
 *			v0.0.000	Proyecto base creado usando MCUXpresso
 *
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"

#include "leds.h"
#include "sensor_luz.h"
#include "irq_lptmr0.h"
#include "botones.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/


/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

int main(void) {
	uint32_t sensor_luz;
	bool boton1, boton2;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    //printf("Inicia");

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */

    //EnableIRQ(DEMO_LPTMR_IRQn);
    LPTMR_StartTimer(LPTMR0);

    while(1) {

    	if( lptmr0_iqr_counter != 0 ){
    		toggle_led_rojo();
    		lptmr0_iqr_counter = 0;

    		i++;
			sensor_luz = sensorDeLuzObtenerDatoADC();
			printf("ADC Sensor de luz: %u\r\n", sensor_luz);
			boton1 = boton1LeerEstado();
			boton2 = boton2LeerEstado();
			printf("BTN1: %u\r\n", boton1);
			printf("BTN2: %u\r\n", boton2);
    	}

    }

    return 0 ;
}


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
