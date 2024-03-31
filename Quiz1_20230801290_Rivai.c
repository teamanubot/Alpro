/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define cetak printf
#define sistem system
#define pergi_ke goto
#define jika if
#define kalau else
#define Tidur Sleep

struct sistemVariable {
	int value, validInput, hanyaEnter;
	long long int value2, data[3];
    double sum, average;
    char _Menu[100], subMenu[100], buffer[100], id[100], nama[100], jabatan[100], jamKerja[100], gaji[100];
};

struct sistemVariable struktur;

void sistemMenu();

void sistemSubMenu();

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
        Tidur(5);
    }
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
    do {
        cetak("\033[1;32m");
        jika (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            size_t len = strlen(struktur.buffer);
            jika (len > 0 && struktur.buffer[len - 1] == '\n') {
                struktur.buffer[len - 1] = '\0';
                len--;
            }
            struktur.hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isspace(struktur.buffer[i])) {
                    struktur.hanyaEnter = 0;
                    break;
                }
            }
            jika (struktur.hanyaEnter) {
                cetak("\033[1;32m\tMasukkan Angka : ");
                continue;
            }
            struktur.validInput = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isdigit(struktur.buffer[i])) {
                    struktur.validInput = 0;
                    break;
                }
            }
            jika (struktur.validInput) {
                sscanf(struktur.buffer, "%d", &struktur.value);
                cetak("\033[0m");
            } kalau {
                cetak("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    } while (!struktur.validInput);
    return struktur.value;
}

long long int getValidLongLongInt() {
	do {
        cetak("\033[1;32m");
        jika (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            size_t len = strlen(struktur.buffer);
            jika (len > 0 && struktur.buffer[len - 1] == '\n') {
                struktur.buffer[len - 1] = '\0';
                len--;
            }
            struktur.hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isspace(struktur.buffer[i])) {
                    struktur.hanyaEnter = 0;
                    break;
                }
            }
            jika (struktur.hanyaEnter) {
                cetak("\033[1;32m\tMasukkan Angka : ");
                continue;
            }
            struktur.validInput = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isdigit(struktur.buffer[i])) {
                    struktur.validInput = 0;
                    break;
                }
            }
            jika (struktur.validInput) {
                sscanf(struktur.buffer, "%lld", &struktur.value2);
                cetak("\033[0m");
            } kalau {
                cetak("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    } while (!struktur.validInput);
    return struktur.value2;
}

void getValidString(char input[]) {
    int valid = 0;
    do {
        printf("\033[1;32m");
        jika (fgets(input, 100, stdin) != NULL) {
            size_t len = strlen(input);
            jika (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
                len--;
            }
            struktur.hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isspace(input[i])) {
                    struktur.hanyaEnter = 0;
                    break;
                }
            }
            jika (struktur.hanyaEnter) {
                cetak("\033[1;32m\tMasukkan hanya huruf : ");
                continue;
            }
            valid = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isspace(input[i]) && !isalpha(input[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                cetak("\033[0m");
            } else {
                cetak("\033[1;32m\tMasukkan hanya huruf dan spasi : ");
            }
        }
    } while (!valid);
}

struct duaInteger {
    int satu;
    int dua;
};

struct duaInteger getValidInt2() {
    struct duaInteger hasil;
    char input[100];
    int scanned = 0;

    do {
        cetak("\033[1;32m");
        jika (fgets(input, sizeof(input), stdin) != NULL) {
            int jam, menit;
            scanned = sscanf(input, "%d.%d", &jam, &menit);
            
            jika (scanned == 2 && jam >= 0 && jam < 24 && menit >= 0 && menit < 60) {
                hasil.satu = jam;
                hasil.dua = menit;
                printf("\033[0m");
            } kalau {
                cetak("\033[1;32m\tMasukkan format jam yang valid (HH.MM): ");
            }
        }
    } while (scanned != 2);

    return hasil;
}

void dataPegawai(){
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
	gerakGaris();
    cetak("\n\t\t\t\t\tProgram Inputan Data Pegawai\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tId Pegawai : ");
    struktur.data[1] = getValidLongLongInt();
    cetak("\033[1;32m\tNama Pegawai : ");
    getValidString(struktur.nama);
    cetak("\033[1;32m\tJabatan : ");
    getValidString(struktur.jabatan);
    cetak("\033[1;32m\tJam Kerja Perhari : ");
    struktur.data[2] = getValidLongLongInt();
    cetak("\033[1;32m\tGolongan Gaji : ");
    struktur.data[3] = getValidLongLongInt();
    cetak("\033[1;34m\n\n\t");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tHasil Olah Data\n\t");
    gerakGaris();
    cetak("\n\tId Pegawai : %lld", struktur.data[1]);
    cetak("\n\tNama Pegawai : %s", struktur.nama);
    cetak("\n\tJabatan : %s", struktur.jabatan);
    cetak("\n\tJam Kerja Perhari : %lld", struktur.data[2]);
    cetak("\n\tGolongan Gaji : %lld", struktur.data[3]);
    cetak("\033[0m\n\n\n");
}

void biayaParkir(){
	struct duaInteger jamMasuk, jamKeluar;
    int jam, menit, biaya;
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tProgram Hitung Biaya Parkir\n\t");
    gerakGaris();
    
	cetak("\033[0m\033[1;32m\n\tMasukkan jam masuk (contoh: 10.00) : ");
    jamMasuk = getValidInt2();

    cetak("\033[1;32m\tMasukkan jam keluar (contoh: 15.30) : ");
    jamKeluar = getValidInt2();
    
    jika (jamKeluar.satu > jamMasuk.satu || (jamKeluar.satu == jamMasuk.satu && jamKeluar.dua > jamMasuk.dua)) {
        int selisihJam = jamKeluar.satu - jamMasuk.satu;
        int selisihMenit = jamKeluar.dua - jamMasuk.dua;
        
        jika (selisihMenit < 0) {
            selisihJam--;
            selisihMenit += 60;
        }

        jam = selisihJam;
        menit = selisihMenit;

        jika (jam > 0) {
            jika (jam < 4) {
                biaya = 2000 + ((jam - 1) * 1000);
            } kalau {
                biaya = 4000 + (jam - 3) * 500;
            }
        }

        cetak("\033[1;34m\tAnda parkir selama: %d jam %d menit\n", jam, menit);
        cetak("\tBiaya parkir: %d\033[0m\n\n\n", biaya);
    } kalau {
        cetak("\tJam keluar harus lebih besar dari jam masuk.\033[0m\n\n\n");
    }
}


void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 3 [Aplikasi Beta Sudah Dekat V3]\n\t");
    gerakGaris();
    cetak("\n\tNama\t : Rivai\n");
    cetak("\tNIM\t : 20230801290\n\t");
    gerakGaris();
    cetak("\n\n");
    cetak("\tWelcome, ");
    sistem("PAUSE");
}

void sistemMenu(){
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tAplikasi Beta Sudah Dekat V3\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;37m\n\t1. Program Inputan Data Pegawai\n");
    cetak("\t2. Program Hitung Biaya Parkir\033[0m\n");
    cetak("\t3. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur._Menu, sizeof(struktur._Menu), stdin);
    struktur._Menu[strcspn(struktur._Menu, "\n")] = 0;

    jika (strcmp(struktur._Menu, "1") == 0 || strcasecmp(struktur._Menu, "program inputan data pegawai") == 0) {
    	dataPegawai();
    } kalau jika (strcmp(struktur._Menu, "2") == 0 || strcasecmp(struktur._Menu, "program hitung biaya parkir") == 0) {
        biayaParkir();
	} kalau jika (strcmp(struktur._Menu, "3") == 0 || strcasecmp(struktur._Menu, "keluar aplikasi") == 0) {
    	sistem("CLS");
        waktuDanTanggal();
        cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
        return;
    } kalau {
        noticeDefault();
        sistemMenu();
    }
    sistemSubMenu();
}

void sistemSubMenu(){
	cetak("\t\033[1;36m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
    gerakGaris();
    cetak("\n\t1. Kembali Ke Awal\n");
    cetak("\t2. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur.subMenu, sizeof(struktur.subMenu), stdin);
    struktur.subMenu[strcspn(struktur.subMenu, "\n")] = 0;

    jika (strcmp(struktur.subMenu, "1") == 0 || strcasecmp(struktur.subMenu, "kembali ke awal") == 0) {
        sistemMenu();
    } kalau jika (strcmp(struktur.subMenu, "2") == 0 || strcasecmp(struktur.subMenu, "keluar aplikasi") == 0) {
    	sistem("CLS");
        waktuDanTanggal();
        cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
        return;
    } kalau {
        noticeDefault();
        sistemSubMenu();
    }
}

void sistemInti(){
	sistemPembuka();
	sistemMenu();
}

int main(void){
	sistemInti();
}
