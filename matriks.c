#include <stdio.h>

void isiMatriks(int matriks[][100], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Masukkan elemen matriks [%d][%d] : ", i, j);
            scanf("%d", &matriks[i][j]);
        }
    }
}

void tambahMatriks(int matriks1[][100], int matriks2[][100], int hasil[][100], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
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
    int baris1, kolom1, baris2, kolom2;

    printf("Masukkan jumlah baris matriks pertama : ");
    scanf("%d", &baris1);
    printf("Masukkan jumlah kolom matriks pertama : ");
    scanf("%d", &kolom1);

    printf("\nMasukkan jumlah baris matriks kedua : ");
    scanf("%d", &baris2);
    printf("Masukkan jumlah kolom matriks kedua : ");
    scanf("%d", &kolom2);

    if (baris1 != baris2 || kolom1 != kolom2) {
        printf("Operasi penjumlahan tidak dapat dilakukan karena ukuran matriks berbeda.\n");
        return 1;
    }

    int matriks1[100][100], matriks2[100][100], hasil[100][100];

    printf("\nMasukkan elemen matriks pertama :\n");
    isiMatriks(matriks1, baris1, kolom1);

    printf("\nMasukkan elemen matriks kedua :\n");
    isiMatriks(matriks2, baris2, kolom2);

    // Menjumlahkan dua matriks
    tambahMatriks(matriks1, matriks2, hasil, baris1, kolom1);

    // Menampilkan matriks pertama
    printf("\n\nMatriks Pertama :\n");
    tampilMatriks(matriks1, baris1, kolom1);
	printf("\n  +\n");
    // Menampilkan matriks kedua
    printf("\n\nMatriks Kedua :\n");
    tampilMatriks(matriks2, baris2, kolom2);

    // Menampilkan hasil penjumlahan
    printf("\n  =\n\n");
    tampilMatriks(hasil, baris1, kolom1);

    return 0;
}
