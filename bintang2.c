/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main() {
    int n;
    printf("Masukkan Input Bilangan: ");
    scanf("%d", &n);

    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= i) {
            printf("*");
            j++;
        }
        printf("\n");
        i++;
    }

    i = n - 1;
    while (i >= 1) {
        int j = 1;
        while (j <= i) {
            printf("*");
            j++;
        }
        printf("\n");
        i--;
    }
    
    return 0;
}
