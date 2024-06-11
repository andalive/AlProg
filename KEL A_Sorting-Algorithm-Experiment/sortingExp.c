//
// DATA EKSPERIMEN
// SORTING ALGORITHM
//

#include <stdio.h>
#include <time.h>
#include "MAKEARRAY.h"
#include "SWAP.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define RESET  "\033[0m"     //mengembalikan format teks asli
#define MAX_ITER_COUNT 1000000


//========================================= BUBBLE SORT =========================================
//Definisi fungsi bubble sort
void bubbleSort(int size_arr, int arr[]){
	int step, i;
	
	for (step = 0; step < size_arr - 1; step++) {
		for (i = 0; i < size_arr - step - 1; i++) {
			if (arr[i] > arr [i + 1]) {
				swap (&arr[i], &arr[i + 1]);
			}
		}
	}
}

//========================================= SELECTION SORT =========================================
//Definisi fungsi selection sort
void selectionSort(int size_arr, int arr[]){
	int step, i, min_idx;
	
	for(step = 0; step < size_arr - 1; step++) {
		min_idx = step;
		
		for (i = step + 1; i < size_arr; i ++) {
			if (arr[i] < arr[min_idx]) {
				min_idx = i;
			}
		}
		
		swap(&arr[min_idx], &arr[step]);
	}
}

//========================================= INSERTION SORT =========================================
//Definisi fungsi insertion sort
void insertionSort(int size_arr, int arr[]) {
	int step, key, j;
	
	for(step = 1; step < size_arr; step++) {
		key = arr[step];
		j = step -1;
		
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		
		arr[j + 1] = key;
	}
}

//========================================= QUICK SORT =========================================
//Definisi fungsi untuk mencari fungsi partisi
int partition(int arr[], int low, int high) {
	int pivot = arr[high];              // elemen paling kanan sebagai pivot
	int i = (low - 1);                  // pointer elemen terbesar
	int j;

	for (j = low; j < high; j++) {
		if (arr[j] <= pivot) {          // jika elemen j lebih kecil/sama dari pivot
		i++;                            // swap elemen j dengan elemen terbesar yang ditunjuk i
		swap(&arr[i], &arr[j]);
		}
	}
	
  	swap(&arr[i + 1], &arr[high]);      // swap pivot dengan elemen terbesar pada i
	return (i + 1);                     // return the partition point
}


//Definisi fungsi quicksort
void quickSort(int arr[], int low, int high) {
	if (low < high) {
	    int pi = partition(arr, low, high);
	    quickSort(arr, low, pi - 1);
	    quickSort(arr, pi + 1, high);
	}
}



//Fungsi utama
int main(void){
	int size, i, iter, cont = 1;
	
	while (cont == 1) {
		printf("Jumlah elemen data: ");
		scanf("%d", &size);
		
		int arr[size];
		addArray(size, arr);
		
		printf("\n>>Data sebelum sorting:\n");
		dispArray(size, arr);
		printf("==============================================================================\n");
		
		for (i = 0; i < 10; i++) {
			printf("DATA ke-%d\n", i+1);
			
			clock_t start1, start2, start3, start4, end1, end2, end3, end4;
		
			//=========================[ BUBBLE SORT ]============================================================
			start1 = clock();
			for (iter = 0; iter < MAX_ITER_COUNT; iter++) {
				bubbleSort(size, arr);
			}
			end1 = clock();
			double excTime1 = (double)(end1 - start1) * 100000 / CLOCKS_PER_SEC / MAX_ITER_COUNT;
			
			printf(">> Hasil bubble sort:\n");
			dispArray(size, arr);
			
			printf("Run time: %lf s\n", excTime1);
			
			//=========================[ SELECTION SORT ]==========================================================
			start2 = clock();
			for (iter = 0; iter < MAX_ITER_COUNT; iter++) {
				selectionSort(size, arr);
			}
			end2 = clock();
			double excTime2 = (double)(end2 - start2) * 100000 / CLOCKS_PER_SEC / MAX_ITER_COUNT;
			
			printf(">> Hasil selection sort:\n");
			dispArray(size, arr);
			
			printf("Run time: %lf s\n", excTime2);
			
			//=========================[ INSERTION SORT ]==========================================================
			start3 = clock();
			for (iter = 0; iter < MAX_ITER_COUNT; iter++) {
				insertionSort(size, arr);
			}
			end3 = clock();
			double excTime3 = (double)(end3 - start3) * 100000 / CLOCKS_PER_SEC / MAX_ITER_COUNT;
			
			printf(">> Hasil insertion sort:\n");
			dispArray(size, arr);
			
			printf("Run time: %lf s\n", excTime3);
			
			//=========================[ QUICK SORT ]===============================================================
			start4 = clock();
			for (iter = 0; iter < MAX_ITER_COUNT; iter++) {
				quickSort(arr, 0, size - 1);
			}
			end4 = clock();
			double excTime4 = (double)(end4 - start4) * 100000 / CLOCKS_PER_SEC / MAX_ITER_COUNT;
			
			printf(">> Hasil quick sort:\n");
			dispArray(size, arr);
			
			printf("Run time: %lf s\n", excTime4);
			
			printf("==============================================================================\n");
		}
		
		
		printf("\nLanjut [1]Y/[0]N: ");
		scanf("%d", &cont);
		while (cont != 0 && cont != 1) {
			printf(RED"<INVALID INPUT>"RESET" Lanjut [1]Y/[0]N: ");
			scanf("%d", &cont);
		}
		printf("==============================================================================\n");
	}
	
	return 0;
}
