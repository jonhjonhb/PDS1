#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TAM 1000

//1)
int contaLinhasArquivo(char nome_arquivo[]) {   
    
    FILE *arq = fopen(nome_arquivo, "r");
    // Caso o arquivo não abra
    if(!arq) {
		fprintf(stderr, "Erro na abertura do arquivo!\n");
		fclose(arq);
	}
    
    char str[MAX_TAM];
    int cont = 0;
    
    while (!feof(arq)){
        cont++;
        fgets(str, MAX_TAM, arq);
    }

    fclose(arq);
    return cont;
}

//2)
int contador_char(char *str) {

    if(*str == '\n')
        return 1;
    return 1 + contador_char(str+1);
}

char** carregaPoema(char nome_arquivo[]) {
    
    FILE *arq = fopen(nome_arquivo, "r");
    int tam = contaLinhasArquivo(nome_arquivo);
    char **str = (char**)malloc(tam*sizeof(char*));
    int i = 0, j = 0, cont_char = 0;

    // for(i=0; i<tam; i++)
    //     str[i] = (char*)malloc(MAX_TAM*sizeof(char));
    char string[MAX_TAM];
    int x=0, y=0;
    for (i = 0; i < tam -1; i++)
    {
        fgets(string, MAX_TAM, arq);
        cont_char = contador_char(string);
        str[i] = (char*)malloc(cont_char*sizeof(char));
        
        for(j = 0; j<cont_char; j++)
            str[i][j] = string[j];
         
        for(x = 0; x<cont_char; x++)
            printf("%c", str[i][x]);

    }
    str[tam-1] = NULL;

    fclose(arq);
    return str;
}

//3) 
void imprime_inv(char *str)
{
    if(*str == '\n'){
        printf("\n");
        return;
    }
    imprime_inv(str+1);
    printf("%c", *str);
}

void imprimePoemaInvertido(char **poema) {
    if(*poema == NULL)
        return;
    imprimePoemaInvertido(poema+1);
    imprime_inv(*poema);
}

//4)

int numeroTriangular(int n) {

    if(n == 1)
        return 1;
    return n + numeroTriangular(n-1);
}

//5)

float serieDois(int n) {
    if(n == 1)
        return 1;
    return 1.0/numeroTriangular(n) + serieDois(n-1);
}

// main auxiliar para testes:
// int minha_main() {

//     char poema[MAX_TAM] = "LOOOOOLALMDSLaSDKSALKJKL\nadsljakdlsjadjaklasd";

//     int contador = contaLinhasArquivo(poema);
//     printf("%d", contador);

// 	return 0;
// }

int main() {

    char poema[MAX_TAM] = "poema.txt";
    int contador = contaLinhasArquivo(poema);
    printf("Teste 1:\n");
    printf("%d\n", contador);


    printf("\nTeste 2:\n");
    char **str = NULL;
    str = carregaPoema(poema);

    printf("\n\nTeste 3:\n");
    imprimePoemaInvertido(str);

    printf("\n\nTeste 4:\n");
    int n = 0;
    for (int i = 0; i < 6; i++)
    {
        n++;
        printf("Numero triangular de %d: %d\n", n, numeroTriangular(n));
    }
    
    printf("\nTeste 5:\n");
    int x = 0;
    for (int i = 0; i < 6; i++)
    {
        x++;
        printf("Serie dois de %d: %.2f\n", x, serieDois(x));
    }

    return 0;
}