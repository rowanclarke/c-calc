#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "calc.h"
#include "trig.h"

int main(void) {
	int i, n = 2;
	float a[] = {5, 2};
	float *c = calloc(n, sizeof(float)); 
	
	sine(a, c, n);
	
	for (i = 0; i < n; i++) printf("%f ", *(c+i));
	free(c);
	return 0;
}


