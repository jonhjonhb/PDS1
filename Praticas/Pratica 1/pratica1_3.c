#include <stdio.h>

int main(){

	float cash;
	
	int i;
	
	int vetor[3];
	
	cash = 789,54;
	
	for(i = 0; i < 3; i++){
		
		if(i != 1 || !2){
			cash = cash * 1.0056;
		}	
		else{
			if(i = 1){
					cash = (cash + 303.20) * 1.0056;
			}
			if(i = 2){
					cash = (cash - 58.25) * 1.0056;
			}
		}
			
	}
	
	printf("%0.2f", cash);

}