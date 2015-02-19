// ArrayMulC.cpp

#include "ArrayMulC.h"

void array_mul_c(long array_of_int[], unsigned mul, unsigned count)
{
	for (auto i = 0; i != count; ++i)
		array_of_int[i] *= mul;
}
