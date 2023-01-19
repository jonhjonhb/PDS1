#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

void zeraMatriz(int M[][MAX_TAM], int n){
	int j=0, i=0;
	for(j=0; j<n; j++)
		for(i=0; i<n; i++)
		{
			M[i][j] = 0;
		}
}

void imprimeMatriz(int M[][MAX_TAM], int n)
{
	int j=0, i=0;
	for(j=0; j<n; j++){
		for(i=0; i<n; i++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}

void criaBloco(int M[][MAX_TAM], int linha, int coluna, int tam)
{
	int i=0, j=0;
	for(i=0; i<tam; i++)
		for(j=0; j<tam; j++)
		{
			M[linha+i][coluna+j] = 1;
		}
}

int confereFloat(float x)
{
	
	float valor;
	int aux;

	valor = x;
	aux = x;

	if (aux == valor)
		return 0;
	else
		return 1;
}

int insereBloco(int M[][MAX_TAM], int n, Bloco b)
{
	
	if((b.linha+b.tam)>n || (b.coluna+b.tam)>n)
		return 0;
	else if( b.linha>n || b.coluna>n )
		return 0;
	else if( b.tam <= 0 )
		return 0; 
	else if (confereFloat(n))
		return 0;
	else if (n <= 0)
		return 0;
	else {
		criaBloco(M, b.linha, b.coluna, b.tam);	
		return 1;
	}
}

int tamBloco(int M[][MAX_TAM], int n, int i, int j)
{
	int tam = 0;
	int x = 0;
	for(x = j; x<n; x++)
		{
			if(M[i][x]==1)
				tam++;
			else
				break;
		}

	return tam;
}

Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j)
{
	int tam = 0;

	tam = tamBloco(M, n, i, j);

	Bloco maior;

	maior.linha = i;
	maior.coluna = j; 
	maior.tam = tam;

	return maior;
}

void encontraBlocos(int M[][MAX_TAM], int n, Bloco blocos[], int *numBlocos)
{
	int i = 0, j = 0;
	int count = 0;

	for (i=0; i<n; i++)
		for(j=0; j<n; j++){
			if(tamBloco(M, n, i, j)!=0){
				blocos[count] = maiorBloco(M, n, i, i);
				count++;
			}
		}

	*numBlocos = count;
}

void tranforma_string(char x[])
{	
	int i=0;
	//Transforma letra minuscula em maiuscula
	for (i=0; x[i]!='\0'; i++)
		if (x[i] > 96 && x[i] < 123)
			x[i] -= 32;
}

int similar(char str[])
{
	int i = 0, indice = 0, aux = 0;
	int strInt[126];

	tranforma_string(str);
	
	//zerar vetor
	for(i=0; i<126; i++){
		strInt[i] = 0;
	}
	
	//contador de quantidade de cada caracter
	int j = 0;
	for(j=0; str[j]!=0 ; j++){
		if(str[j]>126){
			i++;
			continue;
		}else if(str[j]==10){
			i++;
			continue;
        } else {
			indice = str[j];
			strInt[indice]++;
            printf("strInt[%d] == '%c' = %d \n", indice, indice, strInt[indice]);
        }
	}

	int x = 0;
	for(x=0; x<126 ; x++){
		if (strInt[x]>0){
			aux++;
		}
	}
	
	return aux;
}

int numCharsDiferentes(char str[])
{
	int count = 0;
	count = similar(str);

	return count;
}

float compX(Retangulo ret)
{
	float x_comp = 0;
	x_comp = abs(ret.inf_dir.x - ret.sup_esq.x);

	return x_comp;
}

float compY(Retangulo ret)
{
	float y_comp = 0;
	y_comp = abs(ret.inf_dir.y - ret.sup_esq.y);

	return y_comp;
}

double distPonto(Circulo cir, float px, float py)
{
	return sqrt(pow((px-cir.centro.x),2)+pow((py-cir.centro.y),2));
}

int colisao(Circulo cir, Retangulo ret)
{
	Ponto sup_dir;
	sup_dir.x = ret.inf_dir.x;
	sup_dir.y = ret.sup_esq.y;

	Ponto inf_esq;
	inf_esq.x = ret.sup_esq.x;
	inf_esq.y = ret.inf_dir.y;

	int v1=0, v2=0, v3=0, v4=0;
	v1 = distPonto(cir, ret.sup_esq.x, ret.sup_esq.y);
	v2 = distPonto(cir, sup_dir.x, sup_dir.y);
	v3 = distPonto(cir, ret.inf_dir.x, ret.inf_dir.y);
	v4 = distPonto(cir, inf_esq.x, inf_esq.y);
	
	int count = 0 ;

	if(v1<=cir.raio || v2<=cir.raio || v3<=cir.raio || v4<=cir.raio)
		count = 1;

	float x_comp = compX(ret);
	float y_comp = compY(ret);
	float i = ret.sup_esq.y, j = ret.sup_esq.x;
	double v = 0;

	for(i = ret.sup_esq.y; i<i+y_comp; i++)
		for(j = ret.sup_esq.x; j<j+x_comp; j++){
			v = distPonto(cir, j, i);
			if(v<=cir.raio)
				count++;
		}

	if (count>0)
		return 1;
	else 
		return 0;
}

int colisaoCirculoRetangulo(Circulo cir, Retangulo ret)
{
	if(colisao(cir, ret))
		return 1;
	else 
		return 0;
}