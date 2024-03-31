#include <stdio.h>

int main (){
	int i;
	for (i = 1; i <= 5; i++){
		if (i == 1){
			printf("%d", i);
			printf("*");
		} else if (i != 5){
			printf("%d", i);
			printf("*");
		} else {
			printf("%d", i);
		}
	} 
	getch();
	return 0;
}
