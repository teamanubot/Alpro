/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>

#define jika if
#define cetak printf
#define pergi_ke goto
#define kalau else
#define sistem system
#define Rivai_Munte main

#define Nasi 3000
#define Ayam_Bakar 10000
#define Tahu 1000
#define Tempe 1000
#define Lalap 2000
#define Air_Mineral 3000
#define Sayur_Asem 5000
#define Air_Hangat 1000
#define Gepuk 10000

struct sistemVariable {
    int data[4], hasil[3], input[2], subMenu, _Menu, garis;
    double sisi[3], luas[2], input2;
    char buffer[20];
};

struct sistemVariable struktur;

void gerakGaris() {
    struktur.garis = 100;
    while (struktur.garis--) {
        cetak("=");
        Sleep(5);
    }
}

void noticeDefault() {
    cetak("\t\033[1;32mMasukkan Dengan Benar\n");
    cetak("\tSilahkan Coba Lagi.\033[0m\n");
    getch();
    sistem("CLS");
}

void waktuDanTanggal(){
    time_t rawtime;
    struct tm *info_waktu;

    time(&rawtime);
    info_waktu = localtime(&rawtime);

    char *hari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
    char *bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    int tanggal = info_waktu->tm_mday;
    int indeks_bulan = info_waktu->tm_mon;
    int tahun = info_waktu->tm_year + 1900;
    int jam = info_waktu->tm_hour;
    int menit = info_waktu->tm_min;
    int detik = info_waktu->tm_sec;

    char *nama_hari = hari[info_waktu->tm_wday];
    char *nama_bulan = bulan[indeks_bulan];

    cetak("\033[0m\033[1;32mTanggal dan Waktu : %s, %02d %s %04d %02d:%02d:%02d\033[0m\n", nama_hari, tanggal, nama_bulan, tahun, jam, menit, detik);
    return;
}

int getValidInt() {
    cetak("\033[1;32m");
    for (;;) {
        jika (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            cetak("\033[0m");
            jika (struktur.buffer[0] == '\n') {
                cetak("\033[1;32m");
                continue;
            }
            jika (sscanf(struktur.buffer, "%d", &struktur.input[1]) == 1) {
                return struktur.input[1];
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

void formatRupiah(int number) {
    setlocale(LC_ALL, "");
    jika (number < 1000) {
        cetak("%d", number);
    } kalau {
        struktur.input[2] = number % 1000;
        formatRupiah(number / 1000);
        cetak(".%03d", struktur.input[2]);
    }
}

void sistemWarteg() {
Menu:
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Warteg Munte\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;37m\n\t1. Nasi + Ayam Bakar + Tahu + Tempe + Lalap + Air Mineral\n");
    cetak("\t2. Nasi + Ayam Bakar + Tahu + Tempe + Lalap + Air Mineral + Sayur Asem\n");
    cetak("\t3. Nasi +   Gepuk    + Tahu + Tempe + Lalap + Air Hangat\033[0m\n\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor : ");
    struktur._Menu = getValidInt();

    jika (struktur._Menu == 1) {
        struktur.data[1] = Nasi + Ayam_Bakar + Tahu + Tempe + Lalap + Air_Mineral;
        cetak("\033[1;34m\n\tPaket 1 (Rp ");
        formatRupiah(struktur.data[1]);
        cetak(")");
    } kalau jika (struktur._Menu == 2) {
        struktur.data[1] = Nasi + Ayam_Bakar + Tahu + Tempe + Lalap + Air_Mineral + Sayur_Asem;
        cetak("\033[1;34m\n\tPaket 2 (Rp ");
        formatRupiah(struktur.data[1]);
        cetak(")");
    } kalau jika (struktur._Menu == 3) {
        struktur.data[1] = Nasi + Gepuk + Tahu + Tempe + Lalap + Air_Hangat;
        cetak("\033[1;34m\n\tPaket 3 (Rp ");
        formatRupiah(struktur.data[1]);
        cetak(")");
    } kalau {
        noticeDefault();
        pergi_ke Menu;
    }

    cetak("\n\t\033[0m\033[1;32mMasukkan Jumlah Pesan : ");

Scan:
    struktur.input[1] = getValidInt();

    jika (struktur.input[1] > 78000) {
        cetak("\033[0m\033[1;32m\tMaaf, jumlah pesanan melebihi batas (78000).\n");
        cetak("\tSilakan Masukkan Jumlah Pesan Lagi Dengan Benar : ");
        getch();
        pergi_ke Scan;
    }

    struktur.hasil[1] = struktur.data[1] * struktur.input[1];
    struktur.hasil[2] = struktur.hasil[1] * 0.1;
    cetak("\033[1;34m\tDikenakan Pajak (10%%) : Rp ");
    formatRupiah(struktur.hasil[2]);
    cetak("\n\tBiaya Pembayaran : Rp ");
    formatRupiah(struktur.hasil[1] + struktur.hasil[2]);
    cetak("\n\t");
    waktuDanTanggal();
    cetak("\n\n");
}

void sistemSegitiga() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Segitiga\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Sisi A : ");
    struktur.sisi[1] = getValidDouble();
    cetak("\033[0m\033[1;32m\tMasukkan Sisi B : ");
    struktur.sisi[2] = getValidDouble();
    cetak("\033[0m\033[1;32m\tMasukkan Sisi C : ");
    struktur.sisi[3] = getValidDouble();

    struktur.luas[1] = (struktur.sisi[1] + struktur.sisi[2] + struktur.sisi[3]) / 2;
    struktur.luas[2] = sqrt(struktur.luas[1] * (struktur.luas[1] - struktur.sisi[1]) * (struktur.luas[1] - struktur.sisi[2]) * (struktur.luas[1] - struktur.sisi[3]));

    jika (struktur.sisi[1] == struktur.sisi[2] && struktur.sisi[2] == struktur.sisi[3]) {
        cetak("\033[0m\033[1;34m\tSegitiga Ini Adalah Segitiga Sama Sisi");
        cetak("\n\tLuas Segitiga Sama Sisi = %.2lf\n\n\n\033[0m", struktur.luas[2]);
    } kalau jika (struktur.sisi[1] == struktur.sisi[2] || struktur.sisi[2] == struktur.sisi[3] || struktur.sisi[1] == struktur.sisi[3]) {
        cetak("\033[0m\033[1;34m\tSegitiga Ini Adalah Segitiga Sama Kaki");
        cetak("\n\tLuas Segitiga Sama Kaki = %.2lf\n\n\n\033[0m", struktur.luas[2]);
    } kalau {
        cetak("\033[0m\033[1;34m\tSegitiga Ini Adalah Segitiga Sembarang\n\n\n\033[0m");
    }
}

void sistemSorting() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Sorting Tiga Angka\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.data[1] = getValidInt();
    cetak("\033[0m\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.data[2] = getValidInt();
    cetak("\033[0m\033[1;32m\tMasukkan Angka Ketiga : ");
    struktur.data[3] = getValidInt();

    for (struktur.hasil[1] = 1; struktur.hasil[1] <= 3; struktur.hasil[1]++) {
        for (struktur.hasil[2] = struktur.hasil[1] + 1; struktur.hasil[2] <= 3; struktur.hasil[2]++) {
            jika (struktur.data[struktur.hasil[1]] < struktur.data[struktur.hasil[2]]) {
                struktur.data[4] = struktur.data[struktur.hasil[1]];
                struktur.data[struktur.hasil[1]] = struktur.data[struktur.hasil[2]];
                struktur.data[struktur.hasil[2]] = struktur.data[4];
            }
        }
    }

    cetak("\033[0m\033[1;34m\n\tHasil Sorting Dari Terbesar Ke Terkecil : %d, %d, %d", struktur.data[1], struktur.data[2], struktur.data[3]);
    cetak("\n\tHasil Sorting Dari Terkecil Ke Terbesar : %d, %d, %d\n\n\n\033[0m", struktur.data[3], struktur.data[2], struktur.data[1]);
}

void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\033[1;33mTugas Praktikum ALPRO 2 [Warteg, Segitiga, Sorting Bermenu]\n\t");
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
    cetak("\n\t\t\t\t\tAplikasi Beta Sudah Dekat\n\t");
    gerakGaris();
    cetak("\n\t1. Warteg Munte\033[0m\n");
    cetak("\033[1;37m\t2. Penentu Segitiga\n");
    cetak("\t3. Sorting Tiga Angka\n");
    cetak("\t4. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor : ");
    struktur._Menu = getValidInt();

    jika (struktur._Menu == 1) {
        sistemWarteg();
    } kalau jika (struktur._Menu == 2) {
        sistemSegitiga();
    } kalau jika (struktur._Menu == 3) {
        sistemSorting();
    } kalau jika (struktur._Menu == 4) {
    	sistem("CLS");
		waktuDanTanggal();
        cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat >_<");
		return;
    } kalau {
    	noticeDefault();
        pergi_ke Menu;
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
            sistem("CLS");
            waktuDanTanggal();
            cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat >_<");
			return;
            break;
    }
}

int Rivai_Munte(void) {
    sistemInti();
}
