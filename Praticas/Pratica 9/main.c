#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

typedef struct Guerreiro{

	int ataque, defesa, carisma, pontos_vida, id_guerreiro;

} Guerreiro;

void main()
{
	/*Guerreiro a, b;
	a.id_guerreiro = 1;
	b.id_guerreiro = 2;
	criaGuerreiro(&a);
	criaGuerreiro(&b);
	printf("id: %d\n", a.id_guerreiro);
	printf("atk: %d\n", a.ataque);
	printf("def: %d\n", a.defesa);
	printf("csm: %d\n", a.carisma);
	printf("pts: %d\n", a.pontos_vida);

	printf("id: %d\n", b.id_guerreiro);
	printf("atk: %d\n", b.ataque);
	printf("def: %d\n", b.defesa);	
	printf("csm: %d\n", b.carisma);
	printf("pts: %d\n", b.pontos_vida);*/
	jogo();
}