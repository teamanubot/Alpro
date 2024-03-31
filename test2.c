void menuSatu();
void menuDua();
void menuTiga();

int main() {	
	int menu;
	
	do {
		printf("Aplikasi Simulasi Menu\n");
		printf("1. Menu Pertama\n");
		printf("2. Menu Kedua\n");
		printf("3. Menu Ketiga\n");
		printf("4. Keluar\n");
		printf("========================\n");
		printf("Pilih Menu: "); scanf("%d", &menu);
		printf("\n");
		
		switch(menu) {
			case 1:
				menuSatu();
				break;
			case 2:
				menuDua();
				break;
			case 3:
				menuTiga();
				break;
			case 4:
				break;
		}
	} while (menu != 4);
		
	return 0;
}

void menuSatu() {
	printf("Ini Menu Satu\n\n");
}

void menuDua() {
	printf("Ini Menu Dua\n\n");
}

void menuTiga() {
	printf("Ini Menu Tiga\n\n");
}
