#include <stdio.h>
#define MAX 10000

unsigned long long factorial(int n);
unsigned long long permutation(int n, int r);
unsigned long long combination(int n, int r);
unsigned long long memo[MAX];

unsigned long long fibonacci(long long int n) {
    if (n == 0 || n == 1) {
        return n;
    } else if (memo[n] != 0) {
        return memo[n];
    } else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
}

void factorization(int num);

int main() {
    int choice;

    do {
        printf("\nAplikasi Rekursif\n");
        printf("_________________\n");
        printf("Menu :\n");
        printf("[1] Permutasi\n");
        printf("[2] Kombinasi\n");
        printf("[3] Fibonacci\n");
        printf("[4] Keluar\n");
        printf("\nMasukkan Pilihan [1-4]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int n, r;

                    printf("==============================\n");
                    printf("PERMUTASI\n");
                    printf("==============================\n");
                    printf("Masukkan nilai n: ");
                    scanf("%d", &n);
                    printf("Masukkan nilai r: ");
                    scanf("%d", &r);

                    printf("Rumus Permutasi:\n");
                    printf("____n!___\n");
                    printf("( n - r ) !\n\n");
                    printf("Faktorisasi n dengan nilai %d :\n", n);
                    factorization(n);

                    printf("\nFaktorisasi (n-r) dengan nilai %d :\n", n - r);
                    factorization(n - r);

                    printf("\nMaka Sama Dengan :\n");
                    printf("%llu / %llu\n", factorial(n), factorial(n - r));

                    printf("\nMaka Hasil Kombinasi dari %dP%d adalah %llu\n", n, r, permutation(n, r));
                }
                break;

            case 2:
                {
                    int n, r;
                    printf("Masukkan nilai n: ");
                    scanf("%d", &n);
                    printf("Masukkan nilai r: ");
                    scanf("%d", &r);

                    printf("==============================\n");
                    printf("KOMBINASI\n");
                    printf("==============================\n");
                    printf("Masukan Nilai n : %d\n", n);
                    printf("Masukan Nilai r : %d\n\n");

                    printf("Faktorisasi n dengan nilai %d    :\n", n);
                    factorization(n);

                    printf("\nFaktorisasi (n-r) dengan nilai %d       :\n", n - r);
                    factorization(n - r);

                    printf("\nMaka Sama Dengan :\n");
                    printf("%llu / %llu\n", permutation(n, r), factorial(r));

                    printf("\nMaka Hasil Kombinasi dari %dC%d adalah %llu\n", n, r, combination(n, r));
                }
                break;

            case 3:
                {
                    long long int n;
    				printf("Masukkan nilai n: ");
    				scanf("%lld", &n);

    				if (n < 0) {
        			printf("Input tidak valid. Harap masukkan bilangan bulat non-negatif.\n");
    				} else {
        				printf("Nilai Fibonacci dari %lld adalah: %llu\n", n, fibonacci(n));
    				}
                }
                break;

            case 4:
                printf("Terima kasih, keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan masukkan angka antara 1 hingga 4.\n");
        }

    } while (choice != 4);

    return 0;
}

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

unsigned long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

unsigned long long combination(int n, int r) {
    return permutation(n, r) / factorial(r);
}


void factorization(int num) {
    printf("___________________________\n");
    printf("Begin Factorization Process\n");
    printf("---------------------------\n");

    printf("%d !\n", num);

    unsigned long long sum_n = 1;
    unsigned long long total = 0;

    for (int i = 1; i <= num; i++) {
        unsigned long long sum_j = 1;
        for (int j = num; j >= i; j--) {
            printf("%d", j);
            sum_j *= j;
            if (j != i) {
                printf(" * ");
            }
        }
        printf(" = %llu\n", sum_j);
        total += sum_j;
        sum_n *= i;
    }

    printf("\nPenjumlahan Hasil :\n");
    for (int i = 1; i <= num; ++i) {
        unsigned long long current_sum_j = 1;
        for (int j = num; j >= i; j--) {
            current_sum_j *= j;
        }
        printf("%llu", current_sum_j);

        if (i < num) {
            printf(" + ");
        } else {
            printf(" = %llu\n", total);
        }
    }

    printf("___________________________\n");
    printf("End Factorization Process\n");
    printf("---------------------------\n");
}
