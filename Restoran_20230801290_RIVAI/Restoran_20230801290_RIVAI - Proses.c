#include "Restoran_20230801290_RIVAI - Pustaka.h"
#define MAX_MENU 100

void gerakGaris() {
    int garis = 100;
    while (garis--) {
        printf("=");
        Sleep(5);
    }
}

struct Menu {
    char name[50];
    float harga;
    int id;
};

struct Menu menuList[MAX_MENU];

int jumlahMenu = 0;

void noticeDefault() {
    printf("Masukkan Dengan Benar\n");
    printf("Silahkan Coba Lagi.\n");
    getch();
    system("CLS");
}

void noticeExit(){
	system("CLS");
    printf("Terima Kasih Telah Menggunakan >_<");
    exit;
}

int getValidInt() {
	char buffer[100];
    int hanyaEnter, validInput, value;
    do {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
                len--;
            }
            hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(buffer[i])) {
                    hanyaEnter = 0;
                    break;
                }
            }
            if (hanyaEnter) {
                printf("Masukkan Angka : ");
                continue;
            }
            validInput = 1;
            for (size_t i = 0; i < len; i++) {
                if (i == 0 && buffer[i] == '-') {
                    continue;
                }
                if (!isdigit(buffer[i])) {
                    validInput = 0;
                    break;
                }
            }
            if (validInput) {
                sscanf(buffer, "%d", &value);
            } else {
                printf("Masukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    } while (!validInput);
    return value;
}

void getValidString(char input[]) {
    int valid = 0;
    do {
        if (fgets(input, 100, stdin) != NULL) {
            size_t len = strlen(input);
            if (len > 0 && input[len - 1] == '\n') {
                input[len - 1] = '\0';
                len--;
            }
			int hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(input[i])) {
                    hanyaEnter = 0;
                    break;
                }
            }
            if (hanyaEnter) {
                printf("Masukkan hanya huruf : ");
                continue;
            }
            valid = 1;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(input[i]) && !isalpha(input[i])) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Masukkan hanya huruf dan spasi : ");
            }
        }
    } while (!valid);
}

void kapitalAwal(char str[]) {
    int i;
    int len = strlen(str);
    if (len > 0 && isalpha(str[0])) {
        str[0] = toupper(str[0]);
    }
    for (i = 1; i < len; i++) {
        if (isspace(str[i - 1]) && isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

bool isMenuExist(const char name[], int jumlahMenu) {
    for (int i = 0; i < jumlahMenu; i++) {
        if (strcasecmp(menuList[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void tampilkanMenu(struct Menu menuList[], int jumlahMenu) {
	if (jumlahMenu != 0) {
		printf("\nNo  \tNama Barang  \tHarga\n");
    	gerakGaris();
    	for (int i = 0; i < jumlahMenu; i++) {
        	printf("\n%d.  \t%s  \tRp. %d", menuList[i].id, menuList[i].name, (int)menuList[i].harga);
    	}
    	printf("\n");
    	gerakGaris();
    }
}

void tambahMenu() {
    system("CLS");
    if (jumlahMenu < MAX_MENU) {
        printf("Masukkan nama menu : ");
        char tempName[100];
        getValidString(tempName);
        kapitalAwal(tempName);
        if (isMenuExist(tempName, jumlahMenu)) {
            printf("Menu dengan nama tersebut sudah ada\n");
            system("Pause");
            return;
        } else {
            strcpy(menuList[jumlahMenu].name, tempName);
        }
        printf("Masukkan harga menu : ");
        menuList[jumlahMenu].harga = getValidInt();
        menuList[jumlahMenu].id = jumlahMenu + 1;
        jumlahMenu++;
        printf("Menu berhasil ditambahkan!\n");
        system("Pause");
    } else {
        printf("Maaf, sudah mencapai batas maksimal menu.\n");
        system("Pause");
    }
}

void bubbleSortMenu(struct Menu menuList[], int jumlahMenu) {
    int i, j;
    struct Menu temp;
    for (i = 0; i < jumlahMenu - 1; i++) {
        for (j = 0; j < jumlahMenu - i - 1; j++) {
            if (strcmp(menuList[j].name, menuList[j + 1].name) > 0) {
                temp = menuList[j];
                menuList[j] = menuList[j + 1];
                menuList[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < jumlahMenu; i++) {
        menuList[i].id = i + 1;
    }
}


void selectionSortMenu(struct Menu menuList[], int jumlahMenu) {
    int i, j, minIndex;
    struct Menu temp;
    for (i = 0; i < jumlahMenu - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < jumlahMenu; j++) {
            if (menuList[j].harga < menuList[minIndex].harga) {
                minIndex = j;
            }
        }
        temp = menuList[i];
        menuList[i] = menuList[minIndex];
        menuList[minIndex] = temp;
    }
    for (i = 0; i < jumlahMenu; i++) {
        menuList[i].id = i + 1;
    }
}

bool containsKeyword(const char str[], const char keyword[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (tolower(str[i]) == tolower(keyword[j])) {
            i++;
            j++;
            if (keyword[j] == '\0') {
                return true;
            }
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}

int binarySearch(struct Menu menuList[], int jumlahMenu, const char target[], int urut[]) {
    int count = 0;
    for (int i = 0; i < jumlahMenu; i++) {
        if (containsKeyword(menuList[i].name, target)) {
            urut[count++] = i;
        }
    }
    return count;
}

void tampilkanHasilPencarian() {
    system("CLS");
    char targetMenu[50];
    if (jumlahMenu != 0) {
        printf("Masukkan kata kunci menu yang dicari: ");
        getValidString(targetMenu);
        int urut[jumlahMenu];
        int count = binarySearch(menuList, jumlahMenu, targetMenu, urut);
        if (count > 0) {
            printf("\nMenu ditemukan:\n");
            printf("No  \tNama Barang  \tHarga\n");
            gerakGaris();
            printf("\n");
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (urut[j] > urut[j + 1]) {
                        int temp = urut[j];
                        urut[j] = urut[j + 1];
                        urut[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < count; i++) {
                int index = urut[i];
                printf("%d.  \t%s  \tRp. %.0f\n", i + 1, menuList[index].name, menuList[index].harga);
            }
        } else {
            printf("Menu tidak ditemukan.\n");
        }

        printf("\n%d menu ditemukan dengan kata kunci '%s'\n", count, targetMenu);
    } else {
        printf("Tidak ada menu\n");
    }
    printf("\n\n");
}

void sistemMenu() {
	char _Menu[100];
	system("CLS");
    gerakGaris();
    printf("\n\t\t\t\tAplikasi Beta Sudah Dekat V8\n");
    gerakGaris();
    tampilkanMenu(menuList, jumlahMenu);
    printf("\n1. Add New Menu\n");
    printf("2. Sort Menu by Name (Bubble Sort)\n");
    printf("3. Sort Menu by Price (Selection Sort)\n");
    printf("4. Search Menu (Binary Search)\n");
    printf("5. Keluar Aplikasi\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;

    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "add new menu") == 0) {
    	tambahMenu();
    	sistemMenu();
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "sort menu by Name (bubble sort)") == 0) {
        bubbleSortMenu(menuList, jumlahMenu);
        sistemMenu();
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "sort menu by price (selection sort)") == 0) {
        selectionSortMenu(menuList, jumlahMenu);
        sistemMenu();
    } else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "search menu (binary search)") == 0) {
    	tampilkanHasilPencarian();
    	sistemSubMenu();
	} else if (strcmp(_Menu, "5") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
        noticeDefault();
        sistemMenu();
    }
}

void sistemSubMenu() {
	char subMenu[100];
    gerakGaris();
    printf("\n\t\t\t\t\t   Pilihan Menu\n");
    gerakGaris();
    printf("\n1. Kembali Ke Awal\n");
    printf("2. Keluar Aplikasi\033[0m\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(subMenu, sizeof(subMenu), stdin);
    subMenu[strcspn(subMenu, "\n")] = 0;

    if (strcmp(subMenu, "1") == 0 || strcasecmp(subMenu, "kembali ke awal") == 0) {
        sistemMenu();
    } else if (strcmp(subMenu, "2") == 0 || strcasecmp(subMenu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
        noticeDefault();
        sistemSubMenu();
    }
}
