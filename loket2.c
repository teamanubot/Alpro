#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX_NAMA 50
#define MAX_ANTRIAN 10

struct Antrian {
    char nama[MAX_NAMA];
};

struct Queue {
    struct Antrian antrian[MAX_ANTRIAN];
    int front, rear;
    int jumlahAntrian;
};

void systemClose() {
	#ifdef _WIN32
    	system("CLS");
	#else
    	system("clear");
	#endif
}

void tambahAntrian(struct Queue *queue, const char *nama) {
    if ((queue->rear + 1) % MAX_ANTRIAN == queue->front) {
        printf("Antrian penuh. Tidak dapat menambahkan antrian baru.\n");
    } else {
        strncpy(queue->antrian[queue->rear].nama, nama, MAX_NAMA - 1);
        queue->rear = (queue->rear + 1) % MAX_ANTRIAN;
        queue->jumlahAntrian++;
        printf("Antrian no %d ditambahkan untuk %s.\n", queue->jumlahAntrian, nama);
    }
}

void hapusAntrian(struct Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Antrian kosong. Tidak ada antrian untuk dihapus.\n");
    } else {
        printf("Antrian no %d (%s) telah dihapus.\n", queue->jumlahAntrian - (queue->rear - queue->front) + 1, queue->antrian[queue->front].nama);
        queue->front = (queue->front + 1) % MAX_ANTRIAN;
    }
}

void cetakAntrian(const struct Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Antrian kosong.\n");
    } else {
        printf("===== Antrian Saat Ini =====\n");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d. %s\n", i + 1, queue->antrian[i].nama);
            i = (i + 1) % MAX_ANTRIAN;
        }
    }
}

int main() {
    struct Queue antrianQueue;
    antrianQueue.front = 0;
    antrianQueue.rear = 0;

    int menu;
    char nama[MAX_NAMA];

    do {
    	systemClose();
        printf("===== Menu =====\n");
        printf("1. Tambah Antrian\n");
        printf("2. Hapus Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilih Menu : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
            	systemClose();
                printf("Masukkan nama untuk menambah antrian: ");
                scanf("%s", nama);
                tambahAntrian(&antrianQueue, nama);
                system("PAUSE");
                break;

            case 2:
            	systemClose();
                hapusAntrian(&antrianQueue);
                system("PAUSE");
                break;

            case 3:
            	systemClose();
                cetakAntrian(&antrianQueue);
                system("PAUSE");
                break;

            case 4:
            	systemClose();
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Opsi tidak valid. Silakan masukkan opsi yang benar.\n");
                break;
        }

    } while (menu != 4);

    return 0;
}

