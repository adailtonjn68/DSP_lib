/*
 * resonant_controller.c
 *
 *  Created on: 7 de fev de 2022
 *      Author: Adailton Braga J�nior
 */

#include "resonant_controller.h"

/*
 * UPDATE RESONANT CONTROLLER
 *
 * C(z) = K (z^2 - 1) / (z^2 - d1 * z - d2)
 */
void resonantControl_update(Resonant *resonant, float erro0, float erro2) {
    resonant->y2 = resonant->y1;
    resonant->y1 = resonant->y0;

    resonant->y0 = resonant->d1 * resonant->y1 + resonant->d2 * resonant->y2 + resonant->K * (erro0 - erro2);

    if (resonant->y0 > resonant->superior_limit) resonant->y0 = resonant->superior_limit;
    else if (resonant->y0 < resonant->inferior_limit) resonant->y0 = resonant->inferior_limit;
}

/*
 * Reset resonant controller to a initial state
 */
void resonantControl_reset(Resonant *resonant, float init_state) {
    resonant->y2 = resonant->y1;
    resonant->y1 = resonant->y0;
    resonant->y0 = init_state;
}

