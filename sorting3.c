#include <stdio.h>

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, int sortedIndices[]) {
    for (int i = 0; i < n / 2 - 1; i++) {
        for (int j = 0; j < n / 2 - i - 1; j++) {
            if (arr[sortedIndices[j]] < arr[sortedIndices[j + 1]]) {
                tukar(&arr[sortedIndices[j]], &arr[sortedIndices[j + 1]]);
                tukar(&sortedIndices[j], &sortedIndices[j + 1]);
            }
        }
    }
}

void bagiKelas(int jumlahKelas, int jumlahData, int data[]) {
    int nilaiKelas[jumlahData / 2];
    for (int i = 0, j = 0; i < jumlahData; i += 2, j++) {
        nilaiKelas[j] = data[i] + data[i + 1];
    }
    int sortedIndices[jumlahData / 2];
    for (int i = 0; i < jumlahData / 2; i++) {
        sortedIndices[i] = i;
    }
    bubbleSort(nilaiKelas, jumlahData, sortedIndices);
    for (int i = 0; i < jumlahKelas; i++) {
        printf("\nKelas X-%d :", i + 1);
        for (int j = i; j < jumlahData / 2; j += jumlahKelas) {
            printf("\n%d | %d", data[sortedIndices[j] * 2], data[sortedIndices[j] * 2 + 1]);
        }
        if (i < jumlahKelas - 1) {
            printf("\n------------------------\n");
        }
    }
}

int main() {
    int jumlahKelas, jumlahData;

    printf("Masukkan Banyak Kelas: ");
    scanf("%d", &jumlahKelas);

    printf("Masukkan Banyak Data: ");
    scanf("%d", &jumlahData);

    jumlahData *= 2;
    int data[jumlahData];

    printf("Masukkan %d pasang data:\n", jumlahData / 2);
    for (int i = 0; i < jumlahData; i++) {
        printf("Data ke %d : ", i + 1);
        scanf("%d", &data[i]);
    }

    bagiKelas(jumlahKelas, jumlahData, data);

    return 0;
}

