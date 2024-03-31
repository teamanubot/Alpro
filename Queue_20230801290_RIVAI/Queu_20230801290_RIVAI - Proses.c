#include "Queu_20230801290_RIVAI - Pustaka.h"

void gerakGaris(char *kata, int jumlah) {
    int garis = jumlah;
    while (garis--) {
        printf("%s", kata);
        Sleep(5);
    }
}

void systemClose() {
	#ifdef _WIN32
    	system("CLS");
	#else
    	system("clear");
	#endif
}

void systemPause() {
    #ifdef _WIN32
        system("pause");
    #else
        system("read -p 'Press Enter to continue...' key");
    #endif
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
                if (i == 0 && buffer[i] == '-') {
                    continue;
                }
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

void getValidString(char input[]) {
    int valid = 0;
    do {
        if (fgets(input, 100, stdin) != NULL) {
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
                len--;
            }
			int hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(input[i])) {
                    hanyaEnter = 0;
                    break;
                }
            }
            if (hanyaEnter) {
                printf("Masukkan hanya huruf : ");
                continue;
            }
            valid = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(input[i]) && !isalpha(input[i])) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Masukkan hanya huruf dan spasi : ");
            }
        }
    } while (!valid);
}

void kapitalAwal(char str[]) {
    int i;
    int len = strlen(str);
    int wordStart = 1;
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (wordStart) {
                str[i] = toupper(str[i]);
                wordStart = 0;
            } else {
                str[i] = tolower(str[i]);
            }
        } else {
            wordStart = 1;
        }
    }
}

void noticeDefault() {
    printf("Masukkan Dengan Benar\n");
    printf("Silahkan Coba Lagi.\n");
    getch();
    systemClose();
}

void noticeExit(){
	systemClose();
    printf("Terima Kasih Telah Menggunakan >_<");
    exit;
}

/* Start Loket 1 */

void tampilkanInfoLoket(const struct Loket *loket, int nomorLoket) {
    printf("\nLoket [%d] : ", nomorLoket);
    if (loket[nomorLoket - 1].jumlahAntrian > 0) {
        for (int i = 0; i < loket[nomorLoket - 1].jumlahAntrian; ++i) {
            printf("%s", loket[nomorLoket - 1].antrian[i].nama);
            if (i < loket[nomorLoket - 1].jumlahAntrian - 1) {
                printf(", ");
            }
        }
        printf("\n");
        printf("Banyaknya Antrian di loket %d : %d\n", nomorLoket, loket[nomorLoket - 1].jumlahAntrian);
    } else {
        printf("Tidak ada antrian\n");
    }
}

void tambahAntrian1(struct Loket *loket) {
    systemClose();
    printf("Masukkan nomor loket untuk menambah antrian : ");
    int nomorLoket = getValidInt();
    if (nomorLoket >= 1 && nomorLoket <= MAX_LOKET) {
        printf("Masukkan nama untuk menambah antrian di loket %d : ", nomorLoket);
        getValidString(loket[nomorLoket - 1].antrian[loket[nomorLoket - 1].jumlahAntrian].nama);
        kapitalAwal(loket[nomorLoket - 1].antrian[loket[nomorLoket - 1].jumlahAntrian].nama);
        loket[nomorLoket - 1].jumlahAntrian++;
        printf("Antrian ditambahkan ke loket %d. Total antrian: %d\n", nomorLoket, loket[nomorLoket - 1].jumlahAntrian);
    } else {
        printf("Nomor loket tidak valid.\n");
    }
    systemPause();
}

void hapusAntrian1(struct Loket *loket) {
    systemClose();
    printf("Masukkan nomor loket untuk menghapus antrian : ");
    int nomorLoket = getValidInt();
    if (nomorLoket >= 1 && nomorLoket <= MAX_LOKET) {
        if (loket[nomorLoket - 1].jumlahAntrian != 0) {
            int jumlahAntrianSebelum = loket[nomorLoket - 1].jumlahAntrian;
            loket[nomorLoket - 1].jumlahAntrian = 0;
            printf("Antrian dihapus dari loket %d. Total antrian yang dihapus : %d\n", nomorLoket, jumlahAntrianSebelum);
        } else {
            printf("Tidak ada antrian untuk dihapus di loket %d.\n", nomorLoket);
        }
    } else {
        printf("Nomor loket tidak valid.\n");
    }
    systemPause();
}


void mainLoket1() {
    struct Loket loket[MAX_LOKET];
    for (int i = 0; i < MAX_LOKET; ++i) {
    	loket[i].jumlahAntrian = 0;
	}
Awal :
    systemClose();
    char _Menu[100];
    gerakGaris("=", 100);
    for (int i = 1; i <= MAX_LOKET; ++i) {
    	tampilkanInfoLoket(loket, i);
    }
    gerakGaris("=", 100);
    printf("\n\nMenu :\n");
    printf("1. Tambahkan Antrian\n");
	printf("2. Hapus Antrian\n");
	printf("3. Keluar Aplikasi\n");
	printf("Masukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;
    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "tambahkan antrian") == 0) {
    	tambahAntrian1(loket);
    	goto Awal;
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "hapus antrian") == 0) {
    	hapusAntrian1(loket);
    	goto Awal;
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
    	noticeDefault();
    	goto Awal;
	}
}

/* End Loket 1 */

/* Start Loket 2 */

void tambahAntrian2(struct Queue *queue) {
    systemClose();
    char nama[100];
    printf("Masukkan nama untuk menambah antrian : ");
    getValidString(nama);
    kapitalAwal(nama);
    if ((queue->rear + 1) % MAX_ANTRIAN == queue->front) {
        printf("Antrian penuh. Tidak dapat menambahkan antrian baru.\n");
    } else {
        int nomorAntrian = ++queue->nomorAntrianTerakhir;  // Simpan dan gunakan nomorAntrian yang telah disimpan
        strncpy(queue->antrian[queue->rear].nama, nama, MAX_NAMA - 1);
        queue->antrian[queue->rear].nomorAntrian = nomorAntrian;  // Simpan nomorAntrian pada antrian
        queue->rear = (queue->rear + 1) % MAX_ANTRIAN;
        queue->jumlahAntrian++;
        printf("Antrian no %d ditambahkan untuk %s.\n", nomorAntrian, nama);
    }
    systemPause();
}

void hapusAntrian2(struct Queue *queue) {
	systemClose();
    if (queue->front == queue->rear) {
        printf("Antrian kosong. Tidak ada antrian untuk dihapus.\n");
    } else {
        int nomorAntrian = queue->antrian[queue->front].nomorAntrian;  // Gunakan nomorAntrian yang telah disimpan
        printf("Antrian no %d (%s) telah dihapus.\n", nomorAntrian, queue->antrian[queue->front].nama);
        queue->front = (queue->front + 1) % MAX_ANTRIAN;
    }
    systemPause();
}

void cetakAntrian(const struct Queue *queue) {
	systemClose();
    if (queue->front == queue->rear) {
        printf("Antrian kosong.\n");
    } else {
    	gerakGaris("=", 5);
    	printf(" Antrian Saat Ini ");
    	gerakGaris("=", 5);
        printf("\n");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d. %s\n", i + 1, queue->antrian[i].nama);
            i = (i + 1) % MAX_ANTRIAN;
        }
    }
    systemPause();
}

void mainLoket2() {
    struct Queue antrianQueue;
    antrianQueue.front = 0;
    antrianQueue.rear = 0;
Awal :
    systemClose();
    char _Menu[100];
    char nama[MAX_NAMA];
    gerakGaris("=", 5);
    printf(" Menu ");
    gerakGaris("=", 5);
    printf("\n");
    printf("1. Tambah Antrian\n");
    printf("2. Hapus Antrian\n");
    printf("3. Cetak Antrian\n");
    printf("4. Keluar Aplikasi\n");
    printf("Masukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;
    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "tambah antrian") == 0) {
    	tambahAntrian2(&antrianQueue);
    	goto Awal;
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "hapus antrian") == 0) {
    	hapusAntrian2(&antrianQueue);
    	goto Awal;
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "cetak antrian") == 0) {
    	cetakAntrian(&antrianQueue);
    	goto Awal;
    } else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
    	noticeDefault();
    	goto Awal;
	}
}

/* End Loket 2 */

/* Start Dinamis */

void tampilkanHeader() {
    gerakGaris("-", 30);
    printf("\n");
    printf("\n        Barber Pop\n");
    printf("Jl. Perhatian Blok I No. 3U\n\n");
    gerakGaris("-", 30);
    printf("\n\n");
}

void tampilkanMenu() {
    printf("    ");
    gerakGaris("-", 8);
	printf(" MENU ");
	gerakGaris("-", 8);
	printf("\n");
    printf("     1. Daftar Antrian\n");
    printf("     2. Hapus Antrian\n");
    printf("     3. Daftar Tunggu\n");
    printf("     4. Pendapatan\n");
    printf("     5. Keluar Aplikasi\n\n");
    gerakGaris("-", 30);
	printf("\n\n");
}

void tambahAntrian3(struct BarberShop *barberShop) {
	systemClose();
	char nama[100];
	printf("Masukkan nama untuk menambah antrian : ");
    getValidString(nama);
    kapitalAwal(nama);
    if (barberShop->jumlahAntrian < MAX_ANTRIAN) {
        struct Antrian newAntrian;
        barberShop->nomorAntrianTerakhir++;
        newAntrian.nomorAntrian = barberShop->nomorAntrianTerakhir;
        strncpy(newAntrian.nama, nama, MAX_NAMA - 1);
        barberShop->antrian[barberShop->jumlahAntrian] = newAntrian;
        barberShop->jumlahAntrian++;
		gerakGaris("-", 30);
		printf("\n");
        printf("No. Antrian : %d\n", newAntrian.nomorAntrian);
        printf("Nama        : %s\n", newAntrian.nama);
        gerakGaris("-", 30);
		printf("\n\n");
    } else {
        printf("Antrian penuh. Tidak dapat menambahkan antrian baru.\n\n");
    }
    systemPause();
}

void hapusAntrian3(struct BarberShop *barberShop) {
	systemClose();
    if (barberShop->jumlahAntrian > 0) {
    	char pilihan[100];
        printf("Eksekutor :\n");
        printf("1. Anti\n");
        printf("2. Bella\n");
        printf("3. Citra\n");
        printf("Pilihan Eksekutor : ");
        fgets(pilihan, sizeof(pilihan), stdin);
        pilihan[strcspn(pilihan, "\n")] = 0;
        if (strcmp(pilihan, "1") == 0 || strcmp(pilihan, "2") == 0 || strcmp(pilihan, "3") == 0 || strcasecmp(pilihan, "anti") == 0 || strcasecmp(pilihan, "bella") == 0 || strcasecmp(pilihan, "citra") == 0) {
        	struct Antrian removedAntrian = barberShop->antrian[0];
            printf("\n");
            gerakGaris("-", 30);
			printf("\n");
            printf("No. Antrian : %d\n", removedAntrian.nomorAntrian);
            printf("Nama        : %s\n", removedAntrian.nama);
            if (strcmp(pilihan, "1") == 0 || strcasecmp(pilihan, "anti") == 0) {
            	printf("Eksekutor   : Anti\n");
            	gerakGaris("-", 30);
				printf("\n\n");
                barberShop->pendapatan[0] += 12000;
                barberShop->pendapatanMitra += 8000;
            } else if (strcmp(pilihan, "2") == 0 || strcasecmp(pilihan, "bella") == 0) {
            	printf("Eksekutor   : Bella\n");
            	gerakGaris("-", 30);
				printf("\n\n");
                barberShop->pendapatan[1] += 12000;
                barberShop->pendapatanMitra += 8000;
            } else if (strcmp(pilihan, "3") == 0 || strcasecmp(pilihan, "citra") == 0) {
            	printf("Eksekutor   : Citra\n");
            	gerakGaris("-", 30);
				printf("\n\n");
                barberShop->pendapatan[2] += 12000;
                barberShop->pendapatanMitra += 8000;
            }
            for (int i = 0; i < barberShop->jumlahAntrian - 1; i++) {
                barberShop->antrian[i] = barberShop->antrian[i + 1];
            }
            barberShop->jumlahAntrian--;
        } else {
            printf("Pilihan eksekutor tidak valid.\n\n");
        }
    } else {
        printf("Antrian kosong. Tidak ada antrian untuk dihapus.\n\n");
    }
    systemPause();
}

void daftarTunggu(const struct BarberShop *barberShop) {
	systemClose();
	int sisaAntrian = 0;
	gerakGaris("-", 8);
    printf(" Data Antrian ");
	gerakGaris("-", 8);
	printf("\n\n");
    if (barberShop->jumlahAntrian != 0){
    	for (int i = 0; i < barberShop->jumlahAntrian; i++) {
        	printf("No. Antrian    : %d\n", barberShop->antrian[i].nomorAntrian);
        	printf("Nama           : %s\n", barberShop->antrian[i].nama);
        	printf("Sisa Antrian   : %d\n", sisaAntrian);
        	gerakGaris("-", 30);
			printf("\n\n");
        	sisaAntrian++;
    	}
    	printf("Jumlah Antrian : %d\n\n", barberShop->jumlahAntrian);
   		gerakGaris("-", 30);
		printf("\n\n");
   	} else {
   		printf("Sedang Sepi\n\n");
   		gerakGaris("-", 30);
		printf("\n\n");
   	}
   	systemPause();
}

void tampilkanPendapatan(const struct BarberShop *barberShop) {
	systemClose();
	gerakGaris("-", 8);
    printf(" Pendapatan ");
	gerakGaris("-", 8);
	printf("\n");
    printf("keuntungan Mitra : Rp. %d,-\n", barberShop->pendapatanMitra);
    printf("- Anti           : Rp. %d,-\n", barberShop->pendapatan[0]);
    printf("- Bella          : Rp. %d,-\n", barberShop->pendapatan[1]);
    printf("- Citra          : Rp. %d,-\n", barberShop->pendapatan[2]);
	gerakGaris("-", 30);
	printf("\n\n");
	systemPause();
}

void mainDinamis() {
    struct BarberShop barberShop;
    barberShop.jumlahAntrian = 0;
    barberShop.pendapatan[0] = 0;
    barberShop.pendapatan[1] = 0;
    barberShop.pendapatan[2] = 0;
    barberShop.pendapatanMitra = 0;
    barberShop.nomorAntrianTerakhir = 0;
Awal :
	systemClose();
    char _Menu[100];
    char nama[MAX_NAMA];
    tampilkanHeader();
	tampilkanMenu();
    printf("Masukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;
    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "daftar antrian") == 0) {
    	tambahAntrian3(&barberShop);
    	goto Awal;
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "hapus antrian") == 0) {
    	hapusAntrian3(&barberShop);
    	goto Awal;
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "daftar tunggu") == 0) {
    	daftarTunggu(&barberShop);
    	goto Awal;
    } else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "pendapatan") == 0) {
    	tampilkanPendapatan(&barberShop);
    	goto Awal;
    } else if (strcmp(_Menu, "5") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
    	noticeDefault();
    	goto Awal;
	}
}

/* End Dinamis */
