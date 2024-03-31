#include <stdio.h>

int main() {
    int matriks[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    printf("Matriks:\n");
    for (int baris = 0; baris < 3; ++baris) {
        for (int kolom = 0; kolom < 3; ++kolom) {
            printf("%d ", matriks[baris][kolom]);
        }
        printf("\n");
    }

    int target;
    printf("Masukkan elemen yang dicari: ");
    scanf("%d", &target);

    int ditemukan = 0;
    int baris, kolom;

    for (baris = 0; baris < 3; ++baris) {
        for (kolom = 0; kolom < 3; ++kolom) {
            if (matriks[baris][kolom] == target) {
                ditemukan = 1;
                break;
            }
        }

        if (ditemukan) {
            break;
        }
    }

    if (ditemukan) {
        printf("Elemen %d ditemukan pada posisi (%d, %d).\n", target, baris + 1, kolom + 1);
    } else {
        printf("Elemen %d tidak ditemukan dalam matriks.\n", target);
    }

    return 0;
}
