#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX_LOKET 5
#define MAX_NAMA 50

struct Loket {
    char nama[MAX_NAMA];
    int antrian;
};

void tampilkanInfoLoket(const struct Loket *loket, int nomorLoket) {
    printf("Loket [%d] : ", nomorLoket);

    if (loket[nomorLoket - 1].antrian > 0) {
        printf("%s,\n", loket[nomorLoket - 1].nama);
        printf("Banyaknya Antrian di loket %d : %d\n", nomorLoket, loket[nomorLoket - 1].antrian);
    } else {
        printf("Tidak ada antrian\n");
    }
}

void tambahAntrian(struct Loket *loket, int nomorLoket) {
    if (nomorLoket >= 1 && nomorLoket <= MAX_LOKET) {
        printf("Masukkan nama untuk menambah antrian di loket %d: ", nomorLoket);
        scanf("%s", loket[nomorLoket - 1].nama);

        loket[nomorLoket - 1].antrian = 1;

        printf("Antrian ditambahkan ke loket %d. Total antrian: %d\n", nomorLoket, loket[nomorLoket - 1].antrian);
    } else {
        printf("Nomor loket tidak valid.\n");
    }
}

void hapusAntrian(struct Loket *loket, int nomorLoket) {
    if (nomorLoket >= 1 && nomorLoket <= MAX_LOKET) {
        if (loket[nomorLoket - 1].antrian >= 1) {
            loket[nomorLoket - 1].antrian = 0;
            printf("Antrian dihapus dari loket %d. Total antrian: %d\n", nomorLoket, loket[nomorLoket - 1].antrian);
        } else {
            printf("Tidak ada antrian untuk dihapus di loket %d.\n", nomorLoket);
        }
    } else {
        printf("Nomor loket tidak valid.\n");
    }
}

void systemClose() {
	#ifdef _WIN32
    	system("CLS");
	#else
    	system("clear");
	#endif
}

int main() {
    struct Loket loket[MAX_LOKET];
    int menu;
    
    for (int i = 0; i < MAX_LOKET; ++i) {
        loket[i].antrian = 0;
    }
    
    do {
    	systemClose();
		
    	for (int i = 1; i <= MAX_LOKET; ++i) {
            tampilkanInfoLoket(loket, i);
        }
    	
        printf("\nMenu :\n");
        printf("1. Tambahkan Antrian\n");
        printf("2. Hapus Antrian\n");
        printf("3. Keluar Aplikasi\n");
        printf("Pilih Menu : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Masukkan nomor loket untuk menambah antrian: ");
                int nomorTambah;
                scanf("%d", &nomorTambah);
                tambahAntrian(loket, nomorTambah);
                break;

            case 2:
                printf("Masukkan nomor loket untuk menghapus antrian: ");
                int nomorHapus;
                scanf("%d", &nomorHapus);
                hapusAntrian(loket, nomorHapus);
                break;

            case 3:
                printf("Keluar dari aplikasi.\n");
                break;

            default:
                printf("Opsi tidak valid. Silakan masukkan opsi yang benar.\n");
                break;
        }
    } while (menu != 3);

    return 0;
}
