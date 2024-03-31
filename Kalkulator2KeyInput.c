/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define jika if
#define cetak printf
#define pergi_ke goto
#define kalau else
#define sistem system
#define Rivai_Munte main

struct sistemVariable {
    double rAngka[3], rHasil, input2;
    int subMenu, input, menuOption, angka, hasil, i;
    char _Menu[3];
    char buffer[20];
};

struct sistemVariable struktur;

int getValidInt() {
    cetak("\033[1;32m");
    for (;;) {
        jika (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            cetak("\033[0m");
            jika (struktur.buffer[0] == '\n') {
                cetak("\033[1;32m");
                continue;
            }
            jika (sscanf(struktur.buffer, "%d", &struktur.input) == 1) {
                return struktur.input;
            } kalau {
            	cetak("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    }
}

double getValidDouble() {
    cetak("\033[1;32m");
    for (;;) {
        jika (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            cetak("\033[0m");
            jika (struktur.buffer[0] == '\n') {
                cetak("\033[1;32m");
                continue;
            }
            jika (sscanf(struktur.buffer, "%lf", &struktur.input2) == 1) {
                return struktur.input2;
            } kalau {
				cetak("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    }
}

void sistemPenjumlahan() {
    cetak("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    cetak("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] + struktur.rAngka[2];
    cetak("\n\n\t\033[1;34mHasil dari %.2lf + %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemPengurangan() {
    cetak("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    cetak("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] - struktur.rAngka[2];
    cetak("\n\n\t\033[1;34mHasil dari %.2lf - %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemPerkalian() {
    cetak("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    cetak("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] * struktur.rAngka[2];
    cetak("\n\n\t\033[1;34mHasil dari %.2lf x %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemPembagian() {
    cetak("\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.rAngka[1] = getValidDouble();
    cetak("\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.rAngka[2] = getValidDouble();
    struktur.rHasil = struktur.rAngka[1] / struktur.rAngka[2];
    cetak("\n\n\t\033[1;34mHasil dari %.2lf : %.2lf = %.2lf\033[0m\n\n\n", struktur.rAngka[1], struktur.rAngka[2], struktur.rHasil);
}

void sistemFaktorial() {
    cetak("\033[1;32m\n\tMasukkan Angka : ");
    struktur.angka = getValidInt();
	cetak("\033[1;34m\t%d! = ", struktur.angka);
	struktur.hasil = 1;
	for(struktur.i = struktur.angka; struktur.i > 0; struktur.i--) {
		struktur.hasil = struktur.hasil * struktur.i;
		cetak("%d", struktur.i);
		jika(struktur.i != 1) {
			cetak (" * ");
		}
	}
	cetak(" = %d\033[0m\n\n\n", struktur.hasil);
}

void noticeDefault() {
    cetak("\t\033[1;32mMasukkan Dengan Benar\n");
    cetak("\tSilahkan Coba Lagi.\033[0m\n");
    getch();
    sistem("CLS");
}

void gerakGaris() {
    int garis = 100;
    while (garis--) {
        cetak("=");
        Sleep(5);
    }
}

void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 1 [Kalkulator Sipaling Menu]\n\t");
    gerakGaris();
    cetak("\n\tNama\t : Rivai\n");
    cetak("\tNIM\t : 20230801290\n\t");
    gerakGaris();
    cetak("\n\n");
    cetak("\tWelcome, ");
    sistem("PAUSE");
}

void sistemInti() {
    sistemPembuka();

Menu:
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tAplikasi Kalkulator Ga Simpel Banget Dah\n\t");
    gerakGaris();
    cetak("\n\t1. Penjumlahan '+'\033[0m\n");
    cetak("\033[1;37m\t2. Pengurangan '-'\n");
    cetak("\t3. Perkalian 'x'\n");
    cetak("\t4. Pembagian ':'\n");
    cetak("\t5. Faktorial '!'\n");
    cetak("\t6. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Atau Simbol : ");
    scanf("\n%s\033[0m", struktur._Menu);

    jika (strlen(struktur._Menu) > 1) {
        noticeDefault();
        pergi_ke Menu;
    }

    jika (sscanf(struktur._Menu, "%d", &struktur.menuOption) == 1) {
        jika (struktur.menuOption == 1) {
            sistemPenjumlahan();
        } kalau jika (struktur.menuOption == 2) {
            sistemPengurangan();
        } kalau jika (struktur.menuOption == 3) {
            sistemPerkalian();
        } kalau jika (struktur.menuOption == 4) {
            sistemPembagian();
        } kalau jika (struktur.menuOption == 5) {
            sistemFaktorial();
        } kalau jika (struktur.menuOption == 6) {
            return;
        } kalau {
            noticeDefault();
            pergi_ke Menu;
        }
    } kalau {
        jika (strchr("+-x:!", struktur._Menu[0]) != NULL) {
            jika (struktur._Menu[0] == '+') {
                sistemPenjumlahan();
            } kalau jika (struktur._Menu[0] == '-') {
                sistemPengurangan();
            } kalau jika (struktur._Menu[0] == 'x') {
                sistemPerkalian();
            } kalau jika (struktur._Menu[0] == ':') {
                sistemPembagian();
            } kalau jika (struktur._Menu[0] == '!') {
                sistemFaktorial();
            }
        } kalau {
            noticeDefault();
            pergi_ke Menu;
        }
    }

SubMenu:
    cetak("\t\033[1;36m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
    gerakGaris();
    cetak("\n\t1. Kembali Ke Awal\n");
    cetak("\t2. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu : ");
    struktur.subMenu = getValidInt();

    switch (struktur.subMenu) {
    default:
        noticeDefault();
        pergi_ke SubMenu;
        break;

    case 1:
        pergi_ke Menu;
        break;

    case 2:
    	cetak("\t\033[1;32m");
        return;
        break;
    }
}

int Rivai_Munte(void) {
    sistemInti();
}
