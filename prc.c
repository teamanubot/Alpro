#include "pustaka.h"

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

void isiMatriks(int matriks[][100], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Masukkan elemen matriks [%d][%d] : ", i, j);
            matriks[i][j] = getValidInt();
        }
    }
}

void isiMatriks2(int matriks[][100], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("Masukkan elemen matriks <%d, %d> : ", i, j);
            matriks[i][j] = getValidInt();
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

void kurangMatriks(int matriks1[][100], int matriks2[][100], int hasil[][100], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
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

void matriks1() {
	system("CLS");
	int baris1, kolom1, baris2, kolom2;

    printf("Masukkan jumlah baris matriks pertama : ");
    baris1 = getValidInt();
    printf("Masukkan jumlah kolom matriks pertama : ");
    kolom1 = getValidInt();

    printf("\nMasukkan jumlah baris matriks kedua : ");
    baris2 = getValidInt();
    printf("Masukkan jumlah kolom matriks kedua : ");
    kolom2 = getValidInt();

    if (baris1 != baris2 || kolom1 != kolom2) {
        printf("Operasi penjumlahan tidak dapat dilakukan karena ukuran matriks berbeda.\n");
        exit;
    }

    int matriks1[100][100], matriks2[100][100], hasil[100][100];

    printf("\nMasukkan elemen matriks pertama :\n");
    isiMatriks(matriks1, baris1, kolom1);

    printf("\nMasukkan elemen matriks kedua :\n");
    isiMatriks(matriks2, baris2, kolom2);

    tambahMatriks(matriks1, matriks2, hasil, baris1, kolom1);

    printf("\n\nMatriks Pertama :\n");
    tampilMatriks(matriks1, baris1, kolom1);
	printf("\n  +\n");
    printf("\n\nMatriks Kedua :\n");
    tampilMatriks(matriks2, baris2, kolom2);

    printf("\n  =\n\n");
    tampilMatriks(hasil, baris1, kolom1);
    printf("\n\n");
}

void matriks2() {
	system("CLS");
    int baris1, kolom1, baris2, kolom2;

    printf("Masukkan jumlah baris matriks pertama : ");
    baris1 = getValidInt();
    printf("Masukkan jumlah kolom matriks pertama : ");
    kolom1 = getValidInt();

    printf("\nMasukkan jumlah baris matriks kedua : ");
    baris2 = getValidInt();
    printf("Masukkan jumlah kolom matriks kedua : ");
    kolom2 = getValidInt();

    if (baris1 != baris2 || kolom1 != kolom2) {
        printf("Operasi penjumlahan tidak dapat dilakukan karena ukuran matriks berbeda.\n");
        exit;
    }

    int matriks1[100][100], matriks2[100][100], hasil[100][100];

    printf("\nMasukkan elemen matriks pertama :\n");
    isiMatriks(matriks1, baris1, kolom1);

    printf("\nMasukkan elemen matriks kedua :\n");
    isiMatriks(matriks2, baris2, kolom2);

    kurangMatriks(matriks1, matriks2, hasil, baris1, kolom1);


    printf("\n\nMatriks Pertama :\n");
    tampilMatriks(matriks1, baris1, kolom1);
	printf("\n  -\n");

    printf("\n\nMatriks Kedua :\n");
    tampilMatriks(matriks2, baris2, kolom2);


    printf("\n  =\n\n");
    tampilMatriks(hasil, baris1, kolom1);
    printf("\n\n");
}

void matriks3() {
	system("CLS");
    int baris, kolom;

    printf("Masukkan jumlah baris matriks : ");
    baris = getValidInt();
    printf("Masukkan jumlah kolom matriks : ");
    kolom = getValidInt();

    int matriks[100][100], transpose[100][100];

    printf("\nMasukkan elemen matriks :\n");
    isiMatriks2(matriks, baris, kolom);

    transposeMatriks(matriks, transpose, baris, kolom);

    printf("\nMatriks Asli :\n");
    tampilMatriks(matriks, baris, kolom);

    printf("\nTranspose Matriks :\n");
    tampilMatriks(transpose, kolom, baris);
    printf("\n\n");
}

void sistemMenu(){
	char _Menu[100];
	system("CLS");
    gerakGaris();
    printf("\n\t\t\t\tAplikasi Beta Sudah Dekat V5\n");
    gerakGaris();
    printf("\n1. Penjumlahan Matriks\n");
    printf("2. Pengurangan Matriks\n");
    printf("3. Transpose Matriks\n");
    printf("4. Keluar Aplikasi\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;

    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "penjumlahan matriks") == 0) {
    	matriks1();
    	sistemSubMenu();
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "pengurangan matriks") == 0) {
        matriks2();
        sistemSubMenu();
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "transpose matriks") == 0) {
		matriks3();
        sistemSubMenu();
	} else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
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
