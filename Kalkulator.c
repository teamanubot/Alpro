/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int _Menu, subMenu;
	int rAngkaPertama, rAngkaKedua, rHasil1, rHasil2, rHasil3, rHasil4;
	
	system("CLS");
	printf("Tugas Praktikum ALPRO 1 [Kalkulator Sipaling Menu]\n");
	printf("===========================================\n");
	printf("Nama : Rivai\n");
	printf("NIM : 20230801290\n");
	printf("===========================================\n");
	printf("\n");
	printf("Welcome, ");
	system("PAUSE");
	
Awal:
	system("CLS");
	printf("===========================================\n");
	printf("Aplikasi Kalkulator Simpel Banget Dah\n");
	printf("===========================================\n");
	
Menu:
	printf("1. Memulai Kalkulator Simpel Banget Dah\n");
	printf("2. Keluar Aplikasi\n");
	printf("\n");
	printf("Masukkan Pilihan Menu : ");
	scanf("%d", &_Menu);
		
	switch(_Menu){
		default: printf("Masukkan Dengan Benar\n");
				 printf("Silahkan Coba Lagi.\n");		 
				 getch();
				 break;

		case 1:  printf("\nMasukkan Angka Pertama : ");
				 scanf("%d", &rAngkaPertama);
				 printf("Masukkan Angka Kedua : ");
				 scanf("%d", &rAngkaKedua);
				 rHasil1 = rAngkaPertama + rAngkaKedua;
				 rHasil2 = rAngkaPertama - rAngkaKedua;
				 rHasil3 = rAngkaPertama * rAngkaKedua;
				 rHasil4 = rAngkaPertama / rAngkaKedua;
				 printf("1. %d + %d = %d\n2. %d - %d = %d\n3. %d x %d = %d\n4. %d : %d = %d\n", rAngkaPertama, rAngkaKedua, rHasil1, rAngkaPertama, rAngkaKedua, rHasil2, rAngkaPertama, rAngkaKedua, rHasil3, rAngkaPertama, rAngkaKedua, rHasil4);
				 printf("Pemrograman Ilmu Yang Menyenangkan ~\n");
				 break;
				 
		case 2:	 return 0;
				 break;
	}

SubMenu:
	printf("\n");
	printf("====================\n");
	printf("Pilihan Menu\n");
	printf("====================\n");
	printf("1. Kembali Ke Awal\n");
	printf("2. Keluar Aplikasi\n");
	printf("\n");
	printf("Masukkan Pilihan Menu : ");
	scanf("%d", &subMenu);
	
	switch(subMenu) {
		default: printf("Pilihan Menu Tidak Ada\n");
				 printf("Silahkan Coba Lagi\n");
				 goto SubMenu;
				 break;

		case 1: goto Awal;
				break;

		case 2: return 0;
				break;
	}
}
