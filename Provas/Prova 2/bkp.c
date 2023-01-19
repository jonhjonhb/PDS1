#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//1)

void zeraMatriz(int M[][MAX_TAM], int n) {
    //seu codigo aqui
}


//2)

int insereBloco(int M[][MAX_TAM], int n, Bloco b) {
    //seu codigo aqui
    return -1; 
}

//3)

Bloco maiorBloco(int M[][MAX_TAM], int n, int i, int j) {
    //seu codigo aqui
    Bloco b;
    return b;
}

//4)

void encontraBlocos(int M[][MAX_TAM], int n, Bloco blocos[], int *numBlocos) {
    //seu codigo aqui
}

//5) 

int numCharsDiferentes(char str[]) {
    //seu codigo aqui
    return -1;
}

// 6

int colisaoCirculoRetangulo(Circulo cir, Retangulo ret) {
    //seu codigo aqui
    return -1;
}

// 0

void minha_main() {
    //Voce pode simular uma funcao main nesta funcao. Use-a para testar o que quiser. 
    //Para isso, execute a sua prova e entre com o exercicio 0.
    //Isso fara com que esta funcao (minha_main) seja chamada pelo VPL.
    //Importante: esta funcao NAO sera avaliada!!! No entanto, erros de compilacao nesta funcao invalidam (nota 0!) TODA a prova!
    
    printf("\nPor enquanto nao estou fazendo nada :(");
    
}

int verifica(int M[][MAX_TAM], int i, int j){
    
    int x = 0, y = 0;
    int count1 = 0, count2 = 0;
    
    //verifica coluna
    for(x=0; x<i; x++){
        if(M[x][j] == 1)
            count1++;
    }
    
    //verifica linha
    for(y=0; y<j; y++){
        if(M[i][y] == 1)
            count2++;
    }
    
    if(count1 == j && count2 == i)
        return 1;
    else 
        return 0;
    
}