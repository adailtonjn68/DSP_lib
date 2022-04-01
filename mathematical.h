/*
 * mathematical.h
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton Braga Júnio
 *      E-mail:	adailton.braga@acad.ufsm.br
 */

#ifndef MATHEMATICAL_H_
#define MATHEMATICAL_H_


#include <math.h>



#define MAX(a,b)	((a > b) ? a : b)
#define MIN(a,b)	((a < b) ? a : b)


float integrator_tustin(float y_prev, float x, float x_prev, float Tsamp_2);
float integrator_forward_euler(float y, float x, float Tsamp);
float pi_tustin(float y_prev, float x, float x_prev, float a, float b);
float first_order_filter_tustin(float y_prev, float x, float x_prev, float a, float b);

#endif /* MATHEMATICAL_H_ */
