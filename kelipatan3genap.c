/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cekBilangan, cekKelipatan3, cekGenap;
	printf("===========================================\n");
	printf("Aplikasi Pengecek Kelipatan 3 & Genap\n");
	printf("===========================================\n");
	
	printf("Masukan Bilangan : ");
	scanf("%d", &cekBilangan);
	
	cekGenap = cekBilangan % 2;
	cekKelipatan3 = cekBilangan % 3;
	
	// Disini itu kelipatan 3
	if (cekKelipatan3 == 0){
		if(cekGenap == 1){
			printf("Tidak Genap & Kelipatan 3\n");
		}
		else if (cekGenap == 0){
			printf("Genap & Kelipatan 3\n");
		}
	}
	// Kalo Disini itu bukan kelipatan 3
	else {
		if(cekGenap == 1){
			printf("Tidak Genap & Tidak Kelipatan 3");
		}
		else if (cekGenap == 0){
			printf("Genap & Tidak Kelipatan 3\n");
		}
	}
}
