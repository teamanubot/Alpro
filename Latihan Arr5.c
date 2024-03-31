/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void sistemMenu();

void sistemSubMenu();

void gerakGaris() {
    int garis = 100;
    while (garis--) {
        printf("=");
        Sleep(5);
    }
}

void noticeDefault() {
    printf("Masukkan Dengan Benar\n");
    printf("Silahkan Coba Lagi.\n");
    getch();
    system("CLS");
}

void noticeExit(){
	system("CLS");
    printf("Terima Kasih Telah Menggunakan >_<");
    exit;
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
    int valid = 0, hanyaEnter;
    do {
        if (fgets(input, 100, stdin) != NULL) {
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
                len--;
            }
            hanyaEnter = 1;
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

void arrRata() {
	system("CLS");
	int i, n, angka = 0;
	printf("Masukkan Banyak Angka : ");
	scanf("%d", &n);
	int a[n];
	for (i = 1; i <= n; i++) {
		printf("A[%d] : ", i);
		scanf("%d", &a[i]);
		angka += a[i];
	}
	printf("\n\n\n");
	for(i = 1; i <= n; i++) {
		printf("A[%d] : %d \n", i, a[i]);
	}
	float sum = angka;
	sum /= n;
	printf("Rata Nilai Adalah : %.2f\n\n", sum);
}

void arrGenap() {
	system("CLS");
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
    printf("\n\n");
}

void arrLima() {
	system("CLS");
    int i, n, angka, count = 0;
    system("CLS");
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
    printf("\n\n");
}

void arrMinMax() {
	system("CLS");
    int n, max, min;
    printf("Masukkan Banyak Angka : ");
    n = getValidInt();
    int a[n];
    for (int i = 1; i <= n; i++) {
        printf("Masukkan Angka Ke-%d : ", i);
        a[i] = getValidInt();
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    printf("\nNilai Maximumnya Adalah : %d\n", max);
    printf("Nilai Minimumnya Adalah : %d\n\n", min);
}

void arrVokal() {
    char string[100];
    int vokal[5] = {0};
    system("CLS");
    printf("Masukkan sebuah string : ");
    getValidString(string);

    for (int i = 0; i < strlen(string); i++) {
        char ch = string[i];
        if (ch == 'a' || ch == 'A') {
            vokal[1]++;
        } else if (ch == 'i' || ch == 'I') {
            vokal[2]++;
        } else if (ch == 'u' || ch == 'U') {
            vokal[3]++;
        } else if (ch == 'e' || ch == 'E') {
            vokal[4]++;
        } else if (ch == 'o' || ch == 'O') {
            vokal[5]++;
        }
    }

    printf("\nJumlah huruf vokal dalam string :\n");
    if (vokal[1] > 0) {
    	printf("a = %d\n", vokal[1]);
	}
	if (vokal[2] > 0) {
		printf("i = %d\n", vokal[2]);
	}
	if (vokal[3] > 0) {
		printf("u = %d\n", vokal[3]);
	}
	if (vokal[4] > 0) {
		printf("e = %d\n", vokal[4]);
	}
	if (vokal[5] > 0) {
		printf("o = %d\n", vokal[5]);
	}
	if (vokal[1] == 0 && vokal[2] == 0 && vokal[3] == 0 && vokal[4] == 0 && vokal[5] == 0) {
		printf("Tidak Ada Huruf Vokal");
	}
	printf("\n\n");
}

void sistemMenu(){
	char _Menu[100];
	system("CLS");
    gerakGaris();
    printf("\n\t\t\t\tAplikasi Beta Sudah Dekat V5\n");
    gerakGaris();
    printf("\n1. Nilai Rata-Rata Dengan Array\n");
    printf("2. Nilai Genap Pada Array\n");
    printf("3. Banyak Angka 5 Pada Array\n");
    printf("4. Nilai Max & Nilai Min Dengan Array\n");
    printf("5. Vokal Array\n");
    printf("6. Keluar Aplikasi\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;

    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "nilai rata-rata dengan array") == 0) {
    	arrRata();
    	sistemSubMenu();
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "nilai genap pada array") == 0) {
        arrGenap();
        sistemSubMenu();
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "banyak angka 5 pada array") == 0) {
		arrLima();
        sistemSubMenu();
    } else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "nilai max & nilai min dengan array") == 0) {
    	arrMinMax();
    	sistemSubMenu();
    } else if (strcmp(_Menu, "5") == 0 || strcasecmp(_Menu, "vokal array") == 0) {
    	arrVokal();
    	sistemSubMenu();
	} else if (strcmp(_Menu, "6") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
        noticeDefault();
        sistemMenu();
    }
}

void sistemSubMenu(){
	char subMenu[100];
    gerakGaris();
    printf("\n\t\t\t\t\t   Pilihan Menu\n");
    gerakGaris();
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

int main() {
    sistemMenu();
}
