/*
 * SRF_PLL.c
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton
 *      E-mail: adailton.braga@acad.ufsm.br
 */



#include "SRF_PLL.h"


void SRF_PLL_init(SRF_PLL_t *PLL) {
	PLL->vd_filt = 0;
	PLL->vq_filt = 0;
	PLL->vq_norm = 0;
	PLL->wgrid = 0;
	PLL->theta = 0;
}


/*
 * SYNCHRONOUS REFERENCE FRAME PHASE-LOCKED LOOP
 */
void SRF_PLL_update(SRF_PLL_t *PLL) {
    PLL->theta = PLL->theta_next;
    PLL->cos_theta = cos(PLL->theta);
    PLL->sin_theta = sin(PLL->theta);

    // AlphaBeta -> DQ
    PLL->vd_prev = PLL->vd; PLL->vq_prev = PLL->vq;
    transform_AlphaBeta_DQ(PLL->valpha, PLL->vbeta, &PLL->vd, &PLL->vq, PLL->cos_theta, PLL->sin_theta);

    // Filter Vdq
    PLL->vd_filt = first_order_filter_tustin(PLL->vd_filt, PLL->vd, PLL->vd_prev, PLL_filt_a, PLL_filt_b);
    PLL->vq_filt = first_order_filter_tustin(PLL->vq_filt, PLL->vq, PLL->vq_prev, PLL_filt_a, PLL_filt_b);

    // Peak voltage
    PLL->vpeak = sqrt(PLL->vd_filt * PLL->vd_filt + PLL->vq_filt * PLL->vq_filt);
    if (PLL->vpeak < 1.0) PLL->vpeak = 1.0;

    // Normalize vq
    PLL->vq_norm_prev = PLL->vq_norm;
    PLL->vq_norm = PLL->vq_filt / PLL->vpeak;

    // PI controller
    PLL->wgrid = pi_tustin(PLL->wgrid, PLL->vq_norm, PLL->vq_norm_prev, PLL_PI_a, PLL_PI_b);

    if (PLL->wgrid > 500) 		PLL->wgrid =  500;
    else if (PLL->wgrid < -500) PLL->wgrid = -500;

    // Integrate
    PLL->theta_next = integrator_forward_euler(PLL->theta, PLL->wgrid, PLL_Ts);
    if (PLL->theta_next > PI2) 		PLL->theta_next -= PI2;
    else if (PLL->theta_next < 0) 	PLL->theta_next += PI2;
}

