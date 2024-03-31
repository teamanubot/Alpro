#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Deklarasi variabel global
int mitra = 0;
int anti = 0;
int bella = 0;
int citra = 0;

// Struktur data antrian
typedef struct {
    int num;
    char name[36]; // Gunakan array karakter untuk menyimpan nama
} QueueItem;

// Deklarasi fungsi
void createQueue(QueueItem **queue) {
    *queue = malloc(sizeof(QueueItem));
    (*queue)->num = 0;
}

void add(int num, char *name, QueueItem **queue) {
    int size = (*queue)->num;
    *queue = realloc(*queue, (size + 1) * sizeof(QueueItem));
    if (*queue == NULL) {
        fprintf(stderr, "Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    (*queue)[size].num = num;
    strcpy((*queue)[size].name, name); // Gunakan strcpy untuk menyalin nama ke dalam struktur
    (*queue)->num = size + 1;
}

bool isEmpty(QueueItem *queue) {
    return (queue->num == 0);
}

void del(QueueItem **queue) {
    int size = (*queue)->num;
    if (size > 0) {
        (*queue)->num = size - 1;
        *queue = realloc(*queue, (size - 1) * sizeof(QueueItem));
        if (*queue == NULL && size > 1) {
            fprintf(stderr, "Error reallocating memory.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printQueue(QueueItem *queue) {
    int size = queue->num;
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            printf("No. Antrian : %d\n", queue[i].num);
            printf("Nama        : %s\n", queue[i].name);
        }
    } else {
        printf("Antrian Kosong\n");
    }
}

int main() {
    QueueItem *local_14 = NULL;
    int local_38 = 1;
    char local_5c[36];
    int local_30;

    do {
        printf("-------------------------------\n");
        printf("\n");
        printf("\tBarber Pop\n");
        printf("Jl. Perhatian Blok I No. 3U\n\n");
        printf("\n-------------------------------\n");
        printf("    --------MENU-------\n");
        printf("     1. Daftar Antrian\n");
        printf("     2. Hapus\n");
        printf("     3. Daftar Tunggu\n");
        printf("     4. Pendapatan\n");
        printf("     5. Keluar\n\n");
        printf("-------------------------------\n\n");
        printf("Masukkan Pilihan: ");
        if (scanf("%d", &local_30) != 1) {
            fprintf(stderr, "Error reading input.\n");
            exit(EXIT_FAILURE);
        }

        switch (local_30) {
            case 1:
                printf("No. Antrian : %d\n", local_38);
                printf("Nama        : ");
                fflush(stdout);
                if (scanf("%s", local_5c) != 1) {
                    fprintf(stderr, "Error reading input.\n");
                    exit(EXIT_FAILURE);
                }
                add(local_38, local_5c, &local_14);
                local_38 = local_38 + 1;
                getchar(); // Tambahkan getchar untuk menunggu Enter
                break;
            case 2:
                if (isEmpty(local_14)) {
                    printf("Antrian Masih Kosong\n\n");
                } else {
                    printf("Eksekutor :\n");
                    printf("1. Anti\n");
                    printf("2. Bella\n");
                    printf("3. Citra\n\n");
                    printf("Pilihan   : ");
                    if (scanf("%d", &local_30) != 1) {
                        fprintf(stderr, "Error reading input.\n");
                        exit(EXIT_FAILURE);
                    }

                    if (local_30 >= 1 && local_30 <= local_14->num) {
                        printf("\n-------------------------------\n");
                        printf("No. Antrian : %d\n", local_14[local_30 - 1].num);
                        printf("Nama        : %s\n", local_14[local_30 - 1].name);

                        // Tambahkan logika untuk mengupdate pendapatan sesuai dengan eksekutor
                        // mitra = mitra + 8000;
                        // anti = anti + 12000;

                        del(&local_14);
                        printf("-------------------------------\n");
                    } else {
                        printf("Pilihan tidak valid\n");
                    }
                }
                getchar(); // Tambahkan getchar untuk menunggu Enter
                break;
            case 3:
                printf("------- Data Antrian -------\n\n");
                printQueue(local_14);
                printf("\n----------------------------\n");
                getchar(); // Tambahkan getchar untuk menunggu Enter
                break;
            case 4:
                printf("-------- Pendapatan --------\n");
                printf("keuntungan Mitra\t:Rp. %d,-", mitra);
                printf("\n- Anti    :Rp. %d,-\n", anti);
                printf("- Bella   :Rp. %d,-\n", bella);
                printf("- Citra   :Rp. %d,-\n", citra);
                printf("\n----------------------------\n");
                getchar(); // Tambahkan getchar untuk menunggu Enter
                break;
            case 5:
                // Tidak melakukan exit(0) di sini agar program tetap berjalan setelah keluar
                break;
            default:
                printf("Pilihan tidak valid\n");
                getchar(); // Tambahkan getchar untuk menunggu Enter
                break;
        }
    } while (local_30 != 5);

    free(local_14);
    return 0;
}
