/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main (){
	int i, j, batas;
	printf("Masukkan Input Bilangan : ");
	scanf("%d", &batas);
	while (i<=batas) {
		j=1;
		while(j<=i){
			printf("*", j);
			j++;
		}
		printf("\n",i);
		i++;
    }
}
