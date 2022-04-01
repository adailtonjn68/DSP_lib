/*
 * transformations.c
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton
 */


#include "transformations.h"

#include "constants.h"


/*
 * Transform line voltages to phase voltages
 */
void transform_line_to_phasevoltages(float vab, float vbc, float *va, float *vb, float *vc) {
    *va = D1_3 * (2 * vab +     vbc);
    *vb = D1_3 * (   -vab +     vbc);
    *vc = D1_3 * (   -vab - 2 * vbc);
}


/*
 * Transform ABC to AlphaBeta
 */
void transform_ABC_AlphaBeta(float a, float b, float c, float *alpha, float *beta){
    *alpha = D2_3 * (a - 0.5 * (b + c));
    *beta  = R3_3 * (b - c);
}


void transform_AlphaBeta_ABC(float alpha, float beta, float *a, float *b, float *c) {
    *a = alpha;
    *b = -0.5 * alpha + R3_2 * beta;
    *c = -0.5 * alpha - R3_2 * beta;
}


void transform_AlphaBeta_DQ(float alpha, float beta, float *d, float *q, float cos_theta, float sin_theta) {
    *d =  cos_theta * alpha + sin_theta * beta;
    *q = -sin_theta * alpha + cos_theta * beta;
}


void transform_DQ_AlphaBeta(float d, float q, float *alpha, float *beta, float cos_theta, float sin_theta) {
    *alpha = cos_theta * d - sin_theta * q;
    *beta  = sin_theta * d + cos_theta * q;
}


/*
 * Transform line voltages to phase voltages by passing
 */
void transform_line_to_phasevoltages_arrays(float vab_bc[2], float vabc[3]) {
    vabc[0] = D1_3 * (2 * vab_bc[0] +     vab_bc[1]);
    vabc[1] = D1_3 * (   -vab_bc[0] +     vab_bc[1]);
    vabc[2] = D1_3 * (   -vab_bc[0] - 2 * vab_bc[1]);
}


void transform_ABC_AlphaBeta_arrays(float abc[3], float alpha_beta[2]) {
	alpha_beta[0] = D2_3 * (abc[0] - 0.5 * (abc[1] + abc[2]));
	alpha_beta[1]  = R3_3 * (abc[1] - abc[2]);
}


void transform_AlphaBeta_ABC_arrays(float alpha_beta[2] ,float abc[3]) {
    abc[0] = 		alpha_beta[0];
    abc[1] = -0.5 * alpha_beta[0] + R3_2 * alpha_beta[1];
    abc[2] = -0.5 * alpha_beta[0] - R3_2 * alpha_beta[1];
}


void transform_AlphaBeta_DQ_arrays(float alpha_beta[2], float dq[2], float cos_theta, float sin_theta) {
    dq[0] =  cos_theta * alpha_beta[0] + sin_theta * alpha_beta[1];
    dq[1] = -sin_theta * alpha_beta[0] + cos_theta * alpha_beta[1];
}


void transform_DQ_AlphaBeta_arrays(float dq[2], float alpha_beta[2], float cos_theta, float sin_theta) {
    alpha_beta[0] = cos_theta * dq[0] - sin_theta * dq[1];
    alpha_beta[1] = sin_theta * dq[0] + cos_theta * dq[1];
}
