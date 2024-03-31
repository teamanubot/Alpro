/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

typedef struct{
	int rAngkaPertama, rAngkaKedua, rAngkaKetiga, diskriminan;
	float x1, x2;
	int _Menu, subMenu;
}sistem;

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

void sistemPenentuAkar(){
	sistem struktur;
	printf("\n\n\tFormat persamaan: ax^2 + bx + c = 0 \n");
	printf("\n\tInput nilai a: ");
	scanf("%d", &struktur.rAngkaPertama);
	printf("\n\tInput nilai b: ");
	scanf("%d", &struktur.rAngkaKedua);
	printf("\n\tInput nilai c: ");
	scanf("%d", &struktur.rAngkaKetiga);
	struktur.diskriminan = (struktur.rAngkaKedua*struktur.rAngkaKedua)-(4*struktur.rAngkaPertama*struktur.rAngkaKetiga);
	printf("\n\tDiskriminan = %d", struktur.diskriminan);
	if (struktur.diskriminan > 0){
 		struktur.x1 = (-struktur.rAngkaKedua + sqrt(struktur.diskriminan)) / (2*struktur.rAngkaPertama);
    	struktur.x2 = (-struktur.rAngkaKedua - sqrt(struktur.diskriminan)) / (2*struktur.rAngkaPertama);
 		printf("\033[0m\033[1;34m\n\n\tx1 = %.2f", struktur.x1);
    	printf("\n\tx2 = %.2f", struktur.x2);
    	printf("\n\t(akar real dan berbeda)\033[0m\n\n");
  	} else if (struktur.diskriminan == 0){
 		struktur.x1 = struktur.x2 = (-struktur.rAngkaKedua + sqrt(struktur.diskriminan)) / (2*struktur.rAngkaPertama);
 		printf("\033[0m\033[1;34m\n\n\tx1 = %.2f", struktur.x1);
    	printf("\n\tx2 = %.2f", struktur.x2);
    	printf("\n\t(akar real dan sama)\033[0m\n\n");
  	} else if (struktur.diskriminan < 0) {
  		printf("\033[0m\033[1;34m\n\n\tx1 = %.2f", struktur.x1);
    	printf("\n\tx2 = %.2f", struktur.x2);
    	printf("\n\t(akar tidak real / imajiner)\033[0m\n\n");
    } else {
			printf("ERROR");
	}
}

void sistemPembuka(){
	system("CLS");
	printf("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 1 [Penentu Akar Kuadrat Menu]\n\t");
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
	printf("\n\t\t\t\t\tAplikasi Penentu Akar Kuadrat\033[0m\033[1;37m\n\t");
	gerakGaris();
	printf("\n\t1. Mulai Aplikasi\n");
	printf("\t2. Keluar Aplikasi\033[0m\n");
	printf("\n");
	printf("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Atau Simbol : ");
	scanf("\n%s\033[0m", &struktur._Menu);

	if (struktur._Menu == '1'){
		sistemPenentuAkar();
	} else if (struktur._Menu == '2'){
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
	scanf("\n%s\033[0m", &struktur.subMenu);
	
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
