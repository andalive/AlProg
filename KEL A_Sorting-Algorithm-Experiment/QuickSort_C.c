//PROGRAM       : QUICK SORT ALGORITHM
//KELOMPOK A    :
//HANNA MALIKA AZ-ZAHRA   (NPM: 2206055914)
//VIVA INOVA PINKY        (NPM: 2206056002)
//HANA RAISSA EARLABIBA   (NPM: 2206056160)
//CAMELIA PUTRI           (NPM: 2206812804)

//TANGGAL       : 10/06/2024
//VERSI         : 1.1       (MODIFIED: 11/06/2024)


#include <stdio.h>
#include "MAKEARRAY.h"
#include "SWAP.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define BLUE   "\033[1;34m"  //format teks waran biru   + tebal
#define RESET  "\033[0m"     //mengembalikan format teks asli


//Function to find the partition position
int partition(int arr[], int low, int high);

//Fungsi quick Sort
void quickSort(int arr[], int low, int high);


int main() {
	int size, cont = 1;
	printf("<QUICK SORT>\n");
	
	while (cont == 1) {
		printf("Jumlah elemen data: ");
		scanf("%d", &size);
		
		int arr[size];
		addArray(size, arr);
		
		printf("\n"BLUE">>Data sebelum sorting:"RESET"\n");
		dispArray(size, arr);
		printf("==============================================================================\n");
		
		quickSort(arr, 0, size - 1);
		
		printf("\n"BLUE">> Hasil sorting:"RESET"\n");
		dispArray(size, arr);
		
		
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


//Definisi fungsi untuk mencari fungsi partisi
int partition(int arr[], int low, int high) {
	int pivot = arr[high];              // elemen paling kanan sebagai pivot
	int i = (low - 1);                  // pointer elemen terbesar
	int j;
	
	//Loop pembanding tiap elemen array dengan pivot
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
	    // menemukan elemen pivot sehingga
	    // elemen lebih kecil dari pivot ada di kiri pivot
	    // elemen lebih besar dari pivot ada di kanan pivot
	    int pi = partition(arr, low, high);
	    
	    // fungsi rekursif pada sisi kiri pivot
	    quickSort(arr, low, pi - 1);
	    
	    // fungsi rekursig pada sisi kanan pivot
	    quickSort(arr, pi + 1, high);
	}
}
