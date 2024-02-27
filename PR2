//PROGRAM       : Program sederhana konversi satuan suhu
//AUTHOR        : HANNA MALIKA AZ-ZAHRA   (NPM: 2206055914)
//TANGGAL       : 26/02/2024
//VERSI         : 1.1       (MODIFIED: 27/02/2024)


#include <stdio.h>
#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define YELLOW "\033[1;33m"  //format teks warna kuning + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define CYAN   "\033[1;36m"  //format teks warna cyan   + tebal
#define BOLD   "\033[1m"     //format teks tabal
#define RESET  "\033[0m"     //mengembalikan format teks asli

//prototipe fungsi judul program
void judul();

//prototipe fungsi formulasi suhu celcius (C)
float celcius();

//prototipe fungsi formulasi suhu reamur (R)
float reamur();

//prototipe fungsi formulasi suhu fahrenheit (F)
float fahrenheit();

//prototipe fungsi formulasi suhu kelvin (K)
float kelvin();

//fungsi utama
int main(void) {
	char sSuhu, lanjut;   //sSuhu = (satuan suhu) awal
	float hasil;
	
	//menampilkan judul program
	judul();
	
	do {
		printf(RED"[ Pastikan input satuan suhu dengan huruf kapital! ]"RESET"\n");
		printf("Pilih satuan awal suhu    : ");
		scanf(" %c", &sSuhu);
		while (getchar() != '\n');
	
		while (sSuhu != 'C' && sSuhu != 'R' && sSuhu != 'F' && sSuhu != 'K'){
			printf(RED"<INVALID INPUT>"RESET" Pilih satuan suhu awal    : ");
			scanf(" %c", &sSuhu);
			while (getchar() != '\n');
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
		
		printf(GREEN">>"RESET" Konversi suhu: "GREEN"["RESET"%.2f"GREEN"]"RESET, hasil);
		
		printf(YELLOW"\n----------------------------------------------------"RESET"\n");
		
		//instruksi memulai program kembali
		printf("MULAI ULANG KONVERTER SUHU ["GREEN"Y"RESET"/"GREEN"N"RESET"]: ");
		scanf(" %c", &lanjut);
		
		while (lanjut != 'Y' && lanjut != 'y' && lanjut != 'N' && lanjut != 'n') {
			printf(RED"INVALID INPUT!"RESET" MULAI ULANG KONVERTER SUHU ["GREEN"Y"RESET"/"GREEN"N"RESET"]: ");
			scanf(" %c", &lanjut);
		}
		printf(YELLOW"===================================================="RESET"\n\n");
		
	} while (lanjut == 'Y'|| lanjut == 'y');
	
	printf(CYAN"******************* TERIMA KASIH! ******************"RESET"\n");

	return 0;
}

//definisi fungsi judul program
void judul(){
	printf(CYAN"===================================================="RESET"\n");
	printf(CYAN"||                  KONVERSI SUHU                 ||"RESET"\n");
	printf(CYAN"===================================================="RESET"\n\n");
}

//definisi fungsi formulasi suhu celcius (C)
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
		printf(RED"<INVALID INPUT>"RESET" ilih satuan konversi suhu: ");
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


