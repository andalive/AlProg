//PROGRAM       : INSERTION SORT ALGORITHM
//KELOMPOK A    :
//HANNA MALIKA AZ-ZAHRA   (NPM: 2206055914)
//VIVA INOVA PINKY        (NPM: 2206056002)
//HANA RAISSA EARLABIBA   (NPM: 2206056160)
//CAMELIA PUTRI           (NPM: 2206812804)

//TANGGAL       : 10/06/2024
//VERSI         : 1.0       (MODIFIED: -)


#include <stdio.h>
#include "MAKEARRAY.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define BLUE   "\033[1;34m"  //format teks waran biru   + tebal
#define RESET  "\033[0m"     //mengembalikan format teks asli


//Fungsi insertion sort
void insertionSort(int size_arr, int arr[]);


int main (void) {
	int size, cont = 1;
	printf("<INSERTION SORT>\n");
	
	while (cont == 1) {
		printf("Jumlah elemen data: ");
		scanf("%d", &size);
		
		int arr[size];
		addArray(size, arr);
		
		printf("\n"BLUE">>Data sebelum sorting:"RESET"\n");
		dispArray(size, arr);
		printf("==============================================================================\n");
		
		insertionSort(size, arr);
		
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


//Definisi fungsi insertion sort
void insertionSort(int size_arr, int arr[]) {
	int step, key, j;
	
	// Loop untuk iterasi tiap elemen array
	for(step = 1; step < size_arr; step++) {
		key = arr[step];  // inisialisasi key sebagai elemen array saat ini
		j = step -1;      // inisialisasi j ke index sebelumnya
		
		// Menampilkan proses sorting array
		printf(GREEN"Iterasi sort ke# %d"RESET"\n", step);
		dispArray(size_arr, arr);
		// Menunjukkan elemen yang di-insert/di-sisipkan
		printf("Insert: %d\n", arr[j + 1]);
		
		// Loop untuk geser elemen lebih besar dari key ke kanan
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];               //geser elemen ke kanan
			j--;                               //decrement j
		}
		
		// Menyisipkan key ke posisi yang sesuai
		arr[j + 1] = key;
		// Hasil sorting setelah penyisipan elemen tertentu
		dispArray(size_arr, arr);
	}
}
