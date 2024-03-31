/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cekBilangan, cekKelipatan3;
	printf("===========================================\n");
	printf("Aplikasi Pengecek Kelipatan Tiga\n");
	printf("===========================================\n");
	
	printf("Masukan Bilangan : ");
	scanf("%d", &cekBilangan);
	
	cekKelipatan3 = cekBilangan % 3;
	
	// Disini itu kelipatan 3
	if (cekKelipatan3 == 0){
		printf("Bilangan merupakan kelipatan 3\n");
	}
	else {
		printf("Bilangan bukan merupakan kelipatan 3\n");
	}
}
