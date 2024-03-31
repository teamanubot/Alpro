/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main() {
	int i, n, angka = 0;
	printf("Masukkan Banyak Angka : ");
	scanf("%d", &n);
	int a[n];
	for (i = 1; i <= n; i++) { //Perulangan untuk pegambilan data
		printf("A[%d] : ", i);
		scanf("%d", &a[i]);
		angka += a[i];
	}
	printf("\n\n\n");
	for(i = 1; i <= n; i++) { //Perulangan untuk menampilkan data
		printf("A[%d] : %d \n", i, a[i]);
	}
	float sum = angka;
	sum /= n;
	printf("Rata Nilai Adalah : %.2f", sum);
	getch();
}
