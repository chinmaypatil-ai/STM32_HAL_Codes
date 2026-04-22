/*
 * EncoderLib.c
 *
 *  Created on: Dec 15, 2025
 *      Author: Chinmay
 */
#include "Encoderlib.h"

void update_encoder(encoder_instance *encoder_value ,TIM_HandleTypeDef *htim){
	uint32_t temp_counter = __HAL_TIM_GET_COUNTER(htim);
	static uint8_t first_time = 0;
	if(!first_time){
		encoder_value->velocity = 0;
	}
}

void reset_encoder(encoder_instance *encoder_value){

}

