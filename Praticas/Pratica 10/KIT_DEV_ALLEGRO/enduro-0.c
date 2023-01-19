#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


const float FPS = 100;  

const int SCREEN_W = 960;
const int SCREEN_H = 540;

const float VEL_CARRO = 1.5;
const float RAIO_CAMPO_FORCA = 50;

typedef struct Ponto {
	float x, y;
} Ponto;

typedef struct Block {
	Ponto top_left;
	Ponto bottom_right;
} Block ;

typedef struct Carro {
	
	Ponto rodaFrente;
	Ponto rodaTras;
	ALLEGRO_COLOR cor;

	Block principal;
	Block frente;
	float vel;

} Carro;

void desenhaCenario()
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	//contorno do cenario
	al_draw_filled_rectangle(0, SCREEN_H-150, SCREEN_W, SCREEN_H, al_map_rgb(0,0,0));
	//Divisoria da Pista
	al_draw_filled_rectangle(SCREEN_W/10*1, SCREEN_H-65 , SCREEN_W/10*3, 
		SCREEN_H-90, al_map_rgb(255,200,0));
	al_draw_filled_rectangle(SCREEN_W/10*4, SCREEN_H-65 , SCREEN_W/10*6, 
		SCREEN_H-90, al_map_rgb(255,200,0));
	al_draw_filled_rectangle(SCREEN_W/10*7, SCREEN_H-65 , SCREEN_W/10*9, 
		SCREEN_H-90, al_map_rgb(255,200,0));

}

void initCarro(Carro *c) 
{

	c->rodaFrente.x = SCREEN_W/10*3;
	c->rodaFrente.y = SCREEN_H-150;
	c->rodaTras.x = c->rodaFrente.x+300;
	c->rodaTras.y = c->rodaFrente.y;
	c->cor = al_map_rgb(255, 30, 30);

	c->principal.top_left.x = c->rodaFrente.x-100;
	c->principal.top_left.y = c->rodaFrente.y-200;
	c->principal.bottom_right.x = c->rodaTras.x;
	c->principal.bottom_right.y = c->rodaTras.y;

	c->frente.top_left.x = c->rodaTras.x;
	c->frente.top_left.y = c->principal.top_left.y*1.4;
	c->frente.bottom_right.x = c->rodaTras.x+100;
	c->frente.bottom_right.y = c->rodaTras.y;

	c->vel = 0;	

}

void desenhaCarro (Carro c)
{
	//Desenho carroceria
	al_draw_filled_rectangle(c.principal.top_left.x, c.principal.top_left.y, 
		c.principal.bottom_right.x, c.principal.bottom_right.y, c.cor);
	al_draw_filled_rectangle(c.frente.top_left.x, c.frente.top_left.y, 
		c.frente.bottom_right.x, c.frente.bottom_right.y, c.cor);

	//Desenho rodas
	al_draw_filled_circle(c.rodaFrente.x, c.rodaFrente.y, RAIO_CAMPO_FORCA, al_map_rgb(51,51,51));
	al_draw_filled_circle(c.rodaTras.x, c.rodaTras.y, RAIO_CAMPO_FORCA, al_map_rgb(51,51,51));
	al_draw_filled_circle(c.rodaTras.x, c.rodaTras.y, RAIO_CAMPO_FORCA-10, al_map_rgb(151,151,151));
	al_draw_filled_circle(c.rodaFrente.x, c.rodaFrente.y, RAIO_CAMPO_FORCA-10, al_map_rgb(151,151,151));
	
	//contornos
	//al_draw_rectangle(SCREEN_W/10*7, SCREEN_H-65 , SCREEN_W/10*9, 
	//	SCREEN_H-90, al_map_rgb(255,200,0), 10);
}

void atualizaCarro(Carro *c)
{
	
	if(c->rodaFrente.x + c->vel + 400 <= SCREEN_W && 
		c->rodaFrente.x + c->vel - 100 >= 0){


		c->rodaFrente.x += c->vel;
		c->rodaTras.x = c->rodaFrente.x+300;
		c->principal.top_left.x = c->rodaFrente.x-100;
		c->principal.bottom_right.x = c->rodaTras.x;
		c->frente.top_left.x = c->rodaTras.x;
		c->frente.bottom_right.x = c->rodaTras.x+100;
		
	}

	if(c->rodaFrente.x + c->vel + 400 >= SCREEN_W || 
		c->rodaFrente.x + c->vel - 100 <= 0){
		c->vel = 0;
	}

}
 
int main(int argc, char **argv){
	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
   
	//----------------------- rotinas de inicializacao ---------------------------------------
    
	//inicializa o Allegro
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
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

	//instala o teclado
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return -1;
	}

	//inicializa o modulo allegro que carrega as fontes
	al_init_font_addon();

	//inicializa o modulo allegro que entende arquivos tff de fontes
	if(!al_init_ttf_addon()) {
		fprintf(stderr, "failed to load tff font module!\n");
		return -1;
	}
	
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
   


	//registra na fila os eventos de tela (ex: clicar no X na janela)
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila os eventos de tempo: quando o tempo altera de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra na fila os eventos de teclado (ex: pressionar uma tecla)
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//cria o carro
	Carro carro;
	initCarro(&carro);

	//inicia o temporizador
	al_start_timer(timer);
	
	int playing = 1;
	while(playing) {

		ALLEGRO_EVENT ev;
		//espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);

		//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		if(ev.type == ALLEGRO_EVENT_TIMER) {

			desenhaCenario();

			atualizaCarro(&carro);

			desenhaCarro(carro);


			//atualiza a tela (quando houver algo para mostrar)
			al_flip_display();
			
			if(al_get_timer_count(timer)%(int)FPS == 0)
				printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
		}
		//se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
		}

		//se o tipo de evento for um pressionar de uma tecla
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			//imprime qual tecla foi
			printf("\ncodigo tecla: %d", ev.keyboard.keycode);
			switch(ev.keyboard.keycode){
				case ALLEGRO_KEY_RIGHT:
					carro.vel += VEL_CARRO;
				break;	
				case ALLEGRO_KEY_LEFT:
					carro.vel -= VEL_CARRO;
				break;
			}
		}

	} //fim do while
     
	//procedimentos de fim de jogo (fecha a tela, limpa a memoria, etc)
	
 
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
   
 
	return 0;
}