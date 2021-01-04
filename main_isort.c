#include "insertionSort.h"

#define INPUT_AMOUNT 50

//int* stringToArray(char* str);

int main() {

	int i;

	int temp=0;

	int arr[INPUT_AMOUNT]={0};

	for (i = 0; i < INPUT_AMOUNT; i++) {
		 if(scanf("%d", &temp) < 1)
		 {
			 printf("error,enter a natrual number\n");
			 i--;
		 }
		 else
		 {
			*(arr + i)=temp; 
		 }
	}

	//printf("Before sorting:\n");
	//printArray(arr, INPUT_AMOUNT);
	insertion_sort(arr, INPUT_AMOUNT);
	//printf("\n\nAfter sorting:\n");
	printArray(arr, INPUT_AMOUNT);
	return 0;
}







