/*
 * user_lib.h
 *
 *  Created on: 26 de jan de 2022
 *      Author: Adailton Braga J�nior
 *              adailton.braga@acad.ufsm.br
 */


#include "DSP_lib.h"


void  main_control() {

}

void init_controllers() {

}


/*
 * Zero sequence modulator
 */
void zsm(float ualpha, float ubeta, float *ua, float *ub, float *uc) {
    float u0max, u0min, u0;
    const float c1 = -1. - ualpha;
    const float c2 = -1. + 0.5 * ualpha - R3_2 * ubeta;
    const float c3 = -1. + 0.5 * ualpha + R3_2 * ubeta;
    const float c4 = c1 + 2;
    const float c5 = c2 + 2;
    const float c6 = c3 + 2;

    u0min = MAX(c1, c2);
    u0min = MAX(c3, u0min);
    u0max = MIN(c4, c5);
    u0max = MIN(c6, u0max);
//    if (c1 > c2) u0min = c1;
//    else u0min = c2;
//    if (c3 > u0min) u0min = c3;
//    if (c4 < c5) u0max = c4;
//    else u0max = c5;
//    if (c6 < u0max) u0max = c6;

    u0 = 0.5 * (u0max + u0min);

    *ua = ualpha + u0;
    *ub = -0.5 * ualpha + R3_2 * ubeta + u0;
    *uc = -0.5 * ualpha - R3_2 * ubeta + u0;
}




/*
 * Saturate control action based on the DC link voltage
 *
 */
void saturate_control_action(float *ud, float *uq, float vdc) {
    const float upeak = sqrt((*ud) * (*ud)+ (*uq) * (*uq));
    if (upeak > R1_3 * vdc) {
        *ud = (*ud) * R1_3 * vdc / upeak;
        *uq = (*uq) * R1_3 * vdc / upeak;
    }
}




