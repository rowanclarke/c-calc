#ifndef TRIG
#define TRIG

#include <math.h>

void sine(float *a, float *b, int n);
void cosine(float *a, float *b, int n);

void sine(float *a, float *b, int n) {
	int i;
	float *e1 = calloc(n, sizeof(float));
	float *e2 = calloc(n, sizeof(float));
	float *half = calloc(n, sizeof(float));
	float *c = calloc(n, sizeof(float));
	float *d = calloc(n, sizeof(float));
	
	for (i = 0; i < n; i++) {
		*(e1+i) = (i == 1) ? 1 : 0;
		*(e2+i) = (i == 1) ? -1 : 0;
		*(half+i) = (i == 1) ? -0.5 : 0;
	}
	
	multiply(e1, a, e1, n);
	multiply(e2, a, e2, n);
	
	exponentiate(e1, c, n);
	exponentiate(e2, d, n);
	
	subtract(c, d, e1, n);
	multiply(half, e1, b, n);
}

void cosine(float *a, float *b, int n) {
	int i;
	float *e1 = calloc(n, sizeof(float));
	float *e2 = calloc(n, sizeof(float));
	float *half = calloc(n, sizeof(float));
	float *c = calloc(n, sizeof(float));
	float *d = calloc(n, sizeof(float));
	
	for (i = 0; i < n; i++) {
		*(e1+i) = (i == 1) ? 1 : 0;
		*(e2+i) = (i == 1) ? -1 : 0;
		*(half+i) = (i == 0) ? 0.5 : 0;
	}
	
	multiply(e1, a, e1, n);
	multiply(e2, a, e2, n);
	
	exponentiate(e1, c, n);
	exponentiate(e2, d, n);
	
	add(c, d, e1, n);
	multiply(half, e1, b, n);
}

#endif
