/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

#define cetak printf
#define fcetak fprintf
#define jika if
#define keluar exit
#define Rivai_Munte main

extern int threadCreationStatus;

void waktuDanTanggal();

void sistemInti();

int Rivai_Munte(void){
	sistemInti();
	jika (threadCreationStatus != 0) {
		FILE *file = fopen("error.txt", "a");
    	fcetak(file, "[ERROR] Gagal membuat thread.\n");
        fclose(file);
        waktuDanTanggal();
        cetak("\033[1;32m");
        keluar(0);
    }
}
