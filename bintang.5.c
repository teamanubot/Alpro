/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include<stdio.h>

int main(){
	int i,j,n;
	printf("masukkan angka : ");
	scanf("%d",&n);
	for(j=1;j <= n; j++){
		for(i=n;i>=j;i--){
			printf("  ");
		}
		for(i=1;i<=j;i++){
			printf("* ");
		}
		for(i=1;i<=n;i++){
			printf("- ");
		}
		for(i=1;i<=j;i++){
			printf("* ");
		}
		printf("\n");
	}
}
