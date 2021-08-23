#include <stdio.h>
#include <stdbool.h>

#define TAM 10

int binarySearch(int *array, int min, int max, int target);

int main(){
	
	int array[TAM] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int index = binarySearch(array, 0, TAM-1, 23);

	printf("Posicao: %d\n", index);

	return 0;	
}

int binarySearch(int *array, int min, int max, int target){
	
	while(true){
		if(max < min){ // O elemento não se encontra no array
			return -1;
		}
		
		int guess = (max + min)/2;
		
		if(array[guess] == target){ // O elemento procurado está exatamenente no índice (max+min)/2
			return guess;
		}
		
		if(array[guess] < target){ // O elemento de array no índice guess é menor que o target
			min = guess +1;
		}else if(array[guess] > target){ // O elemento de array no índice guess é maior que o target
			max = guess -1;
		}
	}
	
}
