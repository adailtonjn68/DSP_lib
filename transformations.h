/*
 * transformations.h
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton
 */

#ifndef TRANSFORMATIONS_H_
#define TRANSFORMATIONS_H_

#include <math.h>


void transformLine2Phasevoltages(float vab, float vbc, float *va, float *vb, float *vc);
void transform_ABC_AlphaBeta(float a, float b, float c, float *alpha, float *beta);
void transform_AlphaBeta_ABC(float alpha, float beta, float *a, float *b, float *c);
void transform_AlphaBeta_DQ(float alpha, float beta, float *d, float *q, float cos_theta, float sin_theta);
void transform_DQ_AlphaBeta(float d, float q, float *alpha, float *beta, float cos_theta, float sin_theta);


void transform_line_to_phasevoltages_arrays(float vab_bc[2], float vabc[3]);
void transform_ABC_AlphaBeta_arrays(float abc[3], float alpha_beta[2]);
void transform_AlphaBeta_ABC_aarays(float alpha_beta[2] ,float abc[3]);
void transform_AlphaBeta_DQ_arrays(float alpha_beta[2], float dq[2], float cos_theta, float sin_theta);
void transform_DQ_AlphaBeta_arrays(float dq[2], float alpha_beta[2], float cos_theta, float sin_theta);

#endif /* USER_LIB_TRANSFORMATIONS_H_ */
