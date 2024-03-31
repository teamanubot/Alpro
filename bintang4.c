/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>

int main() {
    int height;
    
    printf("Masukkan tinggi M: ");
    scanf("%d", &height);

    if (height < 3) {
        printf("Tinggi M minimal 3\n");
        return 1;
    }

    int width = (2 * height) - 1;
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (j == 0 || j == width - 1 || j == i || j == (width - 1) - i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

