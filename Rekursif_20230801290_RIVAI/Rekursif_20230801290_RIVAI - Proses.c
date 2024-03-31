#include "Rekursif_20230801290_RIVAI - Pustaka.h"

void gerakGaris(char *kata, int jumlah) {
    int garis = jumlah;
    while (garis--) {
        printf("%s", kata);
        Sleep(5);
    }
}

void systemClose() {
	#ifdef _WIN32
    	system("CLS");
	#else
    	system("clear");
	#endif
}

void systemPause() {
    #ifdef _WIN32
        system("pause");
    #else
        system("read -p 'Press Enter to continue...' key");
    #endif
}

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
                if (i == 0 && buffer[i] == '-') {
                    continue;
                }
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

void getValidString(char input[]) {
    int valid = 0;
    do {
        if (fgets(input, 100, stdin) != NULL) {
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
                len--;
            }
			int hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(input[i])) {
                    hanyaEnter = 0;
                    break;
                }
            }
            if (hanyaEnter) {
                printf("Masukkan hanya huruf : ");
                continue;
            }
            valid = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(input[i]) && !isalpha(input[i])) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Masukkan hanya huruf dan spasi : ");
            }
        }
    } while (!valid);
}

void kapitalAwal(char str[]) {
    int i;
    int len = strlen(str);
    int wordStart = 1;
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (wordStart) {
                str[i] = toupper(str[i]);
                wordStart = 0;
            } else {
                str[i] = tolower(str[i]);
            }
        } else {
            wordStart = 1;
        }
    }
}

void noticeDefault() {
    printf("Masukkan Dengan Benar\n");
    printf("Silahkan Coba Lagi.\n");
    getch();
    systemClose();
}

void noticeExit(){
	systemClose();
    printf("Terima Kasih Telah Menggunakan >_<");
    exit;
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

void mainPermutasi() {
	systemClose();
	int n, r;
    printf("==============================\n");
    printf("PERMUTASI\n");
	printf("==============================\n");
	printf("Masukkan nilai n : ");
	n = getValidInt();
	printf("Masukkan nilai r : ");
	r = getValidInt();
	printf("Rumus Permutasi:\n");
	printf("____n!___\n");
	printf("( n - r ) !\n\n");
	printf("Faktorisasi n dengan nilai %d :\n", n);
	factorization(n);
	printf("\nFaktorisasi (n-r) dengan nilai %d :\n", n - r);
	factorization(n - r);
	printf("\nMaka Sama Dengan :\n");
	printf("%llu / %llu\n", factorial(n), factorial(n - r));
	printf("\nMaka Hasil Kombinasi dari %dP%d adalah %llu\n\n\n", n, r, permutation(n, r));
}

void mainKombinasi() {
	systemClose();
	int n, r;
	printf("==============================\n");
	printf("KOMBINASI\n");
	printf("==============================\n");
	printf("Masukkan nilai n : ");
	n = getValidInt();
	printf("Masukkan nilai r : ");
	r = getValidInt();
	printf("Faktorisasi n dengan nilai %d    :\n", n);
	factorization(n);
	printf("\nFaktorisasi (n-r) dengan nilai %d       :\n", n - r);
	factorization(n - r);
	printf("\nMaka Sama Dengan :\n");
	printf("%llu / %llu\n", permutation(n, r), factorial(r));
	printf("\nMaka Hasil Kombinasi dari %dC%d adalah %llu\n\n\n", n, r, combination(n, r));
}

void mainFibonacci() {
	systemClose();
	long long int n;
    printf("Masukkan nilai n : ");
    n = getValidInt();
	if (n < 0) {
		printf("Input tidak valid. Harap masukkan bilangan bulat non-negatif.\n\n\n");
	} else {
		printf("Nilai Fibonacci dari %lld adalah: %llu\n\n\n", n, fibonacci(n));
	}
}

void sistemMenu() {
	char _Menu[100];
	systemClose();
    gerakGaris("=", 100);
    printf("\n\t\t\t\tAplikasi Beta Sudah Dekat V9\n");
    gerakGaris("=", 100);
    printf("\n1. Permutasi\n");
    printf("2. Kombinasi\n");
    printf("3. Fibonacci\n");
    printf("4. Keluar Aplikasi\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;

    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "permutasi") == 0) {
    	mainPermutasi();
    	sistemSubMenu();
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "kombinasi") == 0) {
        mainKombinasi();
        sistemSubMenu();
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "fibonacci") == 0) {
        mainFibonacci();
        sistemSubMenu();
	} else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
        noticeDefault();
        sistemMenu();
    }
}

void sistemSubMenu() {
	char subMenu[100];
    gerakGaris("=", 100);
    printf("\n\t\t\t\t\t   Pilihan Menu\n");
    gerakGaris("=", 100);
    printf("\n1. Kembali Ke Awal\n");
    printf("2. Keluar Aplikasi\033[0m\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(subMenu, sizeof(subMenu), stdin);
    subMenu[strcspn(subMenu, "\n")] = 0;

    if (strcmp(subMenu, "1") == 0 || strcasecmp(subMenu, "kembali ke awal") == 0) {
        sistemMenu();
    } else if (strcmp(subMenu, "2") == 0 || strcasecmp(subMenu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
        noticeDefault();
        sistemSubMenu();
    }
}
