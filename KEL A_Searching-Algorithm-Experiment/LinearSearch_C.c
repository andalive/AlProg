//PROGRAM       : LINEAR SEARCH ALGORITHM
//KELOMPOK A    :
//HANNA MALIKA AZ-ZAHRA   (NPM: 2206055914)
//VIVA INOVA PINKY        (NPM: 2206056002)
//HANA RAISSA EARLABIBA   (NPM: 2206056160)
//CAMELIA PUTRI           (NPM: 2206812804)

//TANGGAL       : 07/06/2024
//VERSI         : 1.2       (MODIFIED: 09/03/2024)


#include <stdio.h>
#include "LINEARSEARCH.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define RESET  "\033[0m"     //mengembalikan format teks asli

int main (void) {
	//int arr1[] = {32, 5, 100, 6, 41, 1, 73, 14, 9, 11, 12, 15, 21, 58, 7, 3, 37, 201, 13, 911, 59};
	//int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {1, 5, 7, 11, 13, 14, 19, 21, 37, 51, 69, 84, 91, 99, 100};
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int k, result, cont = 1;
	
	
	printf("<LINEAR SEARCH>\nElemen array:\n[1, 5, 7, 11, 13, 14, 19, 21, 37, 41, 44, 47, 51, 69, 73, 81, 84, 91, 99, 100]\n");
	printf("==============================================================================\n\n");
	
	while (cont == 1) {
		printf("Cari nilai: ");
		scanf("%d", &k);
		
		//result1 = linearSearch(size1, arr1, k);
		result = linearSearch(size2, arr2, k);
		
		//Menampilkan hasil pencarian elemen
		if (result != -1) {
			printf(GREEN"Element found at index: %d"RESET"\n\n", result);
		} else {
			printf(RED"Element not found"RESET"\n\n");
		}
		
		printf("Lanjut [1]Y/[0]N: ");
		scanf("%d", &cont);
		while (cont != 0 && cont != 1) {
			printf(RED"<INVALID INPUT>"RESET" Lanjut [1]Y/[0]N: ");
			scanf("%d", &cont);
		}
		printf("==============================================================================\n");
	}
	
	
	return 0;
}

