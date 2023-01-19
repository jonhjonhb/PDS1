#include <stdio.h>
#include <stdlib.h>

void zeraVetor(float *v, int n)
{
    int i = 0;
    for(i=0; i<n; i++)
        v[i] = 0;
}

void imprimeVetor(float *v, int n)
{
    int i = 0;
    for(i=0; i<n; i++)
        printf("%.1f ", v[i]);
}

void zeraMatriz(float *v, int n)
{
    int i = 0, j = 0;
    //for(j=0; j<n; i++)
    for(i=0; i<n; i++)
        v[i] = 0;
}

void imprimeMatriz(float *v, int n)
{
    int i = 0, j = 0;
    for(j=0; j<n; j++){
        for(i=0; i<n; i++){
            printf("%.1f ", v[i]);
        }
        printf("\n");
    }
}

void alocaMatriz(float ***v, int n)
{
    int i = 0;
    *v = (float**)malloc(n*sizeof(float*));
    for(i=0; i<n; i++)
//        *(*v+i) = (float*)malloc(n*sizeof(float));
        (*v)[i] = (float*)malloc(n*sizeof(float));

}

void main()
{
    int i =0, n=0;
    float **v = NULL;
    while(n<1){
       scanf("%d", &n);
    }
    //alocação dinâmica por função
    alocaMatriz(&v, n); 
    //alocação dinâmica por função
/*
    v = (float**)malloc(n*sizeof(float));
    
    for(i=0; i<n; i++)
        v[i] = (float*)malloc(n*sizeof(float));
*/

    zeraMatriz(*v, n);
    imprimeMatriz(*v, n);

    for(i=0; i<n; i++)
        free(v[i]);
    free(v);

}

/*Escreva um programa para ler um número inteiro n do 
teclado e criar dinamicamente uma matriz n x n de 
pontos flutuantes, atribuindo 0.0 a todas as suas 
posições. Uma matriz de pontos flutuantes de dimensões 
n x n é, na verdade, um vetor de n ponteiros para pontos
flutuantes em que cada ponteiro deste vetor aponta para
um vetor de n pontos flutuantes. Assim, para resolver 
esse exercício, primeiro aloque dinamicamente um vetor 
de n posições de ponteiros para pontos flutuantes. 
Depois, para cada posição i deste vetor, aloque um vetor
de tamanho n de pontos flutuantes e atribua 0.0 a cada 
uma das suas posições. Por fim, imprima a matriz.*/