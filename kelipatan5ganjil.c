/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cekBilangan, cekKelipatan5, cekGanjil;
	printf("===========================================\n");
	printf("Aplikasi Pengecek Kelipatan Lima & Ganjil\n");
	printf("===========================================\n");
	
	printf("Masukan Bilangan : ");
	scanf("%d", &cekBilangan);
	
	cekGanjil = cekBilangan % 2;
	cekKelipatan5 = cekBilangan % 5;
	
	// Disini itu kelipatan 5
	if (cekKelipatan5 == 0){
		if(cekGanjil == 0){
			printf("Tidak Ganjil & Kelipatan 5\n");
		}
		else if (cekGanjil == 1){
			printf("Ganjil & Kelipatan 5\n");
		}
	}
	// Kalo Disini itu bukan kelipatan 5
	else if (cekKelipatan5 == 1){
		if(cekGanjil == 0){
			printf("Tidak Ganjil & Tidak Kelipatan");
		}
		else if (cekGanjil == 1){
			printf("Ganjil & Tidak Kelipatan 5\n");
		}
	}
	else if (cekKelipatan5 == 1 && cekGanjil == 0 ){
		printf("Error");
	}
}
