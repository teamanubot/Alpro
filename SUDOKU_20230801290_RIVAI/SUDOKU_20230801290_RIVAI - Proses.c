#include "SUDOKU_20230801290_RIVAI - Pustaka.h"

int getValidInt() {
    char buffer[100];
    int validInput, value;
    do {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len == 2 && isdigit(buffer[0]) && buffer[1] == '\n') {
                validInput = 1;
                sscanf(buffer, "%d", &value);
            } else {
                validInput = 0;
                printf("Masukkan Satu Angka Saja : ");
            }
        }
    } while (!validInput);
    return value;
}

void sudoku() {
    int baris, kolom, temp[100], percobaan = 0;
    Sudoku[0][0].isi = 1;
    Sudoku[0][1].isi = 4;
    Sudoku[0][2].isi = 2;
    Sudoku[0][3].isi = 3;
    Sudoku[1][0].isi = 2;
    Sudoku[1][1].isi = 3;
    Sudoku[1][2].isi = 4;
    Sudoku[1][3].isi = 1;
    Sudoku[2][0].isi = 4;
    Sudoku[2][1].isi = 1;
    Sudoku[2][2].isi = 3;
    Sudoku[2][3].isi = 2;
    Sudoku[3][0].isi = 3;
    Sudoku[3][1].isi = 2;
    Sudoku[3][2].isi = 1;
    Sudoku[3][3].isi = 4;
    Sudoku[0][0].status = 1;
    Sudoku[1][1].status = 1;
    Sudoku[2][0].status = 1;
    Sudoku[3][1].status = 1;
    Sudoku[3][3].status = 1;
    do {
        temp[2] = 1;
        coba = 0;
        system("CLS");
        for (baris = 0; baris < 4; baris++) {
            for (kolom = 0; kolom < 4; kolom++) {
                if (Sudoku[baris][kolom].status != 1) {
                    printf("* ");
                } else {
                    printf("%d ", Sudoku[baris][kolom].isi);
                }
            }
            printf("\n");
        }
        printf("\n");
        if(percobaan == 0) {
        	printf("Tebak Angka Sudoku, Akan terisi otomatis jika benar\n");
        } else {
        	printf("Anda sudah melakukan %dx percobaan\n", percobaan);
		}
        printf("===================================\n");
        for(baris = 0; baris < 4; baris++) {
            for(kolom = 0; kolom < 4; kolom++) {
                temp[1] = 0;
                if (Sudoku[baris][kolom].status != 1) {
                    printf("Masukkan Angka Baris %d Kolom %d : ", baris + 1, kolom + 1);
                    temp[1] = getValidInt();
                    if (temp[1] == Sudoku[baris][kolom].isi) {
                        Sudoku[baris][kolom].status = 1;
                    }
                }
            }
        }
        for(baris = 0; baris < 4; baris++) {
            for(kolom = 0; kolom < 4; kolom++) {
                if((temp[2] == 1) && (Sudoku[baris][kolom].status == 1)) {
                    temp[2] = 1;
                } else {
                    temp[2] = 0;
                }
            }
        }
        coba = temp[2];
        percobaan += 1;
    } while (coba != 1);
    system("CLS");
    for (baris = 0; baris < 4; baris++) {
        for (kolom = 0; kolom < 4; kolom++) {
            printf("%d ", Sudoku[baris][kolom].isi);
        }
        printf("\n");
    }
    if(percobaan == 0 || percobaan == 1) {
    	printf("Selamat kamu berhasil menyelesaikan permainan Sudoku tanpa melakukan pengulangan jawaban\n");
    } else {
    	printf("Selamat kamu berhasil menyelesaikan permainan Sudoku pada percobaan ke-%d\n", percobaan);
	}
    printf("\n");
    system("Pause");
}

void playSudoku() {
    printf("Sudoku Game Beta V1\n");
    printf("_________________\n\n");
    printf("Permainan Sudoku ini berbasis Matrik berordo 4x4,\nDimana jawaban telah ditentukan didalamnya.\nSelamat Bermain ^.^\n\n");
    system("Pause");
    sudoku();
}
