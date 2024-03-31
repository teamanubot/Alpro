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
#include <pthread.h>
#include <windows.h>
#include <mmsystem.h>

#define cetak printf
#define fcetak fprintf
#define sistem system
#define pergi_ke goto
#define jika if
#define kalau else
#define Tidur Sleep
#define keluar exit

struct sistemVariable {
	int input, value, validInput, hanyaEnter, i;
	long long int value2, data2[3];
    double sum, average;
    char _Menu[100], subMenu[100], data[100], buffer[100], id[100], nama[100], jabatan[100], jamKerja[100], gaji[100];
};

struct sistemVariable struktur;

void sistemMenu();

void sistemSubMenu();

void noticeDefault() {
	FILE *file = fopen("error.txt", "a");
    fcetak(file, "[ERROR] Kesalahan Saat Menginput Pada Menu\n");
	fclose(file);
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
}

void noticeExit(){
	sistem("CLS");
    waktuDanTanggal();
    cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
    keluar;
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
            	FILE *file = fopen("error.txt", "a");
    			fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
				fclose(file);
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
            	FILE *file = fopen("error.txt", "a");
    			fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
				fclose(file);
                cetak("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    } while (!struktur.validInput);

    return struktur.value;
}

void sistemGenap() {
	int n, i, bilangan;
    int jumlah = 0;
    int jumlah_genap = 0;
    float rata_rata;
    system("cls");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tMenghitung Rata-Rata Bilangan Genap\n\t");
    gerakGaris();
   	cetak("\033[0m\033[1;32m\n\tMasukkan banyak bilangan : ");
    fflush(stdin);
    n = getValidInt();
	cetak("\n");
	
    for (i = 1; i <= n; i++) {
        cetak("\033[0m\033[1;32m\tMasukkan bilangan ke-%d : ", i);
        bilangan = getValidInt();
        jika (bilangan % 2 == 0) {
            jumlah_genap++;
            jumlah += bilangan;
        }
    }

	rata_rata = 0;
    jika (jumlah_genap > 0) {
        rata_rata = (float) jumlah / jumlah_genap;
        cetak("\033[1;34m\n\tRata-rata bilangan genap : %.2f\033[0m\n\n\n", rata_rata);
    } kalau {
        cetak("\033[1;34m\n\tTidak ada bilangan genap yang dimasukkan.\033[0m\n\n\n");
    }
}

void bintangAngka(){
    int n, i, j, angka, sum = 0;
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tMenghitung Bintang Angka\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Banyak Bilangan : ");
    n = getValidInt();
    cetak ("\n\t");
    for (i = 1; i <= n; i++) {
    	angka = 0;
    	for (j = 1; j <= i; j++) {
        	cetak("\033[0m\033[1;32m%d", j);
			angka += j;
        	sum += j;
        	jika (j < i) {
            	cetak(" + ");
        	}
		}
        cetak(" = %d\n\t", angka);
    }
    cetak("\033[1;34m\n\tJadi, jumlah seluruhnya adalah : %d\033[0m\n\n\n", sum);
}

void sistemKardus(){
    int jumlahBakwan, jumlahGehu, jumlahPisgor;
    int maksimumBakwan = 20, maksimumGehu = 15, maksimumPisgor = 25;
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tMenghitung Kardus Keluar\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan jumlah bakwan : ");
    jumlahBakwan = getValidInt();
    cetak("\033[0m\033[1;32m\tMasukkan jumlah gehu : ");
    jumlahGehu = getValidInt();
    cetak("\033[0m\033[1;32m\tMasukkan jumlah pisgor : ");
    jumlahPisgor = getValidInt();

    int kardusBakwan = (jumlahBakwan + maksimumBakwan - 1) / maksimumBakwan;
    int kardusGehu = (jumlahGehu + maksimumGehu - 1) / maksimumGehu;
    int kardusPisgor = (jumlahPisgor + maksimumPisgor - 1) / maksimumPisgor;
    int totalKardus = kardusBakwan + kardusGehu + kardusPisgor;

    cetak("\033[1;34m\n\tBakwan   : %d kardus (%d bakwan)\n\t", kardusBakwan, jumlahBakwan);
    cetak("Gehu     : %d kardus (%d gehu)\n\t", kardusGehu, jumlahGehu);
    cetak("Pisgor   : %d kardus (%d pisgor)\n\n\t", kardusPisgor, jumlahPisgor);
    cetak("Total    : %d kardus\033[0m\n\n\n", totalKardus);
}

void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\t\033[1;33mTugas UTS ALPRO [Aplikasi Beta Sudah Dekat V5]\n\t");
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
    cetak("\n\t\t\t\t\tAplikasi Beta Sudah Dekat V5\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;37m\n\t1. Menghitung Rata-Rata Bilangan Genap\n");
    cetak("\t2. Menghitung Bintang Angka\n");
    cetak("\t3. Menghitung Kardus Keluar\n");
    cetak("\t4. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur._Menu, sizeof(struktur._Menu), stdin);
    struktur._Menu[strcspn(struktur._Menu, "\n")] = 0;

    jika (strcmp(struktur._Menu, "1") == 0 || strcasecmp(struktur._Menu, "menghitung rata-rata bilangan genap") == 0) {
    	sistemGenap();
    	sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "2") == 0 || strcasecmp(struktur._Menu, "menghitung bintang angka") == 0) {
        bintangAngka();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "3") == 0 || strcasecmp(struktur._Menu, "menghitung kardus keluar") == 0) {
        sistemKardus();
        sistemSubMenu();
	} kalau jika (strcmp(struktur._Menu, "4") == 0 || strcasecmp(struktur._Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } kalau {
        noticeDefault();
        sistemMenu();
    }
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
    	noticeExit();
    } kalau {
        noticeDefault();
        sistemSubMenu();
    }
}

void sistemInti() {
    sistemPembuka();
    sistemMenu();
}
