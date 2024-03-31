/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int _Menu, subMenu;
	int rAngkaPertama, rAngkaKedua, rHasil;
	int garis = 70;
	
	system("CLS");
	printf("Tugas Praktikum ALPRO 1 [Kalkulator Sipaling Menu]\n");
	while(garis--){
		printf("=");
		Sleep(5);
	}
	printf("\nNama : Rivai Munte\n");
	printf("NIM : 20230801290\n");
	while(garis--){
		printf("=");
		Sleep(5);
	}
	printf("\n\n");
	printf("Welcome, ");
	system("PAUSE");
	
Awal:
	system("CLS");
	printf("===========================================\n");
	printf("Aplikasi Kalkulator Simpel Banget Dah\n");
	printf("===========================================\n");
	
Menu:
	printf("1. Pertambahan\n");
	printf("2. Pengurangan\n");
	printf("3. Perkalian\n");
	printf("4. Pembagian\n");
	printf("5. Keluar Aplikasi\n");
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
				 rHasil = rAngkaPertama + rAngkaKedua;
				 printf("%d + %d = %d", rAngkaPertama, rAngkaKedua, rHasil);
				 break;	 

		case 2:  printf("\nMasukkan Angka Pertama : ");
				 scanf("%d", &rAngkaPertama);
				 printf("Masukkan Angka Kedua : ");
				 scanf("%d", &rAngkaKedua);
				 rHasil = rAngkaPertama - rAngkaKedua;
				 printf("%d - %d = %d", rAngkaPertama, rAngkaKedua, rHasil);
				 break;

		case 3:  printf("\nMasukkan Angka Pertama : ");
				 scanf("%d", &rAngkaPertama);
				 printf("Masukkan Angka Kedua : ");
				 scanf("%d", &rAngkaKedua);
				 rHasil = rAngkaPertama * rAngkaKedua;
				 printf("%d x %d = %d", rAngkaPertama, rAngkaKedua, rHasil);
				 break;

		case 4:  printf("\nMasukkan Angka Pertama : ");
				 scanf("%d", &rAngkaPertama);
				 printf("Masukkan Angka Kedua : ");
				 scanf("%d", &rAngkaKedua);
				 rHasil = rAngkaPertama / rAngkaKedua;
				 printf("%d : %d = %d", rAngkaPertama, rAngkaKedua, rHasil);
				 break;

		case 5:	 return 0;
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
