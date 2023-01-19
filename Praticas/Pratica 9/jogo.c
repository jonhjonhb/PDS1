#include <stdio.h>
#include <stdlib.h>

typedef struct Guerreiro{
    int ataque, defesa, carisma, pontos_vida, id_guerreiro;
} Guerreiro;

int rolaDados()
{
    int d1=0, d2=0, d3=0;
    
    /*do
    {
        d1 = 1 +rand() % 6;
        d2 = 1 +rand() % 6;
        d3 = 1 +rand() % 6;
    } while (d1==0 || d2==0 || d3==0);
    */
    do{
        d1 = 1 +rand() % 6;
    } while (d1==0);
    
    do{
        d2 = 1 +rand() % 6;
    } while (d2==0);
    
    do{
        d3 = 1 +rand() % 6;
    } while (d3==0);
    
    return d1+d2+d3;
}

void criaGuerreiro(Guerreiro *g1)
{
    g1->ataque = rolaDados();
    g1->carisma = rolaDados();
    g1->defesa = rolaDados();
    int i = 0;
    g1->pontos_vida = rolaDados();
    for (i = 0; i<2; i++)
    {
        g1->pontos_vida += rolaDados();
    }
}

int bonusCarisma(int carisma)
{
    int bonus = 0;
    switch(carisma)
    {
        case 18:
        bonus = 3;
        break;
        case 16:
        bonus = 2;
        break;
        case 17:
        bonus = 2;
        break;
        case 14:
        bonus = 1;
        break;
        case 15:
        bonus = 1;
        break;
        case 6:
        bonus = -1;
        break;
        case 7:
        bonus = -1;
        break;
        case 4:
        bonus = -2;
        break;
        case 5:
        bonus = -2;
        break;
        case 3:
        bonus = -3;
        break;
        default:
        bonus = 0;
        break;
    }
    return bonus;
}

void ataca(Guerreiro *g1, Guerreiro *g2)
{
    int golpe = 0, escudo = 0, dano = 0;
    golpe = rolaDados();
    golpe += g1->ataque;
    golpe += bonusCarisma(g1->carisma);
       
    escudo = rolaDados();
    escudo += g2->defesa;
    escudo += bonusCarisma(g2->carisma);    
    
    dano = golpe - escudo;
    if (dano > 0)
    {
        if (dano > g2->pontos_vida)
        {
            do{
                dano--;
            }while (dano > g2->pontos_vida);
        }
    } /*else if (dano < 0)
        dano = 0;*/
    g2->pontos_vida -= dano;      
}

void jogo()
{
    Guerreiro a, b;
    a.id_guerreiro = 1;
    b.id_guerreiro = 2;
    criaGuerreiro(&a);
    criaGuerreiro(&b);
    while(a.pontos_vida>0 && b.pontos_vida>0)
    {
        ataca(&a, &b);
        if(b.pontos_vida==0)
        {
            printf("\nVencedor: %d", a.id_guerreiro);
            printf("\nPontos de vida restantes: %d", a.pontos_vida);
        }
        ataca(&b, &a);
        if(a.pontos_vida==0)
        {
            printf("\nVencedor: %d", b.id_guerreiro);
            printf("\nPontos de vida restantes: %d", b.pontos_vida);            
        }
    }
}