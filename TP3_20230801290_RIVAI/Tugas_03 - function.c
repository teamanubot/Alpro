/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include "Tugas_03 - library.h"

#define cetak printf
#define sistem system
#define pergi_ke goto
#define jika if
#define kalau else
#define Tidur Sleep

struct sistemVariable {
    int input, angka, hasil, i, j, jumlahGenap, jumlahGanjil, jumlahKelipatan7, value, validInput, hanyaEnter;
    double sum, average;
    char _Menu[100], subMenu[100], data[100], buffer[100];
};

struct sistemVariable struktur;

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

void waktuDanTanggal() {
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

void sistemPenjumlahanDeret() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Penjumlahan Deret\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Angka : ");
    struktur.angka = getValidInt();
    cetak("\n\t\033[1;34m");
    for(struktur.i = 1; struktur.i <= struktur.angka ; struktur.i++) {
		struktur.hasil = struktur.hasil + struktur.i;
		cetak("%d", struktur.i);
		jika (struktur.i != struktur.angka) {
			cetak (" + ");
		}
	}
    cetak(" = %d\n\n\n\033[0m", struktur.hasil);
}

void sistemBanyakBilangan() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tAplikasi Menampilkan Banyak Bilangan\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Angka Awal : ");
    struktur.angka = getValidInt();
    cetak("\033[1;32m\n\tMasukkan Angka akhir : ");
    struktur.input = getValidInt();
    
    cetak("\n\n\t\033[1;34mBilangan Genap\n\t");
    for (struktur.i = struktur.angka; struktur.i <= struktur.input; struktur.i++) {
        jika (struktur.i % 2 == 0) {
            cetak("%d ", struktur.i);
            struktur.jumlahGenap++;
        }
    }

    cetak("\n\n\tBilangan Ganjil\n\t");
    for (struktur.i = struktur.angka; struktur.i <= struktur.input; struktur.i++) {
        jika (struktur.i % 2 != 0) {
            cetak("%d ", struktur.i);
            struktur.jumlahGanjil++;
        }
    }

    cetak("\n\n\tKelipatan 7\n\t");
    for (struktur.i = struktur.angka; struktur.i <= struktur.input; struktur.i++) {
        jika (struktur.i % 7 == 0) {
            cetak("%d ", struktur.i);
            struktur.jumlahKelipatan7++;
        }
    }
    cetak("\n\n\tJumlah Genap : %d\n\t", struktur.jumlahGenap);
    cetak("Jumlah Ganjil : %d\n\t", struktur.jumlahGanjil);
    cetak("Jumlah Kelipatan 7 : %d\033[0m\n\n\n", struktur.jumlahKelipatan7);
}

void sistemRataRata() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Rata - Rata\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Banyak Bilangan : ");
    struktur.input = getValidInt();
    cetak("\n");

    jika (struktur.input <= 0) {
        cetak("Masukkan minimal 1 bilangan.\n");
    }
    for (struktur.i = 1; struktur.i <= struktur.input; struktur.i++) {
        cetak("\t\033[1;32mBilangan ke-%d : ", struktur.i);
        struktur.angka = getValidInt();
        struktur.sum += struktur.angka;
    }

    struktur.average = struktur.sum / struktur.input;
    cetak("\n\n\t\033[0m\033[1;34mRata - Rata = %.2f\033[0m\n\n\n", struktur.average);
}

void sistemFaktorial() {
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Faktorial\n\t");
    gerakGaris();
    cetak("\033[1;32m\n\tMasukkan Angka : ");
    struktur.angka = getValidInt();
	cetak("\033[1;34m\t%d! = ", struktur.angka);
	struktur.hasil = 1;
	for(struktur.i = struktur.angka; struktur.i > 0; struktur.i--) {
		struktur.hasil = struktur.hasil * struktur.i;
		cetak("%d", struktur.i);
		jika (struktur.i != 1) {
			cetak (" * ");
		}
	}
	cetak(" = %d\033[0m\n\n\n", struktur.hasil);
}

void sistemDeretMundur() {
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Deret Mundur\n\t");
    gerakGaris();
    cetak("\033[1;32m\n\tMasukkan Angka : ");
    struktur.input = getValidInt();
	cetak("\033[1;34m\n\t");
	struktur.angka = struktur.input * struktur.input;
    for (struktur.i = 1; struktur.i <= struktur.angka; struktur.i += 2) {
		for (struktur.j = 1; struktur.j <= struktur.i; struktur.j++) {
            printf("%d ", struktur.angka);
            struktur.angka--;
        }
        printf("\n\t");
    }
    cetak("\033[0m\n\n");
}

void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 3 [Aplikasi Beta Sudah Dekat V2]\n\t");
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
    cetak("\n\t\t\t\t\tAplikasi Beta Sudah Dekat V2\n\t");
    gerakGaris();
    cetak("\n\t1. Penjumlahan Deret\033[0m\n");
    cetak("\033[1;37m\t2. Menampilkan Banyak Bilangan\n");
    cetak("\t3. Rata - Rata\n");
    cetak("\t4. Faktorial\n");
    cetak("\t5. Deret Mundur\n");
    cetak("\t6. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur._Menu, sizeof(struktur._Menu), stdin);
    struktur._Menu[strcspn(struktur._Menu, "\n")] = 0;

    jika (strcmp(struktur._Menu, "1") == 0 || strcasecmp(struktur._Menu, "penjumlahan deret") == 0) {
        sistemPenjumlahanDeret();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "2") == 0 || strcasecmp(struktur._Menu, "menampilkan banyak bilangan") == 0) {
        sistemBanyakBilangan();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "3") == 0 || strcasecmp(struktur._Menu, "rata - rata") == 0) {
        sistemRataRata();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "4") == 0 || strcasecmp(struktur._Menu, "faktorial") == 0) {
        sistemFaktorial();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "5") == 0 || strcasecmp(struktur._Menu, "deret mundur") == 0) {
        sistemDeretMundur();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "6") == 0 || strcasecmp(struktur._Menu, "keluar aplikasi") == 0) {
    	sistem("CLS");
        waktuDanTanggal();
        cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
        return;
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
    	sistem("CLS");
        waktuDanTanggal();
        cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
        return;
    } kalau {
        noticeDefault();
        sistemSubMenu();
    }
}

void sistemInti() {
	sistemPembuka();
	sistemMenu();
}
