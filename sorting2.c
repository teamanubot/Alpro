#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    printf("Masukkan Jumlah Angka Yang Diinginkan: ");
    scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Masukkan Angka ke-%d: ", i);
        scanf("%d", &numbers[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    int average = sum / n;
    qsort(numbers, n, sizeof(int), compare);
    printf("\nRerata: %d\n\n", average);
    printf("Setelah Diurutkan:\n");
    int i;
    for (i = 0; i < n && numbers[i] <= average; i++) {
        printf("angka ke-%d : %d\n", i, numbers[i]);
    }
    if (i < n) {
        printf("------------------------------\n");
        for (; i < n; i++) {
            printf("angka ke-%d : %d\n", i, numbers[i]);
        }
    }
    free(numbers);
    return 0;
}

