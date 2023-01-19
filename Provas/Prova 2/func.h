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

void zeraMatriz(int M[][MAX_TAM], int n);

void imprimeMatriz(int M[][MAX_TAM], int n);

void criaBloco(int M[][MAX_TAM], int linha, int coluna, int tam);

int confereFloat(float x);

int insereBloco(int M[][MAX_TAM], int n, Bloco b);

int tamBloco(int M[][MAX_TAM], int n, int i, int j);

Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j);

void encontraBlocos(int M[][MAX_TAM], int n, Bloco blocos[], int *numBlocos);

int numCharsDiferentes(char str[]);

int colisaoCirculoRetangulo(Circulo cir, Retangulo ret);