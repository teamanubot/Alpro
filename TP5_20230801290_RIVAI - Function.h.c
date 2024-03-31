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

void waktuDanTanggal();

pthread_t thread;

void noticeDefault() {
	FILE *file = fopen("error.txt", "a");
    fcetak(file, "[ERROR] Kesalahan Saat Menginput Pada Menu\n");
	fclose(file);
    cetak("\t\033[1;32mMasukkan Dengan Benar\n");
    cetak("\tSilahkan Coba Lagi.\033[0m\n");
    getch();
    sistem("CLS");
}

void noticeExit(){
	sistem("CLS");
    waktuDanTanggal();
    cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
    keluar(0);
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
	cetak("\n\033[1;34m\t");
	
	i = 0;
	do {
		j = 0;
		do {
			jika (i >= j || i + j >= 2 * n - 1) {
                cetak("%s ", a);
            } kalau {
                cetak("  ");
        	}
        	j++;
		} while (j < 2 * n);
		cetak("\n\t");
		i++;
	} while (i < n);
	i = 0;
	do {
		j = 0;
		do {
			jika (i >= j || i + j >= 2 * n - 1) {
                cetak("  ");
            } kalau {
                cetak("%s ", a);
        	}
        	j++;
		} while (j < 2 * n);
		cetak("\n\t");
		i++;
	} while (i < n);
    cetak("\033[0m\n\n");
}

void sistemBintang4(){
	sistem("CLS");
	int i, j, n;
	char a[100];
	cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tProgram Bintang 4\n\t");
    gerakGaris();
	cetak("\033[0m\033[1;32m\n\tMasukkan Inputan Huruf/Angka/Simbol : ");
	getValid(a);
	cetak("\033[1;32m\tMasukkan Inputan Angka (Batas) : ");
	n = getValidInt();
	cetak("\n\033[1;34m\t");
	
	i = 2;
	do {
		j = 1;
        while (j <= n - i) {
            cetak("_");
            j++;
        }
        j = 1;
        while (j <= i) {
            cetak("%s", a);
            j++;
        }
        j = 1;
        while (j <= n) {
            cetak("_");
            j++;
        }
        j = 1;
        while (j <= i) {
            cetak("%s", a);
            j++;
    	}
        cetak("\n\t");
        i++;
    } while (i <= n);

	i = 1;
    do {
    	j = 1;
		do {
			cetak("_");
			j++;
		} while(j <= n + (i - 1));
		j = 1;
		do {
			cetak("%s", a);
			j++;
		} while(j <= n - 2 * (i - 1));
		cetak("\n\t");
		i++;
	} while(i <= 2);
    cetak("\033[0m\n\n");
}

void sistemHurufM(){
	sistem("CLS");
    int tinggi;
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tProgram Huruf M\n\t");
    gerakGaris();
    cetak("\n\t\033[1;32mMasukkan tinggi M: ");
    tinggi = getValidInt();
	cetak("\n\033[1;34m\t");
	
    jika (tinggi < 3) {
        cetak("\033[1;32mTinggi M minimal 3\033[0m\033");
        keluar;
    }

    int lebar = (2 * tinggi) - 1;
    int i,j;

	i = 0;
    do {
    	j = 0;
        do {
            jika (j == 0 || j == lebar - 1 || j == i || j == (lebar - 1) - i) {
                cetak("*");
            } kalau {
                cetak(" ");
            }
            j++;
        } while (j < lebar);
        cetak("\n\t");
        i++;
    } while (i < tinggi);
    cetak("\033[0m\n\n");
}

void sistemTrapesium(){
	sistem("CLS");
    int i, j, n;
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tProgram Trapesium\n\t");
    gerakGaris();
    cetak("\n\t\033[1;32mMasukkan Angka: ");
    n = getValidInt();
	cetak("\n\033[1;34m\t");

	i = 1;
    do {
    	j = (n - 2);
		while (j >= i) {
			cetak("  ");
			j--;
		}
		j = 0;
		while (j <= i) {
			cetak("* ");
			j++;
		}
		j = n;
		while (j >= 1) {
			cetak("^ ");
			j--;
		}
		j = 0;
		while (j <= i) {
			cetak("* ");
			j++;
		}
		cetak("\n\t");
		i++;
	} while (i <= (n - 1));
    cetak("\033[0m\n\n");
}

void sistemJamPasir(){
	sistem("CLS");
    int i, j, tinggi, spasi;
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tProgram Jam Pasir\n\t");
    gerakGaris();
    cetak("\n\t\033[1;32mMasukkan tinggi M: ");
    tinggi = getValidInt();
	cetak("\n\033[1;34m\t");
	
    jika (tinggi % 2 == 0) {
        cetak("\033[1;32mTinggi harus merupakan bilangan ganjil.\033[0m\033");
        keluar;
    }

	i = 1;
    do {
    	j = 1;
        do {
            jika (i <= tinggi / 2) {
                jika (j == 1 || j == tinggi || i == 1) {
                    cetak(" *");
                } kalau {
                    cetak("  ");
                }
        	}
        	j++;
        } while (j <= tinggi);
        cetak("\n\t");
        i++;
	} while (i <= tinggi - (1 + i));

	i = 0;
    do {
    	j = 0;
        while (j < i) {
            cetak(" ");
            j++;
        }
        j = 0;
        while (j < tinggi - i) {
            cetak(" -");
            j++;
        }
        cetak("\n\t");
        i++;
    } while (i < tinggi);

	i = tinggi - 1;
    do {
    	j = 0;
        while (j < i) {
            cetak(" ");
            j++;
        }
        j = 1;
        while (j <= tinggi - i) {
            cetak(" -");
            j++;
        }      
        cetak("\n\t");
        i--;
    } while (i >= 0);

	i = tinggi / 2 + 2;
    do {
    	j = 1;
        do {
            jika (i == tinggi || j == 1 || j == tinggi) {
                cetak(" *");
            } kalau {
                cetak("  ");
            }
            j++;
        } while (j <= tinggi);
        cetak("\n\t");
        i++;
    } while (i <= tinggi);
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

void sistemLogin(){
	cetak("\033[0m\n");
    int attempts, login, maxAttempts = 3, loginmax = 3;
    char username[100], password[100], inputUsername[100], inputPassword[100], dup[100];
	FILE *dataFile, *logFile;
	dataFile = fopen("data.txt", "r");

	jika (dataFile == NULL) {
		cetak("\033[1;33m\n\tWelcome, ");
    	return;
    } kalau {
    	logFile = fopen("login.txt", "r");
    	fscanf(dataFile, "%s : %s", dup, username);
    	fscanf(dataFile, "%s : %s", dup, password);
    	fscanf(logFile, "[ERROR] Gagal Login : %d", &login);
    	fseek(dataFile, 0, SEEK_END);
        long file_size = ftell(dataFile);
        jika (file_size < 26){
        	fclose(dataFile);
    		cetak("\033[1;33m\n\tWelcome, ");
    		return;
		}
    	fclose(dataFile);
    	fclose(logFile);

		jika (login >= loginmax) {
        	cetak("\t\033[1;32mAnda telah melebihi batas percobaan untuk login jadi dibanned.\n\tProgram akan keluar~\n\n");
        	keluar(0);
    	}
    
    	while (attempts < maxAttempts) {
        	do {
            	cetak("\t\033[1;32mMasukkan username : ");
            	jika (fgets(inputUsername, sizeof(inputUsername), stdin) != NULL) {
                	inputUsername[strcspn(inputUsername, "\n")] = '\0';
            	}
        	} while (strlen(inputUsername) == 0);
        	do {
            	cetak("\t\033[0m\033[1;32mMasukkan password : ");
            	int i = 0;
            	char ch;
        		while (1) {
            		ch = _getch();
            		jika (ch == 13) {
                		inputPassword[i] = '\0';
                		break;
            		} kalau jika (ch == 8) {
                		jika (i > 0) {
                    		i--;
                    		cetak("\b \b");
                		}
            		} kalau {
                		inputPassword[i] = ch;
                		i++;
                		cetak("*");
            		}
        		}
        		cetak("\n");
        	} while (strlen(inputPassword) == 0);
        
        	jika (strcmp(inputUsername, username) == 0 && strcmp(inputPassword, password) == 0) {
            	cetak("\n\t\033[0m\033[1;32m[Login sukses] Selamat datang, %s\n\t", username);
            	remove("login.txt");
            	break;
        	} kalau {
            	attempts++;
            	jika (maxAttempts - attempts != 0) {
            		cetak("\n\t\033[0m\033[1;32m[Login gagal] Sisa percobaan : %d\n", maxAttempts - attempts);
            	} kalau {
            		cetak("\n\t\033[0m\033[1;32m[Login gagal] Sisa percobaan telah habis\n");
				}
        	}
    	}

    	jika (attempts == maxAttempts) {
        	login++;
        	logFile = fopen("login.txt", "w");
        	jika (logFile != NULL) {
            	fcetak(logFile, "[ERROR] Gagal Login : %d", login);
            	fclose(logFile);
        	}
        	cetak("\t\033[0m\033[1;32mAnda telah melebihi batas percobaan.\n\tProgram akan keluar~\n\n");
        	keluar(0);
    	}
	}
}

void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 5 [Aplikasi Beta Sudah Dekat V4]\n\t");
    gerakGaris();
    cetak("\n\tNama\t : Rivai\n");
    cetak("\tNIM\t : 20230801290\n\t");
    gerakGaris();
    sistemLogin();
    jika (pthread_create(&thread, NULL, sistemPlay, NULL) != 0) {
        FILE *file = fopen("error.txt", "a");
        fcetak(file, "[ERROR] Gagal membuat thread untuk sistemPlay.\n");
        fclose(file);
        threadCreationStatus = 2;
    }
    sistem("PAUSE");
    jika (threadCreationStatus == 0) {
        sistemMenu();
    }
}

void sistemMenu(){
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tAplikasi Beta Sudah Dekat V4\n\t");
    gerakGaris();
    cetak("\n\t1. Bintang 3\n");
    cetak("\t2. Bintang 4\n");
    cetak("\033[0m\033[1;37m\t3. Huruf M\n");
    cetak("\t4. Trapesium\n");
    cetak("\t5. Jam Pasir\n");
    cetak("\t6. Ganti Lagu\n");
    cetak("\t7. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur._Menu, sizeof(struktur._Menu), stdin);
    struktur._Menu[strcspn(struktur._Menu, "\n")] = 0;

    jika (strcmp(struktur._Menu, "1") == 0 || strcasecmp(struktur._Menu, "bintang 3") == 0) {
    	sistemLogoValo();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "2") == 0 || strcasecmp(struktur._Menu, "bintang 4") == 0) {
        sistemBintang4();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "3") == 0 || strcasecmp(struktur._Menu, "huruf m") == 0) {
        sistemHurufM();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "4") == 0 || strcasecmp(struktur._Menu, "trapesium") == 0) {
        sistemTrapesium();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "5") == 0 || strcasecmp(struktur._Menu, "jam pasir") == 0) {
        sistemJamPasir();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "6") == 0 || strcasecmp(struktur._Menu, "ganti lagu") == 0) {
        sistemMusik();
	} kalau jika (strcmp(struktur._Menu, "7") == 0 || strcasecmp(struktur._Menu, "keluar aplikasi") == 0) {
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
    jika (threadCreationStatus == 0) {
    	sistemMenu();
    }
}
