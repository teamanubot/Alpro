/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main() {
	int i, a[10];
	for (i = 1; i <= 5; i++) { //Perulangan untuk pegambilan data
		printf("A[%d] : ", i);
		scanf("%d", &a[i]);
	}
	printf("\n\n\n");
	for(i = 1; i <= 5; i++) { //Perulangan untuk menampilkan data
		printf("A[%d] : %d \n", i, a[i]);
	}
	getch();
}
