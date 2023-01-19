#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TAM 100

typedef struct Bloco {
    int linha, coluna, tam;
} Bloco;

typedef struct Ponto {
    float x, y;
} Ponto;

typedef struct Circulo {
    Ponto centro;
    float raio;
} Circulo;

typedef struct Retangulo {
    Ponto sup_esq, inf_dir; 
} Retangulo;

void zeraMatriz(int M[][MAX_TAM], int n){
	int j=0, i=0;
	for(j=0; j<n; j++){
		for(i=0; i<n; i++){
			M[j][i] = 0;
		}
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

void retiraBloco(int M[][MAX_TAM], int i, int j, int tam){
    
    int x=i, y=j;
    
    for(x=i; x<i+tam; x++){
		for(y=j; y<j+tam; y++){
			M[x][y] = 2;
		}
	}
}

int verifica(int M[][MAX_TAM], int i, int j){
    
    int x = 0, y = 0;
    int count1 = 0, count2 = 0, count3 = 0;
    
    //verifica coluna
    for(x=0; x<i; x++){
        if(M[x][j] != 1){
            count1++;
            break;
        }
    }

    //verifica linha
    for(y=0; y<j; y++){
        if(M[i][y] != 1){
            count2++;
            break;
        }
    }
    
    if(M[i][j] != 1)
        count3 = 1;
        

    if(count1>0)
        return 0;
    else if(count2>0)
        return 0;
    else if(count3)
        return 0;
    else
        return 1;
    /*
    if(count1 == i && count2 == j && count3==1)
        return 1;
    else 
        return 0;
    */
}

int tamBloco(int M[][MAX_TAM], int n, int i, int j)
{
	int tam = 0;
	int x = j, z = i;
	int aux = 0;
	
    if(M[i][j]==1)
		tam++;
    
    x++;
    z++;
    
    if(M[z][x]==1 && M[i][x]==1 && M[i][j]==1)
        tam++;
    
    x++;
    z++;
    
    while(z<n && x<n){
    	if(verifica(M, z, x)){
    	    tam++;
    	    x++;
    	    z++;
    	}else 
    		break;
	}

	return tam;
}

Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j)
{
	int tam = 0;

	//if(M[i][j]==1)
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
	int tam = 0;

	for (i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(M[i][j]==1){
			   	blocos[count] = maiorBloco(M, n, i, j);
			   	tam = tamBloco(M, n, i, j);
			   	retiraBloco(M, i, j, tam);
				count++;
			}
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

	float i = ret.sup_esq.y, j = ret.sup_esq.x;
	double v = 0;

	for(i = ret.sup_esq.y; i<ret.inf_dir.y; i++)
		for(j = ret.sup_esq.x; j<ret.inf_dir.x; j++){
			v = distPonto(cir, i, j);
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

void main(){
    //Voce pode simular uma funcao main nesta funcao. Use-a para testar o que quiser. 
    //Para isso, execute a sua prova e entre com o exercicio 0.
    //Isso fara com que esta funcao (minha_main) seja chamada pelo VPL.
    //Importante: esta funcao NAO sera avaliada!!! No entanto, erros de compilacao nesta funcao invalidam (nota 0!) TODA a prova!
    
}