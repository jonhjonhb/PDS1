#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SEMENTE_RAND() srand(time(NULL));

int funcsomaCubo(int n)
{
    if(n<=1)
        return 1;
    return pow(n,3) + funcsomaCubo(n-1);
}

void somaCubo()
{
    //int n = 0;
    //scanf(" %d", &n);
    printf("\n");
    printf("Teste 1:\n");
    printf("Soma Cubo: %d\n", funcsomaCubo(5));
}

void ordem(int n)
{
    if(n<0)
        return;
    ordem(n-1);
    printf("%d ", n);
}

void natural()
{
    //int n = 0;
    //scanf(" %d", &n);
    printf("\n");
    printf("Teste 2:\n");
    ordem(5);
}

void ordemDec(int n)
{
    if(n<0)
        return;
    printf("%d ", n);
    ordemDec(n-1);
}

void decrescente()
{
    //int n = 0;
    printf("\n");
    //scanf(" %d", &n);
    ordemDec(5);
}

void aloca(int **v, int n)
{
    *v = (int*)malloc(n*sizeof(int));
}

void populaVetor(int *v, int n)
{
    SEMENTE_RAND()
    for(int i = 0; i<n; i++)
        v[i] = 1 + rand()%10;
    printf("\nVetor:\n");
    for(int i = 0; i<n; i++)
        printf("%d ", v[i]);
}

int somaVetor(int *v, int n)
{
    int soma = 0;
    if(n==1)
        return v[0];
    return v[n-1] + somaVetor(v, n-1);
}

float mediaVetor(int *v, int n)
{
    int soma = 0;
    if(n==1)
        return v[0];
    return (v[n-1] + somaVetor(v, n-1))/(float)n;
}

void vetor()
{
    int n = 3, *v = NULL;
    printf("\n", n);
    //scanf(" %d", &n);
    aloca(&v, n);
    populaVetor(v, n);
    printf("\nSoma do Vetor: %d\n", somaVetor(v,n));
    printf("Media do Vetor: %lf\n", mediaVetor(v,n));
    free(v);
}

int elevado(int x, int y)
{
    if(y==1)
        return x;
    return x*elevado(x, y-1);
}

void excseis()
{
    printf("2^3: %d", elevado(2,3));
}

void invertestr(char *str, int n)
{
    if(n == 0)
        return;
    printf("\n[%d]: %c", n-1, str[n-1]);
    invertestr(str, n-1);
}

void excsete()
{
    char str[10] = "Johnatan10";
    invertestr(str, 10); 
}

unsigned int numinv(unsigned int x, unsigned int *soma)
{
    int resto = 0;
    if(x == 0)
        return *soma;
    else
    {
        resto = x%10;
        *soma *= 10;
        *soma += resto;
        numinv(x/10, soma);
        return *soma;
    }
}

void exc8()
{
    SEMENTE_RAND()
    unsigned int n = 0, soma = 0;
    printf("\n\n");
    printf("Teste 8:\n");
    n = 99 + rand()%999; 
    soma = 0;
    printf("%ld invertido: %ld\n", n, numinv(n, &soma));
    n = 99 + rand()%999;
    soma = 0;
    printf("%ld invertido: %ld\n", n, numinv(n, &soma));
    n = 99 + rand()%999;
    soma = 0;
    printf("%ld invertido: %ld\n", n, numinv(n, &soma));
}

void basebin(unsigned int n)
{
    if(n==0)
        return;
    basebin(n/2);
    printf("%d", n%2);
}

void exc9()
{
    SEMENTE_RAND()
    unsigned int n = 0;
    printf("\n");
    printf("Teste 9:\n");
    n = 1 + rand()%99;
    printf("Base decimal %ld invertido: ", n);
    basebin(n);
    n = 1 + rand()%99;
    printf("\nBase decimal %ld invertido: ", n);
    basebin(n);
    n = 1 + rand()%99;
    printf("\nBase decimal %ld invertido: ", n);
    basebin(n);
    printf("\n");
}

int menor_elemento(int *v, int n)
{
    int atual = v[n-1], menor = 0;
    if(n-1 == 0)
        return v[n-1];
    else
    {
        menor = menor_elemento(v, n-1);
        if(menor<=atual)
            return menor;
        else
            return atual;
    }
}

void exc10()
{
    SEMENTE_RAND()
    int n = 0, *v;
    printf("\n");
    printf("Teste 10:\n");
    n = 1 + rand()%9;
    aloca(&v, n);
    populaVetor(v, n);
    printf("\nMenor elemento: %d", menor_elemento(v, n));
    free(v);
    n = 1 + rand()%9;
    aloca(&v, n);
    populaVetor(v, n);
    printf("\nMenor elemento: %d", menor_elemento(v, n));
    free(v);    
    n = 1 + rand()%9;
    aloca(&v, n);
    populaVetor(v, n);
    printf("\nMenor elemento: %d", menor_elemento(v, n));
    free(v);
    printf("\n");
}