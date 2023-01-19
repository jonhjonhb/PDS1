#include <math.h>

float metros(float v){
	float ms;
	return ms = v/3.6;
}

float circulo(float raio){
	float pi = 3.141592;
	return pi*pow(raio,2);
}

int maior(int n1, int n2, int n3){
	if (n1>=n2 && n1>=n3){
		return n1;
	} else if (n2>=n3 && n2>=n1){
		return n2;
	} else {
		return n3;
	}
}

int par(int n){
	if ((n%2) == 0){
		return 1;
	}else ((n%2) == 1);
		return 0;
}

int divisivel(int n){
	if (n%3==0 && n%5!=0){
	 	return 1;
	} else if (n%5==0 && n%3!=0){
	 	return 1;
	}else return 0;
}

float peso(float h, char s){
	if (s == 'M'){
		return (72.7 * h) -58;
	} else (s == 'F');
		return (62.1 * h) -44.7;
}

int somaImpares(int n){
	int x = 0; 
	int i=0;
	while (i<=n){
		if (par(i) == 0){	
		x = x + i;
		} i++;
	} return x;
}

double fatorial(int n){
	double f = 1;
	int i=2;
	do{
		f = f*i;
		i++;
	}
	while (i<=n);
	return f;
}

int somaNumerosDiv3ou5(int n){
	int s =0, i = 1;
	while (i<=n){
		if (i%3==0 && i%5!=0){
		s += i;
		i++;
		} else if (i%5==0 && i%3!=0){
		s += i;
		i++;
		} else
		i++;
	} return s;
}

float calculaMedia(int x, int y, int z, int operacao){
	if (operacao == 1){
		return pow(x*y*z, (1.0/3.0));
	} else if (operacao ==2){
		return (x+2*y+3*z)/6;
	} else if (operacao ==3){
		return 3/(1/x+1/y+1/z);
	} else (operacao ==4);
		return (x+y+z)/3;
}

int numeroDivisores(int n){
	int div = 1;
	int i = 2;
	while(i<=n){
		if (n%i==0){
			div++;
			i++;
		}  
		else 
			i++;
	} return div;
}

int enesimoFibonacci(int n){
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	int a=0, b=1, i = 3, enesimo;
	while(i<=n){
		enesimo = a + b; 
		a = b;
		b = enesimo;
		i++;
	} return enesimo;
}

int mdc(unsigned int x, unsigned int y){
	int i = 2;
	int menor, mx;
		if (x>y){
		menor = y;
		} else menor = x;
	while (i<=menor){
		if ((x%i==0) && (y%i==0)){
		mx = i;	
		i++;
		} else i++;
	} return mx;
}

int mmc(unsigned int x, unsigned int y){
	int i;
	int maior, minimo;
	if (x>y){
		maior =x;
	} else maior =y;
	while(1){
		if (maior%x==0 && maior%y==0)
			break;
		maior++;
	} return maior;
}

