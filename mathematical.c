/*
 * mathematical.c
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton Braga Júnio
 *      E-mail:	adailton.braga@acad.ufsm.br
 */

#include "mathematical.h"


/*
 * Integrator discretized by bilinear transform
 *
 * G(z) = 0.5 * Ts * (z + 1) / (z - 1)
 * y[k] = y[k-1] + (x[k] + x[k-1]) * Tsamp * 0.5
 */
float integrator_tustin(float y_prev, float x, float x_prev, float Tsamp_2) {
    return y_prev + (x + x_prev) * Tsamp_2;
}

/*
 * Integrator discretized by forward Euler
 *
 * G(z) = Ts / (z + 1)
 * y[k+1] = y[k] + Ts * x[k]
 */
float integrator_forward_euler(float y, float x, float Tsamp) {
    return  y + Tsamp * x;
}

/*
 * PI controller discretized by Tustin
 *
 * G(s) = kp + ki / s
 * G(z) = (a* z + b) / (z - 1); Kt = 2 / Tsamp
 * y[k] = y[k-1] + a * x[k] + b * x[k-1]
 * a = (kp + ki / Kt)
 * b = (-kp + ki/Kt)
 */
float pi_tustin(float y_prev, float x, float x_prev, float a, float b) {
    return y_prev + a * x + b * x_prev;
}


/*
 * First order filter discretized by Tustin
 *
 * G(s) = wc / (s + wc)
 * G(z) = wc * (z + 1) / ( (Kt + wc) * z + (wc - Kt)), Kt = 2 / Tsamp
 * y[k] = a * y[k] + b * (x[k] + x[k-1])
 * a = (Kt - wc) / (Kt + wc)
 * b = wc / (Kt + wc)
 */
float first_order_filter_tustin(float y_prev, float x, float x_prev, float a, float b) {
	return a * y_prev + b * (x + x_prev);
}
