#include <stdio.h>
#include <stdlib.h>
#include "SUHU_FORMULA.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define BOLD   "\033[1m"     //format teks tabal
#define RESET  "\033[0m"     //mengembalikan format teks asli

void konversiSuhu() {
	char sSuhu, lanjut;   //sSuhu = (satuan suhu)
	float hasil;
	
	printf(BOLD"[ Pastikan input satuan suhu dengan huruf kapital! ]"RESET"\n");
	printf("Pilih satuan awal suhu    : ");
	scanf(" %c", &sSuhu);
	while (getchar() != '\n');  //hapus buffer input
	
	while (sSuhu != 'C' && sSuhu != 'R' && sSuhu != 'F' && sSuhu != 'K'){
		printf(RED"<INVALID INPUT>"RESET" Pilih satuan suhu awal    : ");
		scanf(" %c", &sSuhu);
		while (getchar() != '\n');  //hapus buffer input
	}
	
	switch(sSuhu) {
		case 'C':
			hasil = celcius();
			break;
		case 'R':
			hasil = reamur();
			break;
		case 'F':
			hasil = fahrenheit();
			break;
		case 'K':
			hasil = kelvin();
			break;	
	}
		
	printf(GREEN">>"RESET" Konversi suhu: [%.2f]", hasil);
	
	printf("\n------------------------------------------------------------------\n");
}
