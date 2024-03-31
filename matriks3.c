#include <stdio.h>

void isiMatriks(int matriks[][100], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Masukkan elemen matriks <%d, %d> : ", i, j);
            scanf("%d", &matriks[i][j]);
        }
    }
}

void transposeMatriks(int matriks[][100], int transpose[][100], int baris, int kolom) {
    for (int i = 0; i < kolom; i++) {
        for (int j = 0; j < baris; j++) {
            transpose[i][j] = matriks[j][i];
        }
    }
}

void tampilMatriks(int matriks[][100], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
    	printf("[ ");
        for (int j = 0; j < kolom; j++) {
            printf("%d ", matriks[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

int main() {
    int baris, kolom;

    printf("Masukkan jumlah baris matriks : ");
    scanf("%d", &baris);
    printf("Masukkan jumlah kolom matriks : ");
    scanf("%d", &kolom);

    int matriks[100][100], transpose[100][100];

    printf("\nMasukkan elemen matriks :\n");
    isiMatriks(matriks, baris, kolom);

    // Menghitung transpose matriks
    transposeMatriks(matriks, transpose, baris, kolom);

    // Menampilkan matriks asli
    printf("\nMatriks Asli :\n");
    tampilMatriks(matriks, baris, kolom);

    // Menampilkan transpose matriks
    printf("\nTranspose Matriks :\n");
    tampilMatriks(transpose, kolom, baris);

    return 0;
}
