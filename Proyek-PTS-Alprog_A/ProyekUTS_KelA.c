//PROGRAM       : Program sederhana konversi satuan suhu
//KELOMPOK A    :
//MICAHEL ANDHIKA         (NPM: 2206024940)
//HANNA MALIKA AZ-ZAHRA   (NPM: 2206055914)
//VIVA INOVA PINKY        (NPM: 2206056002)
//KHANZA MUHAMMAD         (NPM: 2206056210)
//CAMELIA PUTRI           (NPM: 2206812804)

//TANGGAL       : 23/03/2024
//VERSI         : 1.2       (MODIFIED: 27/03/2024)


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AUTHENTICATION.h"
#include "JUDUL_SUHU.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define YELLOW "\033[1;33m"  //format teks warna kuning + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define CYAN   "\033[1;36m"  //format teks warna cyan   + tebal
#define BLUE   "\033[1;34m"  //format teks warna biru   + tebal
#define BOLD   "\033[1m"     //format teks tabal
#define RESET  "\033[0m"     //mengembalikan format teks asli

int main (void) {
	int input1, lanjut;
	
	judul(); //memanggil fungsi judul()
	
	do {
		do {
			//Pilihan menu utama
			printf(CYAN"[1]"RESET" Log in\n");
			printf(CYAN"[2]"RESET" Sign up\n");
			printf(CYAN"[3]"RESET" Continue without an account\n\n"GREEN">>"RESET" ");
			scanf("%d", &input1);
			
			while (input1 != 1 && input1 != 2 && input1 != 3) {
				printf(RED"<INVALID INPUT>"RESET"\n"GREEN">>"RESET" ");
				scanf("%d", &input1);
			}
			
			printf(BOLD"< click 'Enter' >"RESET"\n");
			getch();
			system("cls");
			
			switch (input1) {
				case 1: //log in
					login();       //fungsi dari header authentication
					break;
				case 2: //sign up
					signup();      //fungsi dari header authentication
					
					printf(BOLD"< click 'Enter' >"RESET"\n");
					getch();
					system("cls");
					
					printf(GREEN"Silkan login untuk melanjutkan program"RESET"\n\n");
					login();
					break;
				case 3: //continue without an account
					tanpa_akun(); //fungsi dari header authentication
					break;
			}
		} while (input1 != 1 && input1 != 2 && input1 != 3);
		
		printf(BOLD"KEMBALI KE MENU UTAMA [Y/N]:"RESET" ");
		scanf(" %c", &lanjut);
		
		while (lanjut != 'Y' && lanjut != 'y' && lanjut != 'N' && lanjut != 'n') {
			printf(RED"INVALID INPUT!"RESET" KEMBALI KE MENU UTAMA [Y/N]: ");
			scanf(" %c", &lanjut);
		}
		
		printf(BLUE"=================================================================="RESET"\n");
		
		printf(BOLD"< click 'Enter' >"RESET"\n");
		getch();
		system("cls");
		
	} while (lanjut == 'Y'|| lanjut == 'y');
	
	printf(YELLOW"************************** TERIMA KASIH **************************"RESET"\n");
	
	getch();
	
	return 0;
}
