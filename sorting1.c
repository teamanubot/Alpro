#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compareString(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void capitalizeFirstLetter(char *word) {
    if (word[0] != '\0') {
        word[0] = toupper(word[0]);
    }
}

int main() {
    int n;
    printf("Masukkan banyak kata : ");
    scanf("%d", &n);
    char **words = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        words[i] = (char *)malloc(100 * sizeof(char));
        printf("Masukkan kata : ");
        scanf("%s", words[i]);
        capitalizeFirstLetter(words[i]);
    }
    printf("\n\n");
    qsort(words, n, sizeof(char *), compareString);
    char currentChar = '\0';
    for (int i = 0; i < n; i++) {
        if (words[i][0] != currentChar) {
            if (i != 0) {
                printf("----------------\n");
            }
            currentChar = words[i][0];
        }
        printf("%s\n", words[i]);
    }
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}
