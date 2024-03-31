#include <stdio.h>

int main (){
	int i, awal, akhir;
	printf("Masukkan Range Awal : ");
	scanf("%d", &awal);
	printf("Masukkan Range Akhir : ");
	scanf("%d", &akhir);
	for (i = awal; i <= akhir; i++){
		printf("%d \n", i);
	}
	getch();
	return 0;
}
