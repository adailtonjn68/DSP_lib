/*
 * resonant_controller.h
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton Braga Júnior
 */

#ifndef RESONANT_CONTROLLER_H_
#define RESONANT_CONTROLLER_H_

/*
 * RESSONANT CONTROLLERS
 *
 * C(z) = K (z - 1) / ( z^2 - d1 * z - d2)
 */
typedef struct {
    float K;
    float d1, d2;
    float superior_limit, inferior_limit;
    float y0, y1, y2;
} Resonant;

void resonantControl_reset(Resonant *resonant, float init_state);
void resonantControl_update(Resonant *resonant, float erro0, float erro2);



#endif /* RESONANT_CONTROLLER_H_ */
