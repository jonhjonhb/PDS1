#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BUFFER_TAM 5

int main()
{
    char *textoaux = NULL;
    char *texto = NULL;
    char caractere;
    char buffer[BUFFER_TAM];
    int contBuffer = 0, cont = 0;

    do
    {
        caractere = getche();
        if(caractere == '\r'){
            caractere = '\n';
            printf("\n");
        }
        if(contBuffer < BUFFER_TAM){
            buffer[contBuffer] = caractere;
            contBuffer++;
        }    
        if(contBuffer == BUFFER_TAM || caractere == '#'){
            textoaux = (char*)malloc((cont + contBuffer) *sizeof(char));
            for(int i = 0; i<cont; i++)
                textoaux[i] = texto[i];
            for(int i = 0; i<contBuffer; i++)
                textoaux[cont+i] = buffer[i];
            if(texto != NULL)
                free(texto);
            texto = textoaux;
            cont += contBuffer;
            contBuffer = 0;
        }
    } while(caractere != '#');
    texto[cont-1] = '\0';
    printf("\nTexto:\n%s", texto);
    free(texto);
    
    return 0;
}