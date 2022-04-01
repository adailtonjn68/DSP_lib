/*
 * SRF_PLL.h
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton Braga
 *      E-mail: adailton.braga@acad.ufsm.br
 */

#ifndef SRF_PLL_H_
#define SRF_PLL_H_

#include <math.h>
#include "constants.h"
#include "mathematical.h"
#include "transformations.h"



#define PLL_Ts		Ts
#define PLL_Kt		(2.0 / PLL_Ts)	// Tustin discretization gain
#define PLL_wc 		(PI2 * 10.0)	// Cutoff frequency
#define PLL_filt_a	((PLL_Kt - PLL_wc) / (PLL_Kt + PLL_wc))
#define PLL_filt_b 	(PLL_wc / (PLL_Kt + PLL_wc))
#define PLL_kp 		100.0
#define PLL_ki 		3200.0
#define PLL_PI_a 	( PLL_kp + PLL_ki / PLL_Kt)
#define PLL_PI_b 	(-PLL_kp + PLL_ki / PLL_Kt)


typedef struct {
    float valpha, vbeta;
    float vd, vq;
    float vd_prev, vq_prev;
    float vd_filt, vq_filt;
    float theta, theta_next;
    float cos_theta, sin_theta;
    float vpeak;
    float wgrid, wgrid_prev;
    float vq_norm, vq_norm_prev;
} SRF_PLL_t;


void SRF_PLL_init(SRF_PLL_t *PLL);
void SRF_PLL_update(SRF_PLL_t *PLL);



#endif /* SRF_PLL_H_ */
