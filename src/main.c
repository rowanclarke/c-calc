#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add(float *a, float *b, float *c, int n);
void subtract(float *a, float *b, float *c, int n);
void conjugate(float *a, float *b, int n);
void multiply(float *a, float *b, float *c, int n);
void reciprocal(float *a, float *b, float *c, int n);

int main(void) {
	int i, n = 4;
	float a[] = {-12, 25, -6, 54};
	float b[] = {5, 4, 2, 4};
	float *c = calloc(n, sizeof(float)); 
	
	for (i = 0; i < n; i++) printf("%f ", *(c+i));
	free(c);
    return 0;
}

void add(float *a, float *b, float *c, int n) {
	int i;
	for (i = 0; i < n; i++) *(c+i) = *(a+i)+*(b+i);
}

void subtract(float *a, float *b, float *c, int n) {
	int i;
	for (i = 0; i < n; i++) *(c+i) = *(a+i)-*(b+i); 
}

void conjugate(float *a, float *b, int n) {
	int i;
	for (i = 0; i < n; i++) *(b+i) = (i > 0) ? -*(a+i) : *(a+i);
}

void multiply(float *a, float *b, float *c, int n) {
	if (n == 1) {
		*c = (*a)*(*b);
	}
	else {
		int m = n/2;
		int i;
		float *f = calloc(6*m, sizeof(float));
		conjugate(b+m, f+2*m, m);
		conjugate(b, f+5*m, m);
		multiply(a,b,f,m);
		multiply(f+2*m,a+m,f+m,m);
		multiply(b+m,a,f+3*m,m);
		multiply(a+m,f+5*m,f+4*m,m);
		for (i = 0; i < m; i++) {
			*(c+i)=*(f+i)-*(f+m+i);
			*(c+m+i)=*(f+3*m+i)+*(f+4*m+i); 
		}
		free(f);
	}
}

void reciprocal(float *a, float *b, float *c, int n) {
	int i;
	conjugate(b, c, n);
	float k = 0;
	for (i = 0; i < n; i++) k += b[i] * b[i];
	for (i = 0; i < n; i++) c[i] /= k;
}

