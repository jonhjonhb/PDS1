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
	printf("\n%s\n", str);

	return 0;
}

void main(){

	//Teste
	str();
}