/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>

int main() {
    int n;
    printf("Masukkan Input Bilangan: ");
    scanf("%d", &n);

    int i = 1;
    while (i <= n) {
        int spasi = n - i;
        int j = 1;

        while (spasi > 0) {
            printf("_");
            spasi--;
        }

        while (j <= i) {
            printf("*");
            j++;
        }

        printf("\n");
        i++;
    }

    return 0;
}

