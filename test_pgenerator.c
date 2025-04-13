#include <stdio.h>
#include "pgenerator.h"


int16_t  val[]      = {100, 200, 500, 600, 400, 400, -600, -400, -300};
uint32_t deltapos[] = {  1,   1,   3,   0,  10,   0,   10,   20,   20};

pgenerator_lin_int16_data_t myInterp = {
	.numpos = 9,
	.val = val,
	.deltapos = deltapos,
	.cnt = 0,
	.pos = 0
};

int main(void){
	int16_t out;
	
	FILE *file = fopen("out.csv", "w");
	
	printf("Hello\n");
	
	for(int i = 0; i<100; i++){
		out = pgenerator_lin_int16(&myInterp);
		printf("%05i:  %05i  -   cnt:%05i, pos:%05i\n", i, out, myInterp.cnt, myInterp.pos);
		//printf("%05i, %05i\n", i, out);
		fprintf(file, "%05i, %05i\n", i, out);
	}
	
	fclose(file);
	
	return(0);
		
}