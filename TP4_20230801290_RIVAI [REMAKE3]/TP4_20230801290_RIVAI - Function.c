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
	int value, validInput, hanyaEnter;
	long long int value2, data2[3];
    double sum, average;
    char _Menu[100], subMenu[100], data[100], buffer[100], id[100], nama[100], jabatan[100], jamKerja[100], gaji[100];
};

struct sistemVariable struktur;

const int jumlah_lagu = 3;

int* urutan_pemutaran;

int threadCreationStatus = 0;

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

void getValid(char input[]) {
    int valid = 0;
    do {
        cetak("\033[1;32m");
        jika (fgets(input, 100, stdin) != NULL) {
		size_t len = strlen(input);
            jika(strlen(input) == 2){
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
            		FILE *file = fopen("error.txt", "a");
    				fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
					fclose(file);
                	cetak("\033[1;32m\tMasukkan Hanya Satu Karakter Angka/Huruf/Simbol (Tanpa Spasi) : ");
                	continue;
            	}
            	valid = 1;
            	for (size_t i = 0; i < len; i++) {
                	jika (!isgraph(input[i])) {
                    	valid = 0;
                    	break;
                	}
            	}
            	jika (valid) {
                	cetak("\033[0m");
            	} kalau {
            		FILE *file = fopen("error.txt", "a");
    				fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
					fclose(file);
                	cetak("\033[1;32m\tMasukkan Hanya Satu Karakter Angka/Huruf/Simbol (Tanpa Spasi) : ");
            	}
            } kalau {
            	FILE *file = fopen("error.txt", "a");
    			fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
				fclose(file);
            	cetak("\033[1;32m\tMasukkan Hanya Satu Karakter Angka/Huruf/Simbol (Tanpa Spasi) : ");
            }
        }
    } while (!valid);
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
                sscanf(struktur.buffer, "%lld", &struktur.value2);
                cetak("\033[0m");
            } kalau {
            	FILE *file = fopen("error.txt", "a");
    			fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
				fclose(file);
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
            	FILE *file = fopen("error.txt", "a");
    			fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
				fclose(file);
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
            	FILE *file = fopen("error.txt", "a");
    			fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
				fclose(file);
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
            	FILE *file = fopen("error.txt", "a");
    			fcetak(file, "[ERROR] Kesalahan Saat Menginput\n");
				fclose(file);
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
    struktur.data2[1] = getValidLongLongInt();
    cetak("\033[1;32m\tNama Pegawai : ");
    getValidString(struktur.nama);
    cetak("\033[1;32m\tJabatan : ");
    getValidString(struktur.jabatan);
    cetak("\033[1;32m\tJam Kerja Perhari : ");
    struktur.data2[2] = getValidLongLongInt();
    cetak("\033[1;32m\tGolongan Gaji : ");
    struktur.data2[3] = getValidLongLongInt();
    cetak("\033[1;34m\n\n\t");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tHasil Olah Data\n\t");
    gerakGaris();
    cetak("\n\tId Pegawai : %lld", struktur.data2[1]);
    cetak("\n\tNama Pegawai : %s", struktur.nama);
    cetak("\n\tJabatan : %s", struktur.jabatan);
    cetak("\n\tJam Kerja Perhari : %lld", struktur.data2[2]);
    cetak("\n\tGolongan Gaji : %lld", struktur.data2[3]);
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
    	FILE *file = fopen("error.txt", "a");
    	fcetak(file, "[ERROR] Kesalahan Pada Function Biaya Parkir\n");
		fclose(file);
        cetak("\033[1;32m\tJam keluar harus lebih besar dari jam masuk.\033[0m\n\n\n");
    }
}

void sistemLogoValo(){
	sistem("CLS");
	int i, j, n;
	char a[100];
	cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tProgram Bintang 3\n\t");
    gerakGaris();
	cetak("\033[0m\033[1;32m\n\tMasukkan Inputan Huruf/Angka/Simbol : ");
	getValid(a);
	cetak("\033[1;32m\tMasukkan Inputan Angka (Batas) : ");
	n = getValidInt();
	cetak("\033[1;34m\t");
	
	i = 0;
	while (i < n) {
		j = 0;
		while (j < 2 * n) {
			jika (i >= j || i + j >= 2 * n - 1) {
                cetak("%s ", a);
            } kalau {
                cetak("  ");
        	}
        	j++;
		}
		cetak("\n\t");
		i++;
	}
	i = 0;
	while (i < n) {
		j = 0;
		while (j < 2 * n) {
			jika (i >= j || i + j >= 2 * n - 1) {
                cetak("  ");
            } kalau {
                cetak("%s ", a);
        	}
        	j++;
		}
		cetak("\n\t");
		i++;
	}
	
    cetak("\033[0m\n\n");
}

void sistemMusik(){
Menu:
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tProgram Playlist Lagu (Musik)\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;37m\n\t1. JKT48 - Rapsodi\n");
    cetak("\t2. JKT48 - Seventeen\n");
    cetak("\t3. Tokyo Drift - Teriyaki Boyz\n");
    cetak("\t4. Kembali Ke Awal\033[0m\n\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur.data, sizeof(struktur.data), stdin);
    struktur.data[strcspn(struktur.data, "\n")] = 0;

    jika (strcmp(struktur.data, "1") == 0 || strcasecmp(struktur.data, "jkt48 - rapsodi") == 0) {
		PlaySoundA("rapsodi.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		sistemMenu();
	} kalau jika (strcmp(struktur.data, "2") == 0 || strcasecmp(struktur.data, "jkt48 - seventeen") == 0) {
		PlaySoundA("seventeen.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		sistemMenu();
    } kalau jika (strcmp(struktur.data, "3") == 0 || strcasecmp(struktur.data, "tokyo drift - teriyaki boyz") == 0) {
		PlaySoundA("tokyo_drift.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		sistemMenu();
    } kalau jika (strcmp(struktur.data, "4") == 0 || strcasecmp(struktur.data, "kembali ke awal") == 0) {
    	sistemMenu();
    } kalau {
        noticeDefault();
        pergi_ke Menu;
    }
}

void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 4 [Aplikasi Beta Sudah Dekat V3]\n\t");
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
    cetak("\n\t1. Program Inputan Data Pegawai\n");
    cetak("\033[0m\033[1;37m\t2. Program Hitung Biaya Parkir\n");
    cetak("\t3. Bintang 3\n");
    cetak("\t4. Ganti Lagu\n");
    cetak("\t5. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur._Menu, sizeof(struktur._Menu), stdin);
    struktur._Menu[strcspn(struktur._Menu, "\n")] = 0;

    jika (strcmp(struktur._Menu, "1") == 0 || strcasecmp(struktur._Menu, "program inputan data pegawai") == 0) {
    	dataPegawai();
    	sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "2") == 0 || strcasecmp(struktur._Menu, "program hitung biaya parkir") == 0) {
        biayaParkir();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "3") == 0 || strcasecmp(struktur._Menu, "bintang 3") == 0) {
        sistemLogoValo();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "4") == 0 || strcasecmp(struktur._Menu, "ganti lagu") == 0) {
        sistemMusik();
	} kalau jika (strcmp(struktur._Menu, "5") == 0 || strcasecmp(struktur._Menu, "keluar aplikasi") == 0) {
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

void laguRapsodi(){
	PlaySoundA("rapsodi.wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(240500);
}

void laguSeventeen(){
	PlaySoundA("seventeen.wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(220200);
}

void laguTokyoDrift(){
	PlaySoundA("tokyo_drift.wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(254500);
}

void alokasiMemoriUrutanPemutaran() {
    urutan_pemutaran = (int*)malloc(jumlah_lagu * sizeof(int));
    jika (urutan_pemutaran == NULL) {
    	FILE *file = fopen("error.txt", "a");
        fcetak(file, "[ERROR] Gagal mengalokasikan memori untuk urutan_pemutaran\n");
        fclose(file);
        threadCreationStatus = 1;
    }
}

void dealokasiMemoriUrutanPemutaran() {
    free(urutan_pemutaran);
}

void inisialisasiUrutanPemutaran() {
    for (int i = 0; i < jumlah_lagu; i++) {
        urutan_pemutaran[i] = i;
    }
    for (int i = jumlah_lagu - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = urutan_pemutaran[i];
        urutan_pemutaran[i] = urutan_pemutaran[j];
        urutan_pemutaran[j] = temp;
    }
}


void playMusik() {
	int pemutaran_selesai = 0;
    while (1) {
        int lagu_saat_ini = urutan_pemutaran[pemutaran_selesai];
        jika (lagu_saat_ini == 0) {
            laguRapsodi();
        } kalau jika (lagu_saat_ini == 1) {
            laguSeventeen();
        } kalau jika (lagu_saat_ini == 2) {
            laguTokyoDrift();
        }
        pemutaran_selesai++;
        jika (pemutaran_selesai == jumlah_lagu) {
            for (int i = 0; i < jumlah_lagu; i++) {
                urutan_pemutaran[i] = i;
            }
            for (int i = jumlah_lagu - 1; i > 0; i--) {
                int j = rand() % (i + 1);
                int temp = urutan_pemutaran[i];
                urutan_pemutaran[i] = urutan_pemutaran[j];
                urutan_pemutaran[j] = temp;
            }
            pemutaran_selesai = 0;
        }
    }
}

void *sistemPlay(void *arg) {
	srand(time(NULL));
    alokasiMemoriUrutanPemutaran();
    inisialisasiUrutanPemutaran();
    playMusik();
    return NULL;
}

void sistemInti() {
    pthread_t thread;
    jika (pthread_create(&thread, NULL, sistemPlay, NULL) != 0) {
        FILE *file = fopen("error.txt", "a");
        fcetak(file, "[ERROR] Gagal membuat thread untuk sistemPlay.\n");
        fclose(file);
        threadCreationStatus = 2;
    }
    jika (threadCreationStatus == 0) {
        sistemPembuka();
        sistemMenu();
    }
}
