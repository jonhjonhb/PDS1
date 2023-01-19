#include <stdio.h>
#define MAX 1000

int cal_fib(int x, double fib[]){
	fib[0] = 1;
	fib[1] = 1;
	int i = 0;
	for (i = 2; i<=x; i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	return x;
}

void pega_fib(){
	int x = 0;
	double fib[MAX];
	do {
		printf("\nDigite o fibonacci desejado:");
		scanf("%d", &x);
			if (x>=0 && x<=MAX){
				printf("\nFib(%d): ", x);
				cal_fib(x, fib);
				printf("%4.3e\n", fib[x]);
			} else 
			printf("FIM.\n");
	} while (x>=0 && x<=MAX);
	

}