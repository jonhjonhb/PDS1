#include <stdio.h>

void main() {

float a = 3.14159, b = 2.71828, e , p;

	p = a;
	e = b;
	b = p;
	a = e;

	printf("\nPI = %f", b);

	printf("\nEULER = %f", a);

}
