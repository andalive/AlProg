//PROGRAM       : BUBBLE SORT ALGORITHM
//KELOMPOK A    :
//HANNA MALIKA AZ-ZAHRA   (NPM: 2206055914)
//VIVA INOVA PINKY        (NPM: 2206056002)
//HANA RAISSA EARLABIBA   (NPM: 2206056160)
//CAMELIA PUTRI           (NPM: 2206812804)

//TANGGAL       : 09/06/2024
//VERSI         : 1.0       (MODIFIED: -)


#include <stdio.h>
#include "MAKEARRAY.h"
#include "SWAP.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define BLUE   "\033[1;34m"  //format teks waran biru   + tebal
#define RESET  "\033[0m"     //mengembalikan format teks asli


//Fungsi bubble sort
void bubbleSort(int size_arr, int arr[]);


int main (void) {
	int size, cont = 1;
	printf("<BUBBLE SORT>\n");
	
	while (cont == 1) {
		printf("Jumlah elemen data: ");
		scanf("%d", &size);
		
		int arr[size];
		addArray(size, arr);
		
		printf("\n"BLUE">>Data sebelum sorting:"RESET"\n");
		dispArray(size, arr);
		printf("==============================================================================\n");
		
		bubbleSort(size, arr);
		
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


//Definisi fungsi bubble sort
void bubbleSort(int size_arr, int arr[]){
	int step, i;
	
	//Loop untuk akses tiap elemen array
	for (step = 0; step < size_arr - 1; step++) {
		
		printf(GREEN"Iterasi sort ke# %d"RESET"\n", step + 1);
		
		//Loop pembanding tiap elemen array
		for (i = 0; i < size_arr - step - 1; i++) {
			dispArray(size_arr, arr);    //menampilkan array saat ini
			
			// Cek elemen saat ini lebih besar dari elemen berikutnya
			if (arr[i] > arr [i + 1]) {
				printf(BLUE"[%d > %d] SWAP"RESET"\n", arr[i], arr[i + 1]);
				
				//Swap elemen jika tidak sesuai urutan (order)
				swap (&arr[i], &arr[i + 1]);
			} else {
				printf(RED"[%d < %d] NO SWAP"RESET"\n", arr[i], arr[i + 1]);
			}
		}
	}
}

