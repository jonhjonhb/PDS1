#include <stdlib.h>
#include <stdio.h>

#define TAM_MAX 100


void imprimeMatriz(int matriz[][TAM_MAX], int m, int n)
{

	printf("\n");

	for (int j = 0; j<m; j++){
		for(int i = 0; i<n; i++)
			printf("%3d ", matriz[j][i]);
		printf("\n");
	}
}


void criamatriz(int matriz[][TAM_MAX], int m, int n, int k)
{

	for (int j = 0; j<m; j++){
		for(int i = 0; i<n; i++){
			do{
				matriz[j][i] = rand();
			}while (matriz[j][i] < 1 || matriz[j][i] > k);
		}
	}

	imprimeMatriz(matriz, m, n);
}

int conf_seq(int matriz[][TAM_MAX], int m, int n)
{
	int anterior=0, count=0;
	int M_linha[TAM_MAX][TAM_MAX];
	int M_coluna[TAM_MAX][TAM_MAX];

	
	for (int j = 0; j < m; j++)
	{
		count = 0;
		anterior = -1;
		for (int i = 0; i<n; i++)
		{
			M_linha[j][i] = matriz[j][i];
			if (i!=n-1)
			{
				if (M_linha[j][i] != anterior)
				{
					if (count >= 3)
						for (int x = count; x>0; x--)
							M_linha[j][i-x]= 0;
					count = 1;
				} 
				else 
					count++;
			}
			else
			{
				if (M_linha[j][i] != anterior)
				{
					if (count >= 3)
						for (int x = count; x>0; x--)
							M_linha[j][i-x]= 0;
					count = 1;
				}
				else if (count >= 2)
					for (int x = count; x>=0; x--)
						M_linha[j][i-x]= 0;
			}
			anterior = matriz[j][i];
		}
	}
	//imprimeMatriz(M_linha, m, n);
	
	//printf("Zerando colunas...\n");

	for (int j = 0; j < n; j++)
	{
		count = 0;
		anterior = -1;
		for (int i = 0; i<m; i++)
		{
			M_coluna[i][j] = matriz[i][j];
			if (i!=m-1)
			{
				if (M_coluna[i][j] != anterior)
				{
					if (count >= 3)
						for (int x = count; x>0; x--)
							M_coluna[i-x][j]= 0;
					count = 1;
				} 
				else 
					count++;
			}
			else
			{
				if (M_coluna[i][j] != anterior)
				{
					if (count >= 3)
						for (int x = count; x>0; x--)
							M_coluna[i-x][j]= 0;
					count = 1;
				}
				else if (count >= 2)
					for (int x = count; x>=0; x--)
						M_coluna[i-x][j]= 0;
			}
			anterior = matriz[i][j];
		}
	}
	//imprimeMatriz(M_coluna, m, n);

	//printf("Mesclando matrizes...\n");

	int countzero = 0;
	for (int j = 0; j<m; j++){
		for(int i = 0; i<n; i++)
		{	
			if(M_coluna[j][i] == 0  || M_linha[j][i] == 0 )
			{
				matriz[j][i] = 0;
				countzero++;
			}
		}
	}
	//printf("Procedimento realizado!\n");
	return countzero;
}

void arruma(int matriz[][TAM_MAX], int m, int n)
{
	int aux = 0 ;
	for (int j = 0; j<m; j++)
	{
		for(int i = 0; i<n; i++)
		{
			if(matriz[j][i] == 0)
			{
				for (int x = j-1; x >= 0; x--)
				{
					aux = matriz[x][i];
					if (aux == 0)
						break;
					else 
					{
						matriz[x][i] = matriz[x+1][i];
						matriz[x+1][i] = aux;
					}
				}
			}
		}
	}
	printf("\nMatriz translada\n");
	imprimeMatriz(matriz, m, n);
}

void zeraseq(int matriz[][TAM_MAX], int m, int n)
{
	int comp = 0 ;
	int x = 0;// = conf_seq(matriz, m, n);

	while (1){
	comp = x;
	x = conf_seq(matriz, m, n);
	if (comp==x)
		break;
	else
	printf("Zerando linhas...\n");
	imprimeMatriz(matriz, m, n);
	arruma(matriz, m, n);
	printf("\nNumero de zeros encontrados: %d\n", x);
	}
	printf("\nMatriz final\n");
	imprimeMatriz(matriz, m, n);
	printf("\nNumero de zeros encontrados: %d\n", x);
}
