//PROGRAM       : SELECTION SORT ALGORITHM
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


//Fungsi selection sort
void selectionSort(int size_arr, int arr[]);

int main (void) {
	int size, cont = 1;
	printf("<SELECTION SORT>\n");
	
	while (cont == 1) {
		printf("Jumlah elemen data: ");
		scanf("%d", &size);
		
		int arr[size];
		addArray(size, arr);
		
		printf("\n"BLUE">>Data sebelum sorting:"RESET"\n");
		dispArray(size, arr);
		printf("==============================================================================\n");
		
		selectionSort(size, arr);
		
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


//Definisi fungsi selection sort
void selectionSort(int size_arr, int arr[]){
	int step, i, min_idx;
	
	//Loop untuk akses tiap elemen array
	for(step = 0; step < size_arr - 1; step++) {
		min_idx = step;       //inisialisasi elemen saat ini menjadi nilai minimum
		
		printf(GREEN"Iterasi sort ke# %d"RESET"\n", step + 1);
		
		//Loop untuk mencari pembanding elemen terkecil
		for (i = step + 1; i < size_arr; i ++) {
			printf("[min: %d] ", arr[min_idx]);
			dispArray(size_arr, arr);
			
			//ascending order
			//Set index array jika elemen pembanding lebih kecil dari inisialisasi awal
			if (arr[i] < arr[min_idx]) {
				min_idx = i;
			}
		}
		
		//Menukar elemen terkecil dengan posisi elemen saat ini
		swap(&arr[min_idx], &arr[step]);
		//Menampilkan urutan terbaru setelah swap elemen
		dispArray(size_arr, arr);
	}
}
