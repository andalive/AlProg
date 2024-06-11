#include <stdio.h>
#include <string.h>
#include "KONV_SUHU.h"

#define RED    "\033[1;31m"  //format teks warna merah  + tebal
#define YELLOW "\033[1;33m"  //format teks warna kuning + tebal
#define GREEN  "\033[1;32m"  //format teks warna hijau  + tebal
#define CYAN   "\033[1;36m"  //format teks warna cyan   + tebal
#define BOLD   "\033[1m"     //format teks tabal
#define RESET  "\033[0m"     //mengembalikan format teks asli

//DEFINSI STRUCT PROFILE
struct profile {
	char username[50];
	char password[50];
};


//DEFINISI FUNGSI mulai_ulang()
int mulai_ulang(int kredit) {
	char lanjut;
	do {
		if (kredit == 0) {
			printf(RED"Kredit Anda habis!"RESET"\n\n");
			break;
		}
		
		printf(YELLOW"\t\t\tSisa kredit: %d"RESET"\n\n", kredit);
			
		konversiSuhu();
		kredit--;

		//instruksi memulai program kembali
		printf(BOLD"MULAI ULANG KONVERTER SUHU [Y/N]"RESET": ");
		scanf(" %c", &lanjut);

		while (lanjut != 'Y' && lanjut != 'y' && lanjut != 'N' && lanjut != 'n') {
			printf(RED"INVALID INPUT!"RESET" MULAI ULANG KONVERTER SUHU [Y/N]: ");
			scanf(" %c", &lanjut);
		}
		
		printf(CYAN"=================================================================="RESET"\n\n");
	} while (lanjut == 'Y'|| lanjut == 'y');
}


//------------------------------------------------------------------------------------------------
//DEFINISI FUNGSI login()
int login() {
	struct profile user;
	int kredit = 10, loginCheck = 0;   //flag login berhasil
	
	printf("Silakan masukkan username dan password Anda\n");
				
	do {
		//instruksi untuk menginput username
		printf("Username: ");
		scanf("%s", user.username);
		
		//instruksi untuk menginput password
		printf("Passowrd: ");
		scanf("%s", user.password);
					
		//membuka file data username dan password pengguna untuk dibaca
		FILE *ptrUser = fopen("username.txt", "r");
		FILE *ptrPass = fopen("pass.txt", "r");
					
		//cek eksistensi file username.txt dan pass.txt
		if (ptrUser == NULL || ptrPass == NULL) {
			printf("File tidak ada.");
			return 1;
		}
					
		//variabel untuk menyimpan konten dari file username.txt dan pass.txt
		char userCheck[50]; 
		char pwCheck[50];
		int found = 0;      //flag username + password ditemukan dalam file

		//cek keberadaan username + password pengguna			
		while (fscanf(ptrUser, "%s", userCheck) != EOF){
			fscanf(ptrPass, "%s", pwCheck);
			if(strcmp(userCheck, user.username) == 0 && strcmp(pwCheck, user.password) == 0) {
				found = 1;  //username + password ditemukan
				break;
			}
		}

		//menutup file data username dan password pengguna	
		fclose(ptrUser);
		fclose(ptrPass);
					
		//eksistensi username + pasword setelah dicek dalam file
		if (found) {
			printf(CYAN"[Berhasil masuk!]"RESET"\n\n");
			loginCheck = 1;
		} else {
			printf(RED"[Login gagal!"RESET" Username atau password Anda salah]\n\n");
		}
					
	} while (!loginCheck);
	
	printf(BOLD"< click 'Enter' >"RESET"\n");
	getch();
	system("cls");

	mulai_ulang(kredit);
}


//DEFINISI FUNSGI signup()
int signup() {
	struct profile user;
	int signupCheck = 0;   //flag signup berhasil
	
	printf(YELLOW"Silakan buat akun Anda!"RESET"\n\n");
		
	while (!signupCheck) {
		//instruksi untuk menginput username
		printf("Masukkan username\n"GREEN">>"RESET" ");
		scanf("%s", user.username);
		while (getchar() != '\n');  //hapus buffer input
		
		//instruksi untuk menginput password
		printf("Masukkan password\n"GREEN">>"RESET" ");
		scanf("%s", user.password);
		while (getchar() != '\n');  //hapus buffer input
		
		//membuka file data username + password pengguna untuk dibaca
		FILE *ptrUserCheck = fopen("username.txt", "r");
		FILE *ptrPassCheck = fopen("pass.txt", "r");
		
		//cek eksistensi file username.txt dan pass.txt
		if (ptrUserCheck == NULL || ptrPassCheck == NULL) {
			printf("File tidak ada.");
			return 1;
		}
		
		//variabel untuk menyimpan konten dari file username.txt dan pass.txt 
		char userCheck[50];
		char pwCheck[50];
		int found = 0;    //flag username + password ditemukan dalam file

		//cek keberadaan username + password pengguna (cek duplikasi akun sama)			
		while (fscanf(ptrUserCheck, "%s", userCheck) != EOF){
			fscanf(ptrPassCheck, "%s", pwCheck);
			if(strcmp(userCheck, user.username) == 0) {
				found = 1;
				printf(RED"[Username sudah ada]"RESET" Silakan coba lagi!\n\n");
				break;
			}
		}
		
		//menutup file data username + password pengguna
		fclose(ptrUserCheck);
		fclose(ptrPassCheck);

		//kondisi terkait duplikasi/tidak akun baru pengguna	
		if (!found) {
			signupCheck = 1;
		}
	}
	
	//membuka file data username + password untuk menambahkan akun baru
	FILE *ptrUser = fopen("username.txt", "a");
	FILE *ptrPass = fopen("pass.txt", "a");
	
	//cek eksistensi file username.txt dan password.txt
	if (ptrUser == NULL || ptrPass == NULL) {
		printf("File tidak ada.");
		return 1;
	}
	
	//menyalin input data baru (akun pengguna) ke dalam file
	fprintf(ptrUser, "\n%s", user.username);
    fprintf(ptrPass, "\n%s", user.password);
	
	//menutup file data username + password pengguna
	fclose(ptrUser);
	fclose(ptrPass);
	
	printf("\n"CYAN"[Akun berhasil dibuat!]"RESET"\n");
}


//DEFINISI FUNGSI tanpa_akun()
int tanpa_akun() {
	int input1, kredit = 3, codeCheck = 0;
	char input2[50], lanjut;
	
	printf("Apakah Anda memiliki kode voucher?\n");
	printf(RED"[1]"RESET"Ya\n"RED"[2]"RESET"Tidak\n\n"GREEN">>"RESET" ");
	scanf("%d", &input1);
	
	while (input1 != 1 && input1 != 2) {
			printf(RED"<INVALID INPUT>"RESET"\n>> ");
			scanf("%d", &input1);
		}
	
	printf(CYAN"=================================================================="RESET"\n\n");
	
	//kondisi pilihan terkait voucher pengguna
	if (input1 == 1){  //jika pengguna memiliki voucher
		while (!codeCheck) {
			printf("Masukkan kode voucher\n"GREEN">>"RESET" ");
			scanf("%s", &input2);
			while (getchar() != '\n');  //hapus buffer input
			
			//membuka file kode voucher sistem
			FILE *ptrVoucher = fopen("voucher.txt", "r");
						
			//cek eksistensi file voucher.txt
			if (ptrVoucher == NULL) {
				printf("File tidak ada.");
				return 1;
			}
						
			//variabel untuk menyimpan konten dalam file voucher.txt
			char voucherCheck[50];
			int found = 0;   //flag kode voucher ditemukan dalam file
			
			//cek input kode voucher pengguna
			while (fscanf(ptrVoucher, "%s", voucherCheck) != EOF){
				if(strcmp(voucherCheck, input2) == 0) {
					found = 1;  //kode voucher ditemukan
					break;
				}
			}

			//menutup file kode voucher		
			fclose(ptrVoucher);

			//kondisi validasi voucher diinput		
			if (found) {
				printf(YELLOW"[Voucher valid! 10 kredit ditambahkan]"RESET"\n\n");
				
				kredit += 7;  //kredit ditambahkan
				printf("\t\t\t>> Kredit Anda: %d  <<\n", kredit);
				
				codeCheck = 1;
				
				getch();
				system("cls");
				
				mulai_ulang(kredit);
			} else {
				printf(RED"[Voucher invalid]"RESET"\n\n");
				
			}
		}
	} else {      // jika pengguna tidak memiliki voucher
		printf("\t\t\t>> Kredit Anda: %d  <<\n", kredit);
		
		printf(BOLD"< click 'Enter' >"RESET"\n");
		getch();
		system("cls");
	
		mulai_ulang(kredit);
	}
}
