#include <stdio.h>
#include "pgenerator.h"


int16_t  val[]      = {100, 200, 500, 600, 400, 400, -600, -400, -300};
uint32_t deltapos[] = {  1,   1,   3,   1,  10,   0,   10,   20,    0};

pgenerator_lin_int16_data_t myInterp = {
	.numpos = 9,
	.val = val,
	.deltapos = deltapos,
	.cnt = 0,
	.pos = 0
};

int main(void){
	int16_t out;
	int end;
	
	FILE *file = fopen("out.csv", "w");
	
	
	int len = pgenerator_lin_int16_totalLen(&myInterp);
	printf("Total lenght: %i\n", len);

	
	for(int i = 0; i<70; i++){
		end = pgenerator_lin_int16(&myInterp, &out);
		printf("%05i:  %05i  -   cnt:%05i, pos:%05i, end:%01i\n", i, out, myInterp.cnt, myInterp.pos, end);
		//printf("%05i, %05i\n", i, out);
		fprintf(file, "%05i, %05i\n", i, out);
	}
	
	fclose(file);
	
	return(0);
		
}