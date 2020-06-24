/*
  Copyright (c) 2020 Fabian Mink <fabian.mink@gmx.de>
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "control.h"
#include <math.h>

#define TI_MIN 1e-15;


int control_init_pictrl(pictrl_t* controller, float Kp, float Ti, float Ts){
	controller->i_val = 0.0f;
	controller->max = INFINITY;
	controller->min = -INFINITY;

	controller->kp = Kp;
	if(Ti > 0.0f){
		controller->ki = (Ts*Kp/Ti);		
	}
	else {
		controller->ki = 0.0; //integrator off		
	}

	return(0);
}


float control_pictrl(pictrl_t* controller, float ref, float act){

	float ctrldiff;
	float p_val, i_val;
	float out;

	ctrldiff = (ref - act);
	p_val = controller->kp * ctrldiff;
	if(controller->ki){	
		i_val = controller->ki * ctrldiff + controller->i_val;
	}
	else {
		i_val = 0.0f;
	}

	out = p_val + i_val;	
	
	if(out > controller->max){
		out = controller->max;
        	i_val = controller->max - p_val;
    	}
    	if(out < controller->min){
        	out = controller->min;
		i_val = controller->min - p_val;
    	}    
	
	controller->i_val = i_val;
	return(out);
}


