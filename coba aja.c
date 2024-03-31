#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>

// Fungsi untuk memasukkan elemen-elemen matriks
void inputMatrix(gsl_matrix *mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double value;
            printf("Matriks[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &value);
            gsl_matrix_set(mat, i, j, value);
        }
    }
}

// Fungsi untuk mencetak matriks
void printMatrix(gsl_matrix *mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%g ", gsl_matrix_get(mat, i, j));
        }
        printf("\n");
    }
}

// Fungsi untuk menghitung invers matriks
void inverseMatrix(gsl_matrix *inputMat, int size) {
    // Matriks identitas untuk menyimpan hasil invers
    gsl_matrix *identityMat = gsl_matrix_alloc(size, size);
    gsl_matrix_set_identity(identityMat);

    // Salin matriks input
    gsl_matrix *copyMat = gsl_matrix_alloc(size, size);
    gsl_matrix_memcpy(copyMat, inputMat);

    // Invers matriks menggunakan dekomposisi LU
    gsl_permutation *p = gsl_permutation_alloc(size);
    int signum;
    gsl_linalg_LU_decomp(copyMat, p, &signum);
    gsl_linalg_LU_invert(copyMat, p, identityMat);

    // Cetak hasil invers
    printf("Inverse Matrix:\n");
    printMatrix(identityMat, size, size);

    // Bebaskan memori
    gsl_matrix_free(copyMat);
    gsl_matrix_free(identityMat);
    gsl_permutation_free(p);
}

int main() {
    int rows, cols;

    // Masukkan ukuran matriks
    printf("Masukkan jumlah baris matriks: ");
    scanf("%d", &rows);
    printf("Masukkan jumlah kolom matriks: ");
    scanf("%d", &cols);

    // Matriks input
    gsl_matrix *inputMat = gsl_matrix_alloc(rows, cols);

    // Masukkan elemen matriks
    printf("Masukkan elemen matriks:\n");
    inputMatrix(inputMat, rows, cols);

    // Cetak matriks input
    printf("Matriks Input:\n");
    printMatrix(inputMat, rows, cols);

    // Periksa apakah matriks persegi
    if (rows == cols) {
        inverseMatrix(inputMat, rows);
    } else {
        printf("Matriks harus berbentuk persegi untuk diinvers.\n");
    }

    // Bebaskan memori
    gsl_matrix_free(inputMat);

    return 0;
}

