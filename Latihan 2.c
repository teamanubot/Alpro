/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	char nama[20];
	char nim[20];
	char alamat [20];
	
	printf("Masukkan Nama	: ");
	fflush(stdin);
	gets(nama);
	
	printf("Masukkan NIM	: ");
	scanf("%s", &nim);
	
	printf("Masukkan Alamat	: ");
	fflush(stdin);
	gets(alamat);
	
	printf("Nama : %s \n", nama);
	printf("NIM : %s \n", nim);
	printf("Alamat : %s \n", alamat);
	
	getch();
	return 0;
}
