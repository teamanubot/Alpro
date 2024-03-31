/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define ESC 27

typedef struct{
	double rAngkaPertama, rAngkaKedua, rHasil;
	int subMenu;
	char _Menu;
}sistem;

void sistemPenjumlahan() {
	sistem struktur;
	printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
	scanf("%lf", &struktur.rAngkaPertama);
	printf("\tMasukkan Angka Kedua : ");
	scanf("%lf\033[0m", &struktur.rAngkaKedua);
	struktur.rHasil = struktur.rAngkaPertama + struktur.rAngkaKedua;
	printf("\n\n\t\033[1;34mHasil dari %.2lf + %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngkaPertama, struktur.rAngkaKedua, struktur.rHasil);
}

void sistemPengurangan(){
	sistem struktur;
	printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
	scanf("%lf", &struktur.rAngkaPertama);
	printf("\tMasukkan Angka Kedua : ");
	scanf("%lf\033[0m", &struktur.rAngkaKedua);
	struktur.rHasil = struktur.rAngkaPertama - struktur.rAngkaKedua;
	printf("\n\n\t\033[1;34mHasil dari %.2lf - %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngkaPertama, struktur.rAngkaKedua, struktur.rHasil);
}

void sistemPerkalian(){
	sistem struktur;
	printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
	scanf("%lf", &struktur.rAngkaPertama);
	printf("\tMasukkan Angka Kedua : ");
	scanf("%lf\033[0m", &struktur.rAngkaKedua);
	struktur.rHasil = struktur.rAngkaPertama * struktur.rAngkaKedua;
	printf("\n\n\t\033[1;34mHasil dari %.2lf x %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngkaPertama, struktur.rAngkaKedua, struktur.rHasil);
}

void sistemPembagian(){
	sistem struktur;
	printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
	scanf("%lf", &struktur.rAngkaPertama);
	printf("\tMasukkan Angka Kedua : ");
	scanf("%lf\033[0m", &struktur.rAngkaKedua);
	struktur.rHasil = struktur.rAngkaPertama / struktur.rAngkaKedua;
	printf("\n\n\t\033[1;34mHasil dari %.2lf : %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngkaPertama, struktur.rAngkaKedua, struktur.rHasil);
}

void noticeDefault(){
	printf("\t\033[1;32mMasukkan Dengan Benar\n");
	printf("\tSilahkan Coba Lagi.\033[0m\n");
	getch();
	system("CLS");
}

void gerakGaris(){
	int garis = 100;
	while(garis --){
		printf("=");
		Sleep(5);
	}
}

void sistemPembuka(){
	system("CLS");
	printf("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 1 [Kalkulator Sipaling Menu]\n\t");
	gerakGaris();
	printf("\n\tNama\t : Rivai\n");
	printf("\tNIM\t : 20230801290\n\t");
	gerakGaris();
	printf("\n\n");
	printf("\tWelcome, ");
	system("PAUSE");
}

void sistemInti(){
	sistem struktur;
	sistemPembuka();

Menu:
	system("CLS");
	printf("\t\033[0m\033[1;31m");
	gerakGaris();
	printf("\n\t\t\t\t\tAplikasi Kalkulator Ga Simpel Banget Dah\n\t");
	gerakGaris();
	printf("\n\t1. Penjumlahan '+'\033[0m\n");
	printf("\033[1;37m\t2. Pengurangan '-'\n");
	printf("\t3. Perkalian 'x'\n");
	printf("\t4. Pembagian ':'\n");
	printf("\t5. Keluar Aplikasi\033[0m\n");
	printf("\n");
	printf("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Atau Simbol : ");
	scanf("\n%s\033[0m", &struktur._Menu);

	if (struktur._Menu == '1' || struktur._Menu == '+'){
		sistemPenjumlahan();
    } else if (struktur._Menu == '2' || struktur._Menu == '-'){
        sistemPengurangan();
    } else if (struktur._Menu == '3' || struktur._Menu == 'x'){
        sistemPerkalian();
    } else if (struktur._Menu == '4' || struktur._Menu == ':'){
        sistemPembagian();
    } else if (struktur._Menu == '5'){
        return;
    } else {
    	noticeDefault();
		goto Menu;
	}
	
SubMenu:
	printf("\t\033[1;36m");
	gerakGaris();
	printf("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
	gerakGaris();
	printf("\n\t1. Kembali Ke Awal\n");
	printf("\t2. Keluar Aplikasi\033[0m\n");
	printf("\n");
	printf("\t\033[1;32mMasukkan Pilihan Menu : ");
	scanf("%d\033[0m", &struktur.subMenu);
	
	switch(struktur.subMenu) {
		default: noticeDefault();
				 goto SubMenu;
				 break;

		case 1:  goto Menu;
				 break;

		case 2:  return;
				 break;
	}
}

int main(void){
	sistemInti();
}
