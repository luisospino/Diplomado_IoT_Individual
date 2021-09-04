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

void delay_block( void ){
	uint32_t i;
	for(i = 0; i < 0x1B3331 ; i++);
}

int main(void) {
	uint32_t adc_sensor_luz;
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
    bool cambio = false;

    while(1) {
        i++ ;

        for(short k = 0; k < 3 ; k++ ) {
			encender_led_verde();
			delay_block();
			apagar_led_verde();
			delay_block();
		}

		if( !cambio ){
			cambio = true;
			encender_led_rojo();
			delay_block();
		}else{
			cambio = false;
			apagar_led_rojo();
			delay_block();
		}

		printf("%i - ", sensorDeLuzObtenerDatoADC());
    }

    return 0 ;
}


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
