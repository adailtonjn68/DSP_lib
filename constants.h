/*
 * constants.h
 *
 *  Created on: 7 de fev de 2022
 *      Author: Humberto
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#ifndef Ts
    #define Ts  50e-6
#endif
#ifndef Ts_2
	#define Ts_2 Ts*0.5
#endif

#ifndef PI
	#define PI 3.14159265358979323846
#endif
#ifndef PI2
	#define PI2 (PI*2)
#endif

#ifndef D1_3
	#define D1_3        0.333333333333333
#endif
#ifndef D2_3
	#define D2_3        0.666666666666667
#endif
#ifndef R1_3    // 1/sqrt(3)
    #define R1_3    0.57735026918963
#endif
#ifndef R3_2    // sqrt(3)/2
    #define R3_2    0.86602540378444
#endif
#define R3_3        0.577350269189626   // sqrt(3)/3



#endif /* USER_LIB_CONSTANTS_H_ */
