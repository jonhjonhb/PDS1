#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimePilhas (int p1, int p2, int p3){
	char pipe[100] = "|";
	char px1[100] = "\0";
	char px2[100] = "\0";
	char px3[100] = "\0";
	int i = 1;
		while(i<=p1){
			strcat(px1,pipe);
			i++;
		} printf("\n%d %s\n", p1, px1);
		i=1;
		while(i<=p2){
			strcat(px2,pipe);
			i++;
		} printf("\n%d %s\n", p2, px2);
		i=1;
		while(i<=p3){
			strcat(px3,pipe);
			i++;
		} printf("\n%d %s\n", p3, px3);
}

void imprimePilhas2 (int p1, int p2, int p3){
    int under = 95;
    int px1 = p1, px2 = p2, px3 = p3;
    printf("\n");

	while (px1!=px2 && px1!=px3 && px2!=px3){
		if (px1>px2 && px1>px3){
			while (px1!=px2 && px1!=px3){
			printf("%c\n", under);
			px1--;	
			}
		} else if (px2>px1 && px2>px3){
			while (px2!=px1 && px2!=px3){
			printf("  %c\n", under);
			px2--;	
			}
		} else {
			while (px3!=px1 && px3!=px2){
			printf("    %c\n", under);
			px3--;	
			}
		}
	}
  
    while (1){
        if (px1==px3 && px1>px2){
            while (px1==px3 && px1>px2){
                printf("%c   %c\n", under, under);
                px1--;
                px3--;
            }
        } else if (px1==px2 && px1>px3){
            while (px1==px2 && px1>px3){
                printf("%c %c  \n", under, under);
                px1--;
                px2--;
            }
        } else {
            while (px2==px3 && px2>px1){
                printf("  %c %c\n", under, under);
                px2--;
                px3--;
            }
        } break;
    }

    while (px1==px2 && px2==px3 && px1==px3 && px1>0){
        printf("%c %c %c\n", under, under, under);
        px1--;
        px2--;
        px3--;
    } printf("%d %d %d\n", p1, p2, p3);
}

void leJogada (int *end_p, int *end_q){
	printf("\nEscolha uma pilha (1, 2 ou 3):\n");
	scanf("%d", end_p);
	printf("Quantos palitos gostaria de remover?\n");
	scanf("%d", end_q);

}

int diminuiPilha(int *end_p, int q){
	if (q>0 && q<=*end_p){
		*end_p -= q;
		return 1;
	}
	return 0;
}

int confereJogo(int p1, int p2, int p3){
	if (p1+p2+p3>0)
		return 1;
	else 
		return 0;
}

int jogo(int p1, int p2, int p3){
	int i=1;
	int end_p, end_q;

	do{	
		imprimePilhas2(p1, p2, p3);
		printf("\nN: %d\n", i%2!=0 ? 1 : 2);
		leJogada(&end_p, &end_q);
		i++;
			if (!diminuiPilha(&end_p, end_q) == 0){
                printf("\nErro! Jogue novamente!\n");
			    i--;
			} else if (end_p == 1) {
                diminuiPilha(&p1, end_q);
            } else if (end_p == 2) {
                diminuiPilha(&p2, end_q);
            } else if (end_p == 3) {
                diminuiPilha(&p3, end_q);
            }
            
	} while (confereJogo(p1,p2,p3));
	return (i % 2 != 0) ? 1 : 2;
}

int principal(){
	int p1, p2, p3;
	do {
		printf("\nVamos brincar!\n");
		printf("Digite o valor da pilha 1:\n");
		scanf("%d", &p1);
		printf("Digite o valor da pilha 2:\n");
		scanf("%d", &p2);
		printf("Digite o valor da pilha 3:\n");
		scanf("%d", &p3);
		imprimePilhas2(p1,p2,p3);
	} while (p1<=0 || p2<=0 || p3<=0);

}


void main(){
	// principal();
	jogo(3,2,1);

}