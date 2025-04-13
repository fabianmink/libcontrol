#include "pgenerator.h"

//Piecewise linear interpolator
int16_t pgenerator_lin_int16(pgenerator_lin_int16_data_t* data){
	if(data->numpos == 0) return(0);

	int16_t val = 0;
	if(data->cnt < (data->numpos-1) ){
		uint32_t deltapos = data->deltapos[data->cnt];
		int16_t a = data->val[data->cnt];
		int16_t b = data->val[data->cnt + 1];
		int64_t tmp;
		//Linear interpolate btw. a and b using pos/(deltapos+1)
		//val = a + (b-a)* data->pos / (deltapos+1);

		tmp = ((int32_t)(b-a)) * (int32_t)(data->pos);
		val = a + (int16_t)(tmp/ (int32_t)(deltapos+1));

		if(data->pos >= deltapos){
			data->pos = 0;
			data->cnt++;
		}
		else {
			data->pos++;
		}
	}
	else {
		uint32_t deltapos = data->deltapos[data->cnt];
		val = data->val[data->numpos-1];
		if(data->pos >= deltapos){
			//indicate end somehow
		}
		else {
			data->pos++;
		}
	}
	return(val);
}
