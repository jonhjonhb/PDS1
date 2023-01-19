#include <stdio.h>

int tranforma_string(char x[]){

	int i=0;
	for (i=0; x[i]!='\0'; i++){
	if (x[i] == ' '){
		i++;
		continue;
	}
	if (x[i] > 64 && x[i] < 91){
		i++;
		continue;
	}
	x[i] -= 32;
	}
}

int numero(char str[]){
	int i = 1;
	for (i=1; str[i] != 0; i++);
	return i-1;
}

int palindromo(char str[]){

	int i = numero(str);
	int x = 0;
	int meio = i/2;
	int inv = 1;
	while (i >= meio){
		if (str[i] != str[x]){
			inv = 0;
			break;
		}
		x++;
		i--;
	}

	if (inv)
		printf("\nEh um palindromo.\n");
	else 
		printf("\nNao eh um palindromo.\n");
	
	return 0;	
}

int str(){
	int i=0;
	char str[100];
	printf("Digite sua string:\n");
	for(i = 0; i<100 ; i++){
		scanf("%c", &str[i]);
		if (str[i] == '.' || str[i] == '\n'){
			break;
		}
	}
	str[i] = '\0';	
	tranforma_string(str);
	palindromo(str);

	return 0;
}

void main(){

	//Teste
	str();
}