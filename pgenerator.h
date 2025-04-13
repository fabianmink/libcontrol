#include <stdint.h>

typedef struct
{
	unsigned int numpos;
	int16_t*  val;
	uint32_t* deltapos;
	unsigned int cnt;
	uint32_t pos;
} pgenerator_lin_int16_data_t;

extern int16_t pgenerator_lin_int16(pgenerator_lin_int16_data_t* data);