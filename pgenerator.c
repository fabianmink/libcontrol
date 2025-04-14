#include "pgenerator.h"

//Piecewise linear interpolator
int pgenerator_lin_int16(pgenerator_lin_int16_data_t* data, int16_t* val){
	*val = 0;
	if(data->numpos == 0) return(1);
	
	uint32_t deltapos;

	while( ((deltapos = data->deltapos[data->cnt]) == 0) && (data->cnt < (data->numpos-1) ) ) {
		data->cnt++;
	}

	if(data->cnt < (data->numpos-1) ){
		
		int16_t a = data->val[data->cnt];
		int16_t b = data->val[data->cnt + 1];
		int64_t tmp;
		//Linear interpolate btw. a and b using pos/(deltapos+1)
		//val = a + (b-a)* data->pos / (deltapos+1);

		tmp = ((int32_t)(b-a)) * (int32_t)(data->pos);
		*val = a + (int16_t)(tmp/ (int32_t)(deltapos));

		if(data->pos >= deltapos-1){
			data->pos = 0;
			data->cnt++;
		}
		else {
			data->pos++;
		}
	}
	else {
		*val = data->val[data->numpos-1];
		if(data->pos >= deltapos){
			return(1);
		}
		else {
			data->pos++;
		}
	}
	return(0);
}

uint32_t pgenerator_lin_int16_totalLen(pgenerator_lin_int16_data_t* data){
	uint32_t len = 0;
	for (unsigned int i = 0; i < data->numpos; i++){
		len += data->deltapos[i];	
	}
	return(len);
}
