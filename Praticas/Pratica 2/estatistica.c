#include <math.h>

float pi = 3.141592;
float x, mi, beta, b;

float cauchy (float x){
	return 1/(pi*(1+pow(x,2)));
}

float gumbel (float beta, float x, float mi){
	return 1/beta*exp(-(x-mi)/beta-exp(-(x-mi)/beta));
}

float laplace (float x, float mi, float b){
	return 1/(2*b)*exp(-fabs(x-mi)/b);
}