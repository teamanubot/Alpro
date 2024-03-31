#include "lib.vokal.h"

void vokal() {
    char string[100];
    int vokal = 0;
    
    printf("Masukkan sebuah string: ");
    fgets(string, sizeof(string), stdin);

    for (int i = 0; i < strlen(string); i++) {
        char ch = string[i];
        
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
            vokal++;
        }
    }

    printf("Jumlah huruf vokal dalam string adalah: %d\n", vokal);

    return;
}
