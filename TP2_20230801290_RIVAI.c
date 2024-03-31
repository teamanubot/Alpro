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

#define Nasi 3000
#define Ayam_Bakar 10000
#define Tahu 1000
#define Tempe 1000
#define Lalap 2000
#define Air_Mineral 3000
#define Sayur_Asem 5000
#define Air_Hangat 1000
#define Gepuk 10000

struct sistem {
    int data[4], hasil[3], input[2], subMenu, _Menu, garis;
    double sisi[3], luas[2], input2;
    char buffer[20];
};

struct sistem struktur;

void gerakGaris() {
    struktur.garis = 100;
    while (struktur.garis--) {
        printf("=");
        Sleep(5);
    }
}

void noticeDefault() {
    printf("\t\033[1;32mMasukkan Dengan Benar\n");
    printf("\tSilahkan Coba Lagi.\033[0m\n");
    getch();
    system("CLS");
}

void waktuDanTanggal(){
    time_t rawtime;
    struct tm *info_waktu;

    time(&rawtime);
    info_waktu = localtime(&rawtime);

    char *hari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    char *bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    int tanggal = info_waktu->tm_mday;
    int indeks_bulan = info_waktu->tm_mon;
    int tahun = info_waktu->tm_year + 1900;
    int jam = info_waktu->tm_hour;
    int menit = info_waktu->tm_min;
    int detik = info_waktu->tm_sec;

    char *nama_hari = hari[info_waktu->tm_wday];
    char *nama_bulan = bulan[indeks_bulan];

    printf("\033[0m\033[1;32mTanggal dan Waktu : %s, %02d %s %04d %02d:%02d:%02d\033[0m\n", nama_hari, tanggal, nama_bulan, tahun, jam, menit, detik);
    return;
}

int getValidInt() {
    printf("\033[1;32m");
    for (;;) {
        if (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            printf("\033[0m");
            if (struktur.buffer[0] == '\n') {
                printf("\033[1;32m");
                continue;
            }
            if (sscanf(struktur.buffer, "%d", &struktur.input[1]) == 1) {
                return struktur.input[1];
            } else {
                printf("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    }
}

double getValidDouble() {
    printf("\033[1;32m");
    for (;;) {
        if (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            printf("\033[0m");
            if (struktur.buffer[0] == '\n') {
                printf("\033[1;32m");
                continue;
            }
            if (sscanf(struktur.buffer, "%lf", &struktur.input2) == 1) {
                return struktur.input2;
            } else {
                printf("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    }
}

void formatRupiah(int number) {
    setlocale(LC_ALL, "");
    if (number < 1000) {
        printf("%d", number);
    } else {
        struktur.input[2] = number % 1000;
        formatRupiah(number / 1000);
        printf(".%03d", struktur.input[2]);
    }
}

void sistemWarteg() {
Menu:
    system("CLS");
    printf("\t\033[0m\033[1;31m");
    gerakGaris();
    printf("\n\t\t\t\t\t\tAplikasi Warteg Munte\n\t");
    gerakGaris();
    printf("\033[0m\033[1;37m\n\t1. Nasi + Ayam Bakar + Tahu + Tempe + Lalap + Air Mineral\n");
    printf("\t2. Nasi + Ayam Bakar + Tahu + Tempe + Lalap + Air Mineral + Sayur Asem\n");
    printf("\t3. Nasi +   Gepuk    + Tahu + Tempe + Lalap + Air Hangat\033[0m\n\n");
    printf("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor : ");
    struktur._Menu = getValidInt();

    if (struktur._Menu == 1) {
        struktur.data[1] = Nasi + Ayam_Bakar + Tahu + Tempe + Lalap + Air_Mineral;
        printf("\033[1;34m\n\tPaket 1 (Rp ");
        formatRupiah(struktur.data[1]);
        printf(")");
    } else if (struktur._Menu == 2) {
        struktur.data[1] = Nasi + Ayam_Bakar + Tahu + Tempe + Lalap + Air_Mineral + Sayur_Asem;
        printf("\033[1;34m\n\tPaket 2 (Rp ");
        formatRupiah(struktur.data[1]);
        printf(")");
    } else if (struktur._Menu == 3) {
        struktur.data[1] = Nasi + Gepuk + Tahu + Tempe + Lalap + Air_Hangat;
        printf("\033[1;34m\n\tPaket 3 (Rp ");
        formatRupiah(struktur.data[1]);
        printf(")");
    } else {
        noticeDefault();
        goto Menu;
    }

    printf("\n\tMasukkan Jumlah Pesan : ");
    struktur.input[1] = getValidInt();

    if (struktur.input[1] > 1000) {
        printf("\033[1;34m\tMaaf, jumlah pesanan melebihi batas (1000).\n");
        printf("\tSilakan pesan kembali.\n\n");
        getch();
        goto Menu;
    }

    struktur.hasil[1] = struktur.data[1] * struktur.input[1];
    struktur.hasil[2] = struktur.hasil[1] * 0.1;
    printf("\033[1;34m\tDikenakan Pajak (10%%) : Rp ");
    formatRupiah(struktur.hasil[2]);
    printf("\n\tBiaya Pembayaran : Rp ");
    formatRupiah(struktur.hasil[1] + struktur.hasil[2]);
    printf("\n\t");
    waktuDanTanggal();
    printf("\n\n");
}

void sistemSegitiga() {
    system("CLS");
    printf("\t\033[0m\033[1;31m");
    gerakGaris();
    printf("\n\t\t\t\t\t\tAplikasi Segitiga\n\t");
    gerakGaris();
    printf("\033[0m\033[1;32m\n\tMasukkan Sisi A : ");
    struktur.sisi[1] = getValidDouble();
    printf("\033[0m\033[1;32m\tMasukkan Sisi B : ");
    struktur.sisi[2] = getValidDouble();
    printf("\033[0m\033[1;32m\tMasukkan Sisi C : ");
    struktur.sisi[3] = getValidDouble();

    struktur.luas[1] = (struktur.sisi[1] + struktur.sisi[2] + struktur.sisi[3]) / 2;
    struktur.luas[2] = sqrt(struktur.luas[1] * (struktur.luas[1] - struktur.sisi[1]) * (struktur.luas[1] - struktur.sisi[2]) * (struktur.luas[1] - struktur.sisi[3]));

    if (struktur.sisi[1] == struktur.sisi[2] && struktur.sisi[2] == struktur.sisi[3]) {
        printf("\033[0m\033[1;34m\tSegitiga Ini Adalah Segitiga Sama Sisi");
        printf("\n\tLuas Segitiga Sama Sisi = %.2lf\n\n\n\033[0m", struktur.luas[2]);
    } else if (struktur.sisi[1] == struktur.sisi[2] || struktur.sisi[2] == struktur.sisi[3] || struktur.sisi[1] == struktur.sisi[3]) {
        printf("\033[0m\033[1;34m\tSegitiga Ini Adalah Segitiga Sama Kaki");
        printf("\n\tLuas Segitiga Sama Kaki = %.2lf\n\n\n\033[0m", struktur.luas[2]);
    } else {
        printf("\033[0m\033[1;34m\tSegitiga Ini Adalah Segitiga Sembarang\n\n\n\033[0m");
    }
}

void sistemSorting() {
    system("CLS");
    printf("\t\033[0m\033[1;31m");
    gerakGaris();
    printf("\n\t\t\t\t\t\tAplikasi Sorting Tiga Angka\n\t");
    gerakGaris();
    printf("\033[0m\033[1;32m\n\tMasukkan Angka Pertama : ");
    struktur.data[1] = getValidInt();
    printf("\033[0m\033[1;32m\tMasukkan Angka Kedua : ");
    struktur.data[2] = getValidInt();
    printf("\033[0m\033[1;32m\tMasukkan Angka Ketiga : ");
    struktur.data[3] = getValidInt();

    for (struktur.hasil[1] = 1; struktur.hasil[1] <= 3; struktur.hasil[1]++) {
        for (struktur.hasil[2] = struktur.hasil[1] + 1; struktur.hasil[2] <= 3; struktur.hasil[2]++) {
            if (struktur.data[struktur.hasil[1]] < struktur.data[struktur.hasil[2]]) {
                struktur.data[4] = struktur.data[struktur.hasil[1]];
                struktur.data[struktur.hasil[1]] = struktur.data[struktur.hasil[2]];
                struktur.data[struktur.hasil[2]] = struktur.data[4];
            }
        }
    }

    printf("\033[0m\033[1;34m\n\tHasil Sorting Dari Terbesar Ke Terkecil : %d, %d, %d", struktur.data[1], struktur.data[2], struktur.data[3]);
    printf("\n\tHasil Sorting Dari Terkecil Ke Terbesar : %d, %d, %d\n\n\n\033[0m", struktur.data[3], struktur.data[2], struktur.data[1]);
}

void sistemPembuka() {
    system("CLS");
    printf("\t\t\t\033[1;33mTugas Praktikum ALPRO 2 [Warteg, Segitiga, Sorting Bermenu]\n\t");
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
    printf("\n\t\t\t\t\tAplikasi Beta Sudah Dekat\n\t");
    gerakGaris();
    printf("\n\t1. Warteg Munte\033[0m\n");
    printf("\033[1;37m\t2. Penentu Segitiga\n");
    printf("\t3. Sorting Tiga Angka\n");
    printf("\t4. Keluar Aplikasi\033[0m\n");
    printf("\n");
    printf("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor : ");
    struktur._Menu = getValidInt();

    if (struktur._Menu == 1) {
        sistemWarteg();
    } else if (struktur._Menu == 2) {
        sistemSegitiga();
    } else if (struktur._Menu == 3) {
        sistemSorting();
    } else if (struktur._Menu == 4) {
    	system("CLS");
		waktuDanTanggal();
        printf("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat >_<");
		return;
    } else {
    	noticeDefault();
        goto Menu;
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
            system("CLS");
            waktuDanTanggal();
            printf("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat >_<");
			return;
            break;
    }
}

int main(void) {
    sistemInti();
}
