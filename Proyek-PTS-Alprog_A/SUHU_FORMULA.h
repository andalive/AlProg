#include <stdio.h>

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define BOLD   "\033[1m"     //format teks tabal
#define RESET  "\033[0m"     //mengembalikan format teks asli

float celcius(){
	float c, result;
	char sKonversi;                  //sKonversi = (satuan suhu) konversi
	
	printf(GREEN">>"RESET" Nilai suhu   : ");
	scanf("%f", &c);
	while (getchar() != '\n');       //hapus buffer input scanf
	
	printf("\nPilih satuan konversi suhu: ");
	scanf(" %c", &sKonversi);
	while (getchar() != '\n');
	
	while (sKonversi != 'C' && sKonversi != 'R' && sKonversi != 'F' && sKonversi != 'K'){
		printf(RED"<INVALID INPUT>"RESET" Pilih satuan konversi suhu: ");
		scanf(" %c", &sKonversi);
		while (getchar() != '\n');
	}
	
	//formulasi konversi celcius
	switch(sKonversi) {
		case 'C':
			result = c;
			break;
		case 'R':
			result = (4.0/5.0)*c;
			break;
		case 'F':
			result = ((9.0/5.0)*c) + 32.0;
			break;
		case 'K':
			result = c + 273.0;
			break;	
	}
	
	return result;
}

//definisi fungsi formulasi suhu reamur (R)
float reamur(){
	float r, result;
	char sKonversi;
	
	printf(GREEN">>"RESET" Nilai suhu   : ");
	scanf("%f", &r);
	while (getchar() != '\n');       //hapus buffer input scanf
	
	printf("\nPilih satuan konversi suhu: ");
	scanf(" %c", &sKonversi);
	while (getchar() != '\n');
	
	while (sKonversi != 'C' && sKonversi != 'R' && sKonversi != 'F' && sKonversi != 'K'){
		printf(RED"<INVALID INPUT>"RESET" Pilih satuan konversi suhu: ");
		scanf(" %c", &sKonversi);
		while (getchar() != '\n');
	}
	
	//formulasi konversi reamur
	switch(sKonversi) {
		case 'C':
			result = (5.0/4.0)*r;
			break;
		case 'R':
			result = r;
			break;
		case 'F':
			result = ((9.0/4.0)*r) + 32.0;
			break;
		case 'K':
			result = ((5.0/4.0)*r) + 273.0;
			break;	
	}
	
	return result;
}

//definisi fungsi formulasi suhu fahrenheit (F)
float fahrenheit(){
	float f, result;
	char sKonversi;
	
	printf(GREEN">>"RESET" Nilai suhu   : ");
	scanf("%f", &f);
	while (getchar() != '\n');       //hapus buffer input scanf
	
	printf("\nPilih satuan konversi suhu: ");
	scanf(" %c", &sKonversi);
	while (getchar() != '\n');
	
	while (sKonversi != 'C' && sKonversi != 'R' && sKonversi != 'F' && sKonversi != 'K'){
		printf(RED"<INVALID INPUT>"RESET" Pilih satuan konversi suhu: ");
		scanf(" %c", &sKonversi);
		while (getchar() != '\n');
	}
	
	//formulasi konversi fahrenheit
	switch(sKonversi) {
		case 'C':
			result = (5.0/9.0)*(f - 32.0);
			break;
		case 'R':
			result = (4.0/9.0)*(f - 32.0);
			break;
		case 'F':
			result = f;
			break;
		case 'K':
			result = ((5.0/9.0)*(f - 32.0)) + 273.0;
			break;	
	}
	
	return result;
}

//definisi fungsi formulasi suhu kelvin (K)
float kelvin(){
	float k, result;
	char sKonversi;
	
	printf(GREEN">>"RESET" Nilai suhu   : ");
	scanf("%f", &k);
	while (getchar() != '\n');       //hapus buffer input scanf
	
	printf("\nPilih satuan konversi suhu: ");
	scanf(" %c", &sKonversi);
	while (getchar() != '\n');
	
	while (sKonversi != 'C' && sKonversi != 'R' && sKonversi != 'F' && sKonversi != 'K'){
		printf(RED"<INVALID INPUT>"RESET" Pilih satuan konversi suhu: ");
		scanf(" %c", &sKonversi);
		while (getchar() != '\n');
	}
	
	//formulasi konversi kelvin
	switch(sKonversi) {
		case 'C':
			result = k - 273.0;
			break;
		case 'R':
			result = (4.0/5.0)*(k - 273.0);
			break;
		case 'F':
			result = ((9.0/5.0)*(k - 273.0)) + 32.0;
			break;
		case 'K':
			result = k;
			break;	
	}
	
	return result;
}
