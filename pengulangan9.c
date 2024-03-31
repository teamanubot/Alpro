#include <stdio.h>

int main(){
    int n, i, j, arr[10];
    printf("Masukkan Angka: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= i; j++){
            arr[j-1] = j;
        }
        for (j = 0; j < i; j++){
            printf("%d", arr[j]);
        }
        printf("\n");
    }
    return 0;
}
