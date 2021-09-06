/*! @file : sensor_luz.c
* @author  Luis Ospino
* @version 1.0.0
* @date    Sep 4, 2021
* @brief   Driver para
* @details
*
*/
/*******************************************************************************
* Includes
******************************************************************************/
#include "sensor_luz.h"

/*******************************************************************************
* Definitions
******************************************************************************/
#define SENSOR_LUZ_ADC16_BASE          ADC0
#define SENSOR_LUZ_ADC16_CHANNEL_GROUP 0U
#define SENSOR_LUZ_ADC16_USER_CHANNEL  3U /* PTE30, ADC0_SE3 */

/*******************************************************************************
* Private Prototypes
******************************************************************************/
void sensorDeLuzIniciarCaptura();

void sensorDeLuzEsperarResultado();

/*******************************************************************************
* External vars
******************************************************************************/


/*******************************************************************************
* Local vars
******************************************************************************/


/*******************************************************************************
* Private Source Code
******************************************************************************/
void sensorDeLuzIniciarCaptura(){
	ADC16_SetChannelConfig(SENSOR_LUZ_ADC16_BASE, SENSOR_LUZ_ADC16_CHANNEL_GROUP, &ADC0_channelsConfig[0]);
}

void sensorDeLuzEsperarResultado(){
	while (0U == (kADC16_ChannelConversionDoneFlag &
	                      ADC16_GetChannelStatusFlags(SENSOR_LUZ_ADC16_BASE, SENSOR_LUZ_ADC16_CHANNEL_GROUP))){
	}
}

/*******************************************************************************
* Public Source Code
******************************************************************************/

uint32_t sensorDeLuzObtenerDatoADC(){
	sensorDeLuzIniciarCaptura();
	sensorDeLuzEsperarResultado();
	uint32_t resultadoADC = ADC16_GetChannelConversionValue(SENSOR_LUZ_ADC16_BASE, SENSOR_LUZ_ADC16_CHANNEL_GROUP);

	return resultadoADC;
}

