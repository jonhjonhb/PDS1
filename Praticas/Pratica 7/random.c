#include <stdlib.h>

//aleatorio float 0 ... 1
float randf(){
	return (float)rand()/RAND_MAX;
}

//aleatorio float entre min e max
float randFloat(float min, float max){
	return min + randf()*(max - min);
}

//aleatorio 0 ... n-1
float random(int n){
	return rand() % n;
}

//aleatorio entre min e max
float randInt(int min, int max){
	return min + random(max - min +1);
}