#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

const float FPS = 100;

//Tela
const int SCREEN_W = 960;
const int SCREEN_H = 540;

const float THETA = M_PI/4;
const float RAIO_CAMPO_FORCA = 25;
const float RAIO_PROJETIL = 3;
const float VEL_TANQUE = 1.5;
const float VEL_PROJETIL = 10;
const float PASSO_ANGULO = M_PI/90;

// Estruturas usadas no jogo
typedef struct Ponto {
	float x, y;
} Ponto;

typedef struct Circulo {
	Ponto centro;
	float raio;
} Circulo;

typedef struct Projetil {
	Circulo circulo;
	float vel;
	float angulo;
	float x_comp, y_comp;
} Projetil;

typedef struct Tanque {

	Circulo circulo;
	Ponto A, B, C;
	ALLEGRO_COLOR cor;

	float vel;
	float angulo;
	float x_comp, y_comp;
	float vel_angular;
	int score;

	Projetil bala;

} Tanque;

typedef struct Bloco {
	Ponto sup_esq;
	Ponto inf_dir;
	ALLEGRO_BITMAP *obstaculo;
} Bloco ;

// cria bloco principal
Bloco b1, b2, b3, b4, b5;
int Cenario;

// Funcoes implementadas

void inicializacao_tanque1(Tanque *t);
void inicializacao_tanque2(Tanque *t);
void inicializa_cenario();
void inicializa_projetil(Tanque *t);
void atribui_Image();
void drawcenario();
void desenhaCenario();
void desenhaProjetil(Tanque t);
void desenhaTanque (Tanque t);
void desenhaBloco(Bloco b);
void atualizaProjetil(Tanque *t);
void atualizaTanque(Tanque *t, Tanque p);
Tanque movimento_tanque(Tanque t);
void rotate(Ponto *P, float angulo);
void rotacionaTanque(Tanque *t);
int limite_tela(float x, float y, float velocidade, float anguloX, float anguloY, char C);
int limite_tela_tanque(Tanque t);
int limite_tela_bala(Projetil t);
float distPonto(Ponto p1, Ponto p2);
int colisao_Circulos(Circulo circulo1, Circulo circulo2);
int colisaoplayer(Tanque t, Tanque p);
int colisao_cenario(Circulo cir);
int colisao_BlocoCirculo(Circulo cir, Bloco ret);
int colisao_cenarioPlayer(Tanque t);
int colisao_PlayerBloco(Tanque t, Bloco ret);
int verificacolisaoTiro(Ponto t, Tanque p);
void atirar(Tanque *t);
void atiraProjetil(Tanque *t, Tanque p);
void historico_winner(int *v1, int *v2);
void Fim_da_partida(Tanque t, Tanque p);
int jogo();

int main(int argc, char **argv){

	jogo();
	return 0;
}

// Funcoes implementadas

void inicializacao_tanque1(Tanque *t)
{
	t->circulo.centro.x = SCREEN_W/6;
	t->circulo.centro.y = SCREEN_H/2;
	t->circulo.raio = RAIO_CAMPO_FORCA;
	t->cor = al_map_rgb(rand()%256, rand()%256, rand()%256);

	t->A.x = 0;
	t->A.y = -RAIO_CAMPO_FORCA;
	
	float alpha = M_PI/2 - THETA;
	float h = RAIO_CAMPO_FORCA * sin(alpha);
	float w = RAIO_CAMPO_FORCA * sin(THETA);

	t->B.x = -w;
	t->B.y = h;

	t->C.x = w;
	t->C.y = h;

	t->vel = 0;

	t->angulo= M_PI/2;
	t->x_comp = cos(t->angulo);
	t->y_comp = sin(t->angulo);

	t->vel_angular = 0;

	//Projétil
	t->bala.vel = 0;
	inicializa_projetil(t);
	t->bala.circulo.raio = RAIO_PROJETIL;

	t->score = 0;
}

void inicializacao_tanque2(Tanque *t)
{

	t->circulo.centro.x = SCREEN_W - SCREEN_W/6;
	t->circulo.centro.y = SCREEN_H/2;
	t->circulo.raio = RAIO_CAMPO_FORCA;
	t->cor = al_map_rgb(rand()%256, rand()%256, rand()%256);

	t->A.x = 0;
	t->A.y = -RAIO_CAMPO_FORCA;
	
	float alpha = M_PI/2 - THETA;
	float h = RAIO_CAMPO_FORCA * sin(alpha);
	float w = RAIO_CAMPO_FORCA * sin(THETA);

	t->B.x = -w;
	t->B.y = h;

	t->C.x = w;
	t->C.y = h;

	t->vel = 0;

	t->angulo= M_PI/2;
	t->x_comp = cos(t->angulo);
	t->y_comp = sin(t->angulo);

	t->vel_angular = 0;

	//Projétil
	t->bala.vel = 0;
	inicializa_projetil(t);
	t->bala.circulo.raio = RAIO_PROJETIL;
	
	t->score = 0;
}

void atribui_Image()
{
	switch (Cenario)
	{
		case 1:
		b1.obstaculo = al_load_bitmap("cenario1.png");
		break;
		case 2:
		b1.obstaculo = al_load_bitmap("cenario2.png");
		break;
		case 3:
		b1.obstaculo = al_load_bitmap("cenario3.png");
		b5.obstaculo = al_load_bitmap("cenario3centro.png");
		break;
	}
}

void inicializa_cenario()
{
	switch (Cenario)
	{
		case 1:
		b1.sup_esq.x = SCREEN_W/10*4;
		b1.sup_esq.y = SCREEN_H/6*2.2;
		b1.inf_dir.x = SCREEN_W/10*6;
		b1.inf_dir.y = SCREEN_H/6*4;
		atribui_Image();
		break;
		case 2:
		b1.sup_esq.x = SCREEN_W/10*2;
		b1.sup_esq.y = SCREEN_H/6*2.2;
		b1.inf_dir.x = SCREEN_W/10*2.5;
		b1.inf_dir.y = SCREEN_H/6*4;
		b2.sup_esq.x = SCREEN_W - (SCREEN_W/10*2.5);
		b2.sup_esq.y = SCREEN_H/6*2.2;
		b2.inf_dir.x = SCREEN_W - (SCREEN_W/10*2);
		b2.inf_dir.y = SCREEN_H/6*4;
		atribui_Image();
		break;
		case 3:
		b1.sup_esq.x = SCREEN_W/10*1.5;
		b1.sup_esq.y = SCREEN_H/6*1.5+20;
		b1.inf_dir.x = SCREEN_W/10*3;
		b1.inf_dir.y = SCREEN_H/6*2+20;
		b2.sup_esq.x = b1.sup_esq.x;
		b2.sup_esq.y = SCREEN_H - b1.inf_dir.y+30;
		b2.inf_dir.x = b1.inf_dir.x;
		b2.inf_dir.y = SCREEN_H - b1.sup_esq.y+30;
		b3.sup_esq.x = SCREEN_W - b1.inf_dir.x;
		b3.sup_esq.y = b1.sup_esq.y;
		b3.inf_dir.x = SCREEN_W - b1.sup_esq.x;
		b3.inf_dir.y = b1.inf_dir.y;
		b4.sup_esq.x = SCREEN_W - b2.inf_dir.x;
		b4.sup_esq.y = b2.sup_esq.y;
		b4.inf_dir.x = SCREEN_W - b2.sup_esq.x;
		b4.inf_dir.y = b2.inf_dir.y;
		b5.sup_esq.x = SCREEN_W/10*4.5;
		b5.sup_esq.y = SCREEN_H/6*2.2;
		b5.inf_dir.x = SCREEN_W/10*5.5;
		b5.inf_dir.y = SCREEN_H/6*4;
		atribui_Image();
		break;
	}
}

void drawcenario()
{
	switch (Cenario)
	{
		case 1:
		al_draw_bitmap(b1.obstaculo, b1.sup_esq.x, b1.sup_esq.y, 0);
		break;
		case 2:
		al_draw_bitmap(b1.obstaculo, b1.sup_esq.x, b1.sup_esq.y, 0);
		al_draw_bitmap(b1.obstaculo, b2.sup_esq.x, b2.sup_esq.y, 0);
		break;
		case 3:
		al_draw_bitmap(b1.obstaculo, b1.sup_esq.x, b1.sup_esq.y, 0);
		al_draw_bitmap(b1.obstaculo, b2.sup_esq.x, b2.sup_esq.y, 0);
		al_draw_bitmap(b1.obstaculo, b3.sup_esq.x, b3.sup_esq.y, 0);
		al_draw_bitmap(b1.obstaculo, b4.sup_esq.x, b4.sup_esq.y, 0);
		al_draw_bitmap(b5.obstaculo, b5.sup_esq.x, b5.sup_esq.y, 0);
		break;
	}
}

void desenhaCenario()
{
	//contorno do cenario
	al_draw_rectangle(5, 45, SCREEN_W-5, SCREEN_H-5, al_map_rgb(0,0,0), 10);
	//Escolhe mapa
	drawcenario();
}

void inicializa_projetil(Tanque *t)
{
	//Inicializa o Projetil no centro do Tanque
	t->bala.circulo.centro.x = t->circulo.centro.x;
	t->bala.circulo.centro.y = t->circulo.centro.y;
}

void atualizaProjetil(Tanque *t)
{
	t->bala.circulo.centro.x -= t->bala.vel*t->bala.x_comp;
	t->bala.circulo.centro.y -= t->bala.vel*t->bala.y_comp;
}

void desenhaProjetil(Tanque t)
{	
	al_draw_filled_circle(t.bala.circulo.centro.x, t.bala.circulo.centro.y, 
						  t.bala.circulo.raio, al_map_rgb(0, 0, 0));
}

void desenhaTanque (Tanque t)
{
	al_draw_circle(t.circulo.centro.x, t.circulo.centro.y, t.circulo.raio, t.cor, 1);
	al_draw_filled_triangle(t.A.x + t.circulo.centro.x, t.A.y + t.circulo.centro.y, 
							t.B.x + t.circulo.centro.x, t.B.y + t.circulo.centro.y, 
							t.C.x + t.circulo.centro.x, t.C.y + t.circulo.centro.y, t.cor);
}

void desenhaBloco(Bloco b)
{
	al_draw_filled_rectangle(b.sup_esq.x, b.sup_esq.y, 
		b.inf_dir.x, b.inf_dir.y, al_map_rgb(0, 0, 0));
}

void rotate(Ponto *P, float angulo)
{
	float x = P->x, y = P->y;

	P->x = (x*cos(angulo))-(y*(angulo));
	P->y = (y*cos(angulo))+(x*(angulo));
}

void rotacionaTanque(Tanque *t)
{
	if (t->vel_angular != 0){

		rotate(&t->A, t->vel_angular);
		rotate(&t->B, t->vel_angular);
		rotate(&t->C, t->vel_angular);
		t->angulo += t->vel_angular;
		t->x_comp = cos(t->angulo);
		t->y_comp = sin(t->angulo);
	
	}
}

int limite_tela(float x, float y, float velocidade, float anguloX, float anguloY, char C)
{
	//Se os dados enviados foram do Tanque
	if(C == 'T'){
		if(x + RAIO_CAMPO_FORCA + velocidade*anguloX < SCREEN_W-10 && 
			x - RAIO_CAMPO_FORCA + velocidade*anguloX > 10 && 
			y + RAIO_CAMPO_FORCA + velocidade*anguloY < SCREEN_H-10 && 
			y - RAIO_CAMPO_FORCA + velocidade*anguloY > 50)
			return 1;
		else 
			return 0;
	} 
	//Se os dados enviados foram do Projétil
	else if (C == 'P'){
		if(x + RAIO_PROJETIL + velocidade*anguloX < SCREEN_W-10 && 
			x - RAIO_PROJETIL + velocidade*anguloX > 10 && 
			y + RAIO_PROJETIL + velocidade*anguloY < SCREEN_H-10 && 
			y - RAIO_PROJETIL + velocidade*anguloY > 50)
			return 1;
		else 
			return 0;
	}
}

int limite_tela_tanque(Tanque t)
{
	if(limite_tela(t.circulo.centro.x, t.circulo.centro.y, t.vel, t.x_comp, t.y_comp, 'T'))
		return 1;
	else 
		return 0;
}

int limite_tela_bala(Projetil t)
{
	if(limite_tela(t.circulo.centro.x, t.circulo.centro.y, t.vel, t.x_comp, t.y_comp, 'P'))
		return 1;
	else 
		return 0;
}

void atualizaTanque(Tanque *t, Tanque p)
{
	rotacionaTanque(t);

	if(limite_tela_tanque(*t)){
		if(!colisao_cenarioPlayer(*t) && !colisaoplayer(*t,p)){
			t->circulo.centro.x += t->vel*t->x_comp;
			t->circulo.centro.y += t->vel*t->y_comp;
		}
		
		if(t->bala.vel == 0)
			inicializa_projetil(t);
	}

	desenhaTanque(*t);
	atiraProjetil(t, p);
}

float distPonto(Ponto p1, Ponto p2)
{
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
} 

int colisaoplayer(Tanque t, Tanque p)
{
	if(distPonto(movimento_tanque(t).circulo.centro, p.circulo.centro)<=t.circulo.raio+p.circulo.raio)
		return 1;
	else
		return 0;
}

int verificacolisaoTiro(Ponto t, Tanque p)
{	
	if(distPonto(t, p.circulo.centro)<=RAIO_CAMPO_FORCA+RAIO_PROJETIL)
		return 1;
	else
		return 0;
}

void atirar(Tanque *t)
{
	//Somente se a bala foi "destruida" no ultimo tiro que podemos atirar novamente
	if(t->bala.circulo.centro.x == t->circulo.centro.x && 
	   t->bala.circulo.centro.y == t->circulo.centro.y)
	{
		inicializa_projetil(t);
		t->bala.angulo = t->angulo;
		t->bala.x_comp = t->x_comp;
		t->bala.y_comp = t->y_comp;
		t->bala.vel = VEL_PROJETIL;
	}
}

void atiraProjetil(Tanque *t, Tanque p)
{

	if(t->bala.vel != 0){
		if(!verificacolisaoTiro(t->bala.circulo.centro, p) && 
		    limite_tela_bala(t->bala) && 
			!colisao_cenario(t->bala.circulo))
		{
			desenhaProjetil(*t);
			atualizaProjetil(t);
		} else {
			t->bala.vel = 0;
			inicializa_projetil(t);
		}

		if(colisao_Circulos(t->bala.circulo, p.circulo))
			t->score++;
	}
}

int colisao_Circulos(Circulo circulo1, Circulo circulo2)
{
	// Verifica colisao entre circulos
	if(distPonto(circulo1.centro, circulo2.centro)<=circulo1.raio+circulo2.raio)
		return 1;
	else
		return 0;
}

int colisao_cenario(Circulo cir)
{
	switch (Cenario)
	{
	case 1:
		if(colisao_BlocoCirculo(cir, b1))
			return 1;
		break;
	case 2:
		if(colisao_BlocoCirculo(cir, b1) || 
		   colisao_BlocoCirculo(cir, b2))
			return 1;
		break;
	case 3:
		if(colisao_BlocoCirculo(cir, b1) ||
		   colisao_BlocoCirculo(cir, b2) ||
		   colisao_BlocoCirculo(cir, b3) ||
		   colisao_BlocoCirculo(cir, b4) ||
		   colisao_BlocoCirculo(cir, b5))
			return 1;
		break;
	}
	return 0;
}

int colisao_BlocoCirculo(Circulo cir, Bloco ret)
{
	// Cria pontos suplementares para a verificacao de colisao nos vertices
	Ponto inf_esq, sup_dir;
	inf_esq.x = ret.sup_esq.x;
	inf_esq.y = ret.inf_dir.y;
	sup_dir.x = ret.inf_dir.x;
	sup_dir.y = ret.sup_esq.y;

	//Se o circulo está com o x dentro da região do bloco [sup_esq.x, inf_dir.x]
	if(cir.centro.x >= ret.sup_esq.x &&
	   cir.centro.x <= ret.inf_dir.x) {
		//Se o circulo está com o y+raio dentro da região do bloco [sup_esq.y, inf_dir.y]
		if(cir.centro.y + cir.raio >= ret.sup_esq.y &&
		   cir.centro.y - cir.raio <= ret.inf_dir.y) {
			return 1;
		}
	}
	//Se o circulo está com o y dentro da região do bloco [sup_esq.y, inf_dir.y]
	if(cir.centro.y >= ret.sup_esq.y && 
	   cir.centro.y <= ret.inf_dir.y) {
		//Se o circulo está com o y+raio dentro da região do bloco [sup_esq.x, inf_dir.x]
		if (cir.centro.x + cir.raio >= ret.sup_esq.x &&
			cir.centro.x - cir.raio <= ret.inf_dir.x){
			return 1;
		}
	}	 
	//Se o circulo está colidindo com os vertices
	if(distPonto(cir.centro, ret.inf_dir) <= cir.raio || 
	   distPonto(cir.centro, ret.sup_esq) <= cir.raio ||
	   distPonto(cir.centro, sup_dir) <= cir.raio ||
	   distPonto(cir.centro, inf_esq) <= cir.raio){
		return 1;
	}
	
	return 0;
}

int colisao_cenarioPlayer(Tanque t)
{
	switch (Cenario)
	{
		case 1:
			if(colisao_PlayerBloco(t, b1))
				return 1;
			break;
		case 2:
			if(colisao_PlayerBloco(t, b1) || 
			   colisao_PlayerBloco(t, b2))
				return 1;
			break;
		case 3:
			if(colisao_PlayerBloco(t, b1) || 
			   colisao_PlayerBloco(t, b2) || 
			   colisao_PlayerBloco(t, b3) || 
			   colisao_PlayerBloco(t, b4) || 
			   colisao_PlayerBloco(t, b5))
				return 1;
			break;
	}
	return 0;
}

int colisao_PlayerBloco(Tanque t, Bloco ret)
{
	Ponto inf_esq, sup_dir;
	inf_esq.x = ret.sup_esq.x;
	inf_esq.y = ret.inf_dir.y;
	sup_dir.x = ret.inf_dir.x;
	sup_dir.y = ret.sup_esq.y;

	//Regiao Superior e Inferior
	if(t.circulo.centro.x + (t.vel*t.x_comp) >= ret.sup_esq.x &&
	   t.circulo.centro.x + (t.vel*t.x_comp) <= ret.inf_dir.x)
		if (t.circulo.centro.y + t.circulo.raio + (t.vel*t.y_comp) >= ret.sup_esq.y &&
		    t.circulo.centro.y - t.circulo.raio + (t.vel*t.y_comp) <= ret.inf_dir.y)
			return 1;
	//Regiao da Esquerda e Direita
	if(t.circulo.centro.y + (t.vel*t.y_comp) >= ret.sup_esq.y && 
	   t.circulo.centro.y + (t.vel*t.y_comp) <= ret.inf_dir.y)
		if (t.circulo.centro.x + t.circulo.raio + (t.vel*t.x_comp) >= ret.sup_esq.x &&
			t.circulo.centro.x - t.circulo.raio + (t.vel*t.x_comp) <= ret.inf_dir.x)
			return 1;
	//Regiao dos Vertices
	if(distPonto(movimento_tanque(t).circulo.centro, ret.inf_dir) <= t.circulo.raio || 
	   distPonto(movimento_tanque(t).circulo.centro, ret.sup_esq) <= t.circulo.raio ||
	   distPonto(movimento_tanque(t).circulo.centro, sup_dir) <= t.circulo.raio ||
	   distPonto(movimento_tanque(t).circulo.centro, inf_esq) <= t.circulo.raio){
		return 1;
	}

	return 0;	
}

Tanque movimento_tanque(Tanque t)
{
	t.circulo.centro.x += t.vel*t.x_comp;
	t.circulo.centro.y += t.vel*t.y_comp;

	return t;
}

void historico_winner(int *v1, int *v2)
{

	FILE *arq = fopen("historico.text","r");
	char str[4], *token;

	fgets(str, 4, arq);

	token = strtok(str, " ");
	*v1 = atoi(token);
	token = strtok(NULL, " ");
	*v2 = atoi(token);

	fclose(arq);
}

void Fim_da_partida(Tanque t, Tanque p)
{	
	ALLEGRO_FONT *size_32 = al_load_font("arial.ttf", 32, 1);   
	if(size_32 == NULL) {
		fprintf(stderr, "font file does not exist or cannot be accessed!\n");
	}

	int vitorias1 = 0, vitorias2 = 0;
	historico_winner(&vitorias1, &vitorias2);
	FILE *arq = fopen("historico.text","w");

	//Jogo termina se jogador acerta 5 tiros
	if(t.score > p.score)
		vitorias1++;
	else if(p.score > t.score)
		vitorias2++;

	fprintf(arq, "%d %d", vitorias1, vitorias2);

	// colore toda a tela de branco
	al_clear_to_color(al_map_rgb(255,255,255));
	// Pontuação do jogo atual
	al_draw_textf(size_32, al_map_rgb(0,0,0), SCREEN_W/2, SCREEN_H/2-32,
				  ALLEGRO_ALIGN_CENTRE, "SCORE: %d x %d", t.score, p.score);
	// Historico das partidas
	al_draw_textf(size_32, al_map_rgb(0,0,0), SCREEN_W/2, SCREEN_H/2+40,
				  ALLEGRO_ALIGN_CENTRE, "Player 1: %d", vitorias1);
	al_draw_textf(size_32, al_map_rgb(0,0,0), SCREEN_W/2, SCREEN_H/2+72,
				  ALLEGRO_ALIGN_CENTRE, "Player 2: %d", vitorias2);

	// reinicializa a tela
	al_flip_display();
	// Mostra a nova tela por 1.5 segundos
	al_rest(1.5);
	fclose(arq);
}

int inicializa_allegro()
{

	//----------------------- rotinas de inicializacao ---------------------------------------

	//inicializa o módulo de primitivas do Allegro
    if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }

	//inicializa o modulo que permite carregar imagens no jogo
	if(!al_init_image_addon()){
		fprintf(stderr, "failed to initialize image module!\n");
		return -1;
	}

	//inicializa o modulo allegro que carrega as fontes
	al_init_font_addon();

	//inicializa o modulo allegro que entende arquivos tff de fontes
	if(!al_init_ttf_addon()) {
		fprintf(stderr, "failed to load tff font module!\n");
		return -1;
	}

	//instala o teclado
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return -1;
	}
	
	//instala o audio
	if(!al_install_audio()) {
		fprintf(stderr, "failed to install audio!\n");
		return -1;
	}

	// inicializa o modulo allegro que carrega os audios
	al_init_acodec_addon();
	al_reserve_samples(1);
	
	return 0;
}

void destroy()
{
	al_destroy_bitmap(b1.obstaculo);
	al_destroy_bitmap(b5.obstaculo);
}

int jogo()
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *fundo = NULL;
	ALLEGRO_SAMPLE *trilha_sonora = NULL;

	//----------------------- rotinas de inicializacao ---------------------------------------
    
	//inicializa o Allegro
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

   
	//cria um temporizador que incrementa uma unidade a cada 1.0/FPS segundos
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
 
	//cria uma tela com dimensoes de SCREEN_W, SCREEN_H pixels
	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	inicializa_allegro();
	
	//carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
    ALLEGRO_FONT *size_32 = al_load_font("arial.ttf", 32, 1);   
	if(size_32 == NULL) {
		fprintf(stderr, "font file does not exist or cannot be accessed!\n");
	}

 	//cria a fila de eventos
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}

	//carrega a imagem louco.jpg e a atribui aa variavel image
	fundo = al_load_bitmap("fundo.png");
	if(!fundo){
		fprintf(stderr, "failed to create bitmap!\n");
		al_destroy_bitmap(fundo);
		return -1;
	}

	//carrega a trilha sonora
	trilha_sonora = al_load_sample("trilhasonora.ogg");
	if(!trilha_sonora){
		fprintf(stderr, "failed to create sample!\n");
		al_destroy_sample(trilha_sonora);
		return -1;
	}


	//registra na fila os eventos de tela (ex: clicar no X na janela)
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila os eventos de tempo: quando o tempo altera de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra na fila os eventos de teclado (ex: pressionar uma tecla)
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//cria o tanque
	Tanque tanque_1;
	inicializacao_tanque1(&tanque_1);

	Tanque tanque_2;
	inicializacao_tanque2(&tanque_2);

	
	//inicia o temporizador
	al_start_timer(timer);
	

	//Toca trilha sonora
	al_play_sample(trilha_sonora, 1.0, ALLEGRO_AUDIO_PAN_NONE, 
				   1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//Decisão do cenario
	srand(time(NULL));
	Cenario = 1 + rand()%3;
	//Cria cenario
	inicializa_cenario();

	int playing = 1;

	while(playing) {
		ALLEGRO_EVENT ev;
		//espera por um evento e o armazena na variavel de evento ev			
		al_wait_for_event(event_queue, &ev);

		//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		if(ev.type == ALLEGRO_EVENT_TIMER) {

			al_clear_to_color(al_map_rgb(255,255,255));
			//coloca na tela a imagem armazenada na variavel fundo nas posicoes x=0, y=0
			al_draw_bitmap(fundo, 0, 0, 0);
			desenhaCenario();

			atualizaTanque(&tanque_1, tanque_2);
			atualizaTanque(&tanque_2, tanque_1);

			// Placar do jogador 1
			al_draw_textf(size_32, tanque_1.cor, SCREEN_W/4, 6, 
				ALLEGRO_ALIGN_LEFT, "%d", tanque_1.score);
 
			// Placar do jogador 2
			al_draw_textf(size_32, tanque_2.cor, SCREEN_W - SCREEN_W/4,
				6, ALLEGRO_ALIGN_RIGHT, "%d", tanque_2.score);

			//Jogo termina se jogador acerta 5 tiros
			if(tanque_1.score == 5 || tanque_2.score == 5)
				playing = 0;

			//atualiza a tela (quando houver algo para mostrar)
			al_flip_display();
			
			if(al_get_timer_count(timer)%(int)FPS == 0)
				printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
		}


		//se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			playing = 0;
		
		//se o tipo de evento for um pressionar de uma tecla
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			//imprime qual tecla foi
			printf("\ncodigo tecla: %d", ev.keyboard.keycode);
			
			switch(ev.keyboard.keycode){
				case ALLEGRO_KEY_W:
					tanque_1.vel -= VEL_TANQUE;
				break;
				case ALLEGRO_KEY_S:
					tanque_1.vel += VEL_TANQUE;
				break;
				case ALLEGRO_KEY_D:
					tanque_1.vel_angular += PASSO_ANGULO;
				break;	
				case ALLEGRO_KEY_A:
					tanque_1.vel_angular -= PASSO_ANGULO;
				break;
				case ALLEGRO_KEY_Q:
					atirar(&tanque_1);
				break;
				case ALLEGRO_KEY_I:
					tanque_2.vel -= VEL_TANQUE;
				break;
				case ALLEGRO_KEY_K:
					tanque_2.vel += VEL_TANQUE;
				break;
				case ALLEGRO_KEY_L:
					tanque_2.vel_angular += PASSO_ANGULO;
				break;	
				case ALLEGRO_KEY_J:
					tanque_2.vel_angular -= PASSO_ANGULO;
				break;
				case ALLEGRO_KEY_U:
					atirar(&tanque_2);
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			//imprime qual tecla foi
			printf("\ncodigo tecla: %d", ev.keyboard.keycode);
			
			switch(ev.keyboard.keycode){
				case ALLEGRO_KEY_W:
					if(tanque_1.vel!=0)
						tanque_1.vel += VEL_TANQUE;				
				break;
				case ALLEGRO_KEY_S:
					if(tanque_1.vel!=0)
						tanque_1.vel -= VEL_TANQUE;
				break;
				case ALLEGRO_KEY_D:
					tanque_1.vel_angular -= PASSO_ANGULO;
				break;	
				case ALLEGRO_KEY_A:
					tanque_1.vel_angular += PASSO_ANGULO;
				break;
				case ALLEGRO_KEY_I:
					if(tanque_2.vel != 0)
						tanque_2.vel += VEL_TANQUE;
				break;
				case ALLEGRO_KEY_K:
					if(tanque_2.vel != 0)
						tanque_2.vel -= VEL_TANQUE;
				break;
				case ALLEGRO_KEY_L:
					tanque_2.vel_angular -= PASSO_ANGULO;
				break;	
				case ALLEGRO_KEY_J:
					tanque_2.vel_angular += PASSO_ANGULO;
				break;
			}
		}
	}//fim do while

	// Tela final de historico das partidas
	al_stop_samples();
	Fim_da_partida(tanque_1, tanque_2);
	//procedimentos de fim de jogo (fecha a tela, limpa a memoria, etc)
	al_destroy_bitmap(fundo);
	destroy();
	al_destroy_sample(trilha_sonora);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}