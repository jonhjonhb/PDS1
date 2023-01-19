#include <stdio.h>

void ordena(int M[])
{
	int i=0, j=0;
	int ORD[6], aux[6];

	for(j=0; j<6; j++){
		aux[j]=0;
		for(i=0; i<6; i++){
			if(M[i]<M[j])
				aux[j]++;
		}
		ORD[aux[j]] = M[j];
	}

	i=0;
	for(i=0; i<6; i++)
		M[i]=ORD[i]; 
}

void imprime(int M[])
{
	int i=0;
	for(i=0; i<6; i++){
		printf("%d ", M[i]);
	}
}

int verifica(int sorteio[], int M[])
{
	int i=0, count = 0;
	for(i=0; i<6; i++)
		if(sorteio[i]!=M[i])
			count++;

	if(count==0)
		return 1;
	else
		return 0;
}

void pegajogo(FILE *arq, int cartela[])
{
	int i=0;
	for(i=0; i<6; i++){
		fscanf(arq, "%d", &cartela[i]);
	}
}

void main ()
{
	FILE *arq;
	arq = fopen("cartelas.txt", "r");

	int cartela[6], sorteio[6], serielost[6];
	int i=0, j=0, vencedores=0, lost=0;

	serielost[0]=4;
	serielost[1]=8;
	serielost[2]=15;
	serielost[3]=16;
	serielost[4]=23;
	serielost[5]=42;

	sorteio[0]=6;
	sorteio[1]=9;
	sorteio[2]=22;
	sorteio[3]=23;
	sorteio[4]=48;
	sorteio[5]=52;

	
	while(feof(arq)==0){
		pegajogo(arq, cartela);
		ordena(cartela);
		if(verifica(sorteio, cartela))
			vencedores++;
		else if(verifica(serielost, cartela))
			lost++;
	}

	printf("\nQuantidade de vencedores: %d\n", vencedores);
	printf("\nQuantidade de lost: %d\n", lost);
	fclose(arq);
}