/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct sistem {
    double rAngka[3], rHasil, input2;
    int subMenu, input, menuOption, angka, hasil, i;
    char _Menu[3]; // Menggunakan array char untuk input menu
    char buffer[20];
};

struct sistem struktur;

int getValidInt() {
    // Mengubah warna teks menjadi hijau sebelum pengguna memasukkan angka
    printf("\033[1;32m");

    for (;;) {
        if (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            // Mengembalikan warna teks ke semula (default)
            printf("\033[0m");

            if (struktur.buffer[0] == '\n') {
                // Hanya Enter ditekan, lanjutkan loop
                // dan ubah warna teks kembali menjadi hijau
                printf("\033[1;32m");
                continue;
            }
            if (sscanf(struktur.buffer, "%d", &struktur.input) == 1) {
                return struktur.input; // Input adalah angka, kembalikan nila2inya
            } else {
                // Mengembalikan warna teks ke hijau setelah mencetak pesan kesalahan
                printf("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    }
}

double getValidDouble() {
    // Mengubah warna teks menjadi hijau sebelum pengguna memasukkan angka
    printf("\033[1;32m");

    for (;;) {
        if (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            // Mengembalikan warna teks ke semula (default)
            printf("\033[0m");

            if (struktur.buffer[0] == '\n') {
                // Hanya Enter ditekan, lanjutkan loop
                // dan ubah warna teks kembali menjadi hijau
                printf("\033[1;32m");
                continue;
            }
            if (sscanf(struktur.buffer, "%lf", &struktur.input2) == 1) {
                return struktur.input2; // Input adalah angka, kembalikan nilainya
            } else {
                // Mengembalikan warna teks ke hijau setelah mencetak pesan kesalahan
                printf("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    }
}

void sistemPenjumlahan() {
    printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    printf("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] + struktur.rAngka[2];
    printf("\n\n\t\033[1;34mHasil dari %.2lf + %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemPengurangan() {
    printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    printf("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] - struktur.rAngka[2];
    printf("\n\n\t\033[1;34mHasil dari %.2lf - %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemPerkalian() {
    printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    printf("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] * struktur.rAngka[2];
    printf("\n\n\t\033[1;34mHasil dari %.2lf x %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemPembagian() {
    printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    printf("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] / struktur.rAngka[2];
    printf("\n\n\t\033[1;34mHasil dari %.2lf : %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemFaktorial() {
    printf("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidInt();
	struktur.hasil = 1;
	for(struktur.i = struktur.rAngka[1]; struktur.i > 0; struktur.i--) {
		struktur.hasil = struktur.hasil * struktur.i;
		printf("\033[1;34m%d\033[0m", struktur.i);
		if(struktur.i != 1) {
			printf ("\033[1;34m * \033[0m");
		}
	}
	printf("\t\033[1;34m = %d\033[0m\n\n\n", struktur.hasil);
}

void noticeDefault() {
    printf("\t\033[1;32mMasukkan Dengan Benar\n");
    printf("\tSilahkan Coba Lagi.\033[0m\n");
    getch();
    system("CLS");
}

void gerakGaris() {
    int garis = 100;
    while (garis--) {
        printf("=");
        Sleep(5);
    }
}

void sistemPembuka() {
    system("CLS");
    printf("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 1 [Kalkulator Sipaling Menu]\n\t");
    gerakGaris();
    printf("\n\tNama\t : Rivai\n");
    printf("\tNIM\t : 20230801290\n\t");
    gerakGaris();
    printf("\n\n");
    printf("\tWelcome, ");
    system("PAUSE");
}

void sistemInti() {
    sistemPembuka();

Menu:
    system("CLS");
    printf("\t\033[0m\033[1;31m");
    gerakGaris();
    printf("\n\t\t\t\t\tAplikasi Kalkulator Ga Simpel Banget Dah\n\t");
    gerakGaris();
    printf("\n\t1. Penjumlahan '+'\033[0m\n");
    printf("\033[1;37m\t2. Pengurangan '-'\n");
    printf("\t3. Perkalian 'x'\n");
    printf("\t4. Pembagian ':'\n");
    printf("\t5. Faktorial '!'\n");
    printf("\t6. Keluar Aplikasi\033[0m\n");
    printf("\n");
    printf("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Atau Simbol : ");
    scanf("\n%s\033[0m", struktur._Menu);

    // Menambahkan pemeriksaan tambahan jika input berisi lebih dari satu karakter
    if (strlen(struktur._Menu) > 1) {
        noticeDefault();
        goto Menu;
    }

    // Konversi input ke bilangan bulat untuk memproses pilihan menu yang valid
    if (sscanf(struktur._Menu, "%d", &struktur.menuOption) == 1) {
        if (struktur.menuOption == 1) {
            sistemPenjumlahan();
        } else if (struktur.menuOption == 2) {
            sistemPengurangan();
        } else if (struktur.menuOption == 3) {
            sistemPerkalian();
        } else if (struktur.menuOption == 4) {
            sistemPembagian();
        } else if (struktur.menuOption == 5) {
            sistemFaktorial();
        } else if (struktur.menuOption == 6) {
            return;
        } else {
            noticeDefault();
            goto Menu;
        }
    } else {
        // Jika input bukan bilangan bulat, cek apakah itu adalah simbol matematika
        if (strchr("+-x:!", struktur._Menu[0]) != NULL) {
            if (struktur._Menu[0] == '+') {
                sistemPenjumlahan();
            } else if (struktur._Menu[0] == '-') {
                sistemPengurangan();
            } else if (struktur._Menu[0] == 'x') {
                sistemPerkalian();
            } else if (struktur._Menu[0] == ':') {
                sistemPembagian();
            } else if (struktur._Menu[0] == '!') {
                sistemFaktorial();
            }
        } else {
            noticeDefault();
            goto Menu;
        }
    }

SubMenu:
    printf("\t\033[1;36m");
    gerakGaris();
    printf("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
    gerakGaris();
    printf("\n\t1. Kembali Ke Awal\n");
    printf("\t2. Keluar Aplikasi\033[0m\n");
    printf("\n");
    printf("\t\033[1;32mMasukkan Pilihan Menu : ");
    struktur.subMenu = getValidInt();

    switch (struktur.subMenu) {
    default:
        noticeDefault();
        goto SubMenu;
        break;

    case 1:
        goto Menu;
        break;

    case 2:
    	printf("\t\033[1;32m");
        return;
        break;
    }
}

int main(void) {
    sistemInti();
}
