#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// fungsi untuk membuat jam terus bergerak
void *jam(void *arg) {
    // variabel untuk menyimpan jam, menit, dan detik
    int jam, menit, detik;

    // variabel untuk menyimpan jumlah detik yang telah berlalu
    long int waktu;

    // loop tanpa henti
    while (1) {
        // mendapatkan jumlah detik yang telah berlalu sejak program dimulai
        waktu = clock();

        // menghitung jam, menit, dan detik saat ini
        jam = (waktu / CLOCKS_PER_SEC) / 3600;
        menit = ((waktu / CLOCKS_PER_SEC) % 3600) / 60;
        detik = (waktu / CLOCKS_PER_SEC) % 60;

        // menampilkan jam, menit, dan detik saat ini di layar
        printf("\rJam: %02d Menit: %02d Detik: %02d", jam, menit, detik);

        // mengosongkan buffer output agar tidak tertunda
        fflush(stdout);
    }
}

int main() {
    // variabel untuk menyimpan thread id
    pthread_t tid1, tid2;

    // membuat thread pertama yang menjalankan fungsi jam
    pthread_create(&tid1, NULL, jam, NULL);

    // menunggu thread pertama selesai
    pthread_join(tid1, NULL);

    // menunggu thread kedua selesai
    pthread_join(tid2, NULL);

    return 0;
}
