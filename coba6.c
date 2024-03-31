#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

int main() {
    const char* wavFilePath = "example.wav"; // Ganti dengan path file WAV yang ingin Anda putar

    if (PlaySoundA(wavFilePath, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)) {
        printf("Audio sedang diputar. Tekan Enter untuk menghentikan...");
        getchar();
        PlaySoundA(NULL, 0, 0); // Menghentikan pemutaran
    } else {
        printf("Gagal memutar audio.");
    }

    return 0;
}
