/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int getValidInt() {
	char buffer[100];
    int hanyaEnter, validInput, value;
    do {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
                len--;
            }
            hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(buffer[i])) {
                    hanyaEnter = 0;
                    break;
                }
            }
            if (hanyaEnter) {
                printf("Masukkan Angka : ");
                continue;
            }
            validInput = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isdigit(buffer[i])) {
                    validInput = 0;
                    break;
                }
            }
            if (validInput) {
                sscanf(buffer, "%d", &value);
            } else {
                printf("Masukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    } while (!validInput);
    return value;
}

void main() {
    int n;
    printf("Masukkan Banyak Angka : ");
    n = getValidInt();
    int a[n];
    for (int i = 1; i <= n; i++) {
        printf("Masukkan Angka Ke-%d : ", i);
        a[i] = getValidInt();
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            printf("\nGenap Array Ke-%d Adalah : %d", i, a[i]);
        }
    }
    getch();
}
