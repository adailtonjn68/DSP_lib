/*
 * user_lib.h
 *
 *  Created on: 26 de jan de 2022
 *      Author: Adailton Braga J�nior
 *              adailton.braga@acad.ufsm.br
 */

#ifndef DSP_LIB_H_
#define DSP_LIB_H_

#include <math.h>
#include "constants.h"
#include "mathematical.h"


//void main_control() __attribute__((weak));
void main_control();
void init_controllers();

void saturate_control_action(float *vd, float *vq, float vdc);


void zsm(float ualpha, float ubeta, float *ua, float *ub, float *uc);



#endif /* DSP_LIB_H_ */
