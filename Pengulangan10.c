/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main (){
	int batas;
	char Nama[100] = "Rivai Munte";
	printf("Masukkan Batas Perulangan : ");
	scanf("%d", &batas);
	while (batas--) {
        printf("%s\n", Nama);
    }
}
