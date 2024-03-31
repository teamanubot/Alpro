/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int tanggal;
	char bulan[20];
	int tahun;
}waktu;

int main(){
	waktu kalender;
	
	printf("Masukkan Tanggal	: ");
	scanf("%d", &kalender.tanggal);
	
	printf("Masukkan Bulan		: ");
	scanf("%s", &kalender.bulan);
	
	printf("Masukkan Tahun		: ");
	scanf("%d", &kalender.tahun);
	
	printf("\n");
	printf("Tanggal Hari ini : %d %s %d", kalender.tanggal, kalender.bulan, kalender.tahun);
	
	getch();
	return 0;
}
