#include "insertionSort.h"

void shift_element(int* arr, int i) {
	int index;
	for (index = i; index > 0; index--) {

		*(arr + index) = *(arr + index - 1);//arr[index] = arr[index - 1]
	}
}


void insertion_sort(int* arr, int len) {

	int i, j, key, howManyToShift;

    for (j = 1; j < len; j++) {

        key = *(arr + j);

        howManyToShift = 0;

        i = j - 1;

        while (i >= 0 && *(arr + i) > key) {

            howManyToShift++;
            i--;
        }
        shift_element(arr + i + 1, howManyToShift);
        *(arr + i + 1) = key;
    }

}







void printArray(int* arr, int i) {

    int index;

    for (index = 0; index < i-1; index++) {

        printf("%d,", *(arr + index));

    }
    printf("%d", *(arr + i-1));

}



