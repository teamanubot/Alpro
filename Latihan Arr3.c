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

int main() {
    int i, n, angka, count = 0;
    printf("Masukkan Banyak Angka : ");
    n = getValidInt();
    int a[n];
    for (i = 0; i < n; i++) {
        printf("Masukkan Angka Ke-%d : ", i + 1);
        a[i] = getValidInt();
    }
    for (i = 0; i < n; i++) {
        if (a[i] == 5) {
            count++;
        }
    }
    printf("\nJumlah Inputan 5 Ada : %d", count);
    if (count == 0) {
        printf("Tidak ada");
    }
    printf("\nArray Berisi Angka 5 Ada Di : ");
    for (i = 0; i < n; i++) {
        if (a[i] == 5) {
            printf("%d", i + 1);
            if (count > 1 && i < n - count) {
                printf(", ");
            }
        }
    }
    printf("\n");
    return 0;
}
