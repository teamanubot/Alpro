#include "SPK_20230801290_RIVAI - Pustaka.h"

void gerakGaris2(int jumlah, char *jenis) {
    int garis = jumlah;
    while (garis--) {
        printf("%s", jenis);
        Sleep(5);
    }
}

void gerakGaris() {
    int garis = 100;
    while (garis--) {
        printf("=");
        Sleep(5);
    }
}

void systemClose() {
	#ifdef _WIN32
    	system("CLS");
	#else
    	system("clear");
	#endif
}

void noticeDefault() {
    printf("Masukkan Dengan Benar\n");
    printf("Silahkan Coba Lagi.\n");
    getch();
    systemClose();
}

void noticeExit(){
	systemClose();
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

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void gnomeSort(int arr[], int n, int sortedIndices[]) {
    int index = 0;
    while (index < n / 2) {
        if (index == 0 || arr[sortedIndices[index] * 2 + 1] <= arr[sortedIndices[index - 1] * 2 + 1]) {
            index++;
        } else {
            tukar(&sortedIndices[index], &sortedIndices[index - 1]);
            index--;
        }
    }
}

void bubbleSort(int arr[], int n, int sortedIndices[]) {
    for (int i = 0; i < n / 2 - 1; i++) {
        for (int j = 0; j < n / 2 - i - 1; j++) {
            if (arr[sortedIndices[j] * 2 + 1] < arr[sortedIndices[j + 1] * 2 + 1]) {
                tukar(&sortedIndices[j], &sortedIndices[j + 1]);
            }
        }
    }
}

void bucketSort(int arr[], int n, int sortedIndices[]) {
    const int max_value = 1000; 
    const int bucket_size = 10;
    int buckets[bucket_size][n / 2];
    int bucket_count[bucket_size];
    for (int i = 0; i < bucket_size; i++) {
        bucket_count[i] = 0;
    }
    for (int i = 0; i < n / 2; i++) {
        int bucket_index = arr[sortedIndices[i] * 2 + 1] / (max_value / bucket_size + 1);
        buckets[bucket_index][bucket_count[bucket_index]++] = sortedIndices[i];
    }
    for (int i = 0; i < bucket_size; i++) {
        for (int j = 1; j < bucket_count[i]; j++) {
            int temp = j;
            while (temp > 0 && arr[buckets[i][temp] * 2 + 1] > arr[buckets[i][temp - 1] * 2 + 1]) {
                tukar(&buckets[i][temp], &buckets[i][temp - 1]);
                temp--;
            }
        }
    }
    int index = 0;
    for (int i = 0; i < bucket_size; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            sortedIndices[index++] = buckets[i][j];
        }
    }
}

void tampilkanKelasGnomeSort(int jumlahKelas, int jumlahData, int data[]) {
    int sortedIndices[jumlahData / 2];
	for (int i = 0; i < jumlahData / 2; i++) {
        sortedIndices[i] = i;
    }
    gnomeSort(data, jumlahData, sortedIndices);
    for (int i = 0; i < jumlahKelas; i++) {
        printf("\nkelas X-%d :", i + 1);
        for (int j = i; j < jumlahData / 2; j += jumlahKelas) {
            printf("\n%d | %d", data[sortedIndices[j] * 2], data[sortedIndices[j] * 2 + 1]);
        }
        printf("\n------------------------\n");
    }
    printf("\n\n");
}

void tampilkanKelasBubbleSort(int jumlahKelas, int jumlahData, int data[]) {
    int sortedIndices[jumlahData / 2];
	for (int i = 0; i < jumlahData / 2; i++) {
        sortedIndices[i] = i;
    }
    bubbleSort(data, jumlahData, sortedIndices);
    for (int i = 0; i < jumlahKelas; i++) {
        printf("\nkelas X-%d :", i + 1);
        for (int j = i; j < jumlahData / 2; j += jumlahKelas) {
            printf("\n%d | %d", data[sortedIndices[j] * 2], data[sortedIndices[j] * 2 + 1]);
        }
        printf("\n------------------------\n");
    }
    printf("\n\n");
}

void tampilkanKelasBucketSort(int jumlahKelas, int jumlahData, int data[]) {
    int sortedIndices[jumlahData / 2];
	for (int i = 0; i < jumlahData / 2; i++) {
        sortedIndices[i] = i;
    }
    bucketSort(data, jumlahData, sortedIndices);
    for (int i = 0; i < jumlahKelas; i++) {
        printf("\nkelas X-%d :", i + 1);
        for (int j = i; j < jumlahData / 2; j += jumlahKelas) {
            printf("\n%d | %d", data[sortedIndices[j] * 2], data[sortedIndices[j] * 2 + 1]);
        }
        printf("\n------------------------\n");
    }
    printf("\n\n");
}

void mainGnomeSort(){
	systemClose();
	int gariss = 10;
	int jumlahKelas, jumlahData;
	gerakGaris2(30, "-");
    printf("\n\t\t\t\t\tGnome Sorting\n");
    gerakGaris();
    printf("\nMasukkan Banyak Kelas : ");
    jumlahKelas = getValidInt();
    printf("Masukkan Banyak Data : ");
    jumlahData = getValidInt();
    jumlahData *= 2;
    int data[jumlahData];
    printf("\nMasukkan %d data\n", jumlahData);
    for (int i = 0; i < jumlahData; i++) {
        printf("Data ke %d : ", i + 1);
        data[i] = getValidInt();
    }
    tampilkanKelasGnomeSort(jumlahKelas, jumlahData, data);
}

void mainBubbleSort(){
	systemClose();
	int jumlahKelas, jumlahData;
	gerakGaris();
    printf("\n\t\t\t\t\tBubble Sorting\n");
    gerakGaris();
    printf("\nMasukkan Banyak Kelas : ");
    jumlahKelas = getValidInt();
    printf("Masukkan Banyak Data : ");
    jumlahData = getValidInt();
    jumlahData *= 2;
    int data[jumlahData];
    printf("\nMasukkan %d data\n", jumlahData);
    for (int i = 0; i < jumlahData; i++) {
        printf("Data ke %d : ", i + 1);
        data[i] = getValidInt();
    }
    tampilkanKelasBubbleSort(jumlahKelas, jumlahData, data);
}

void mainBucketSort(){
	systemClose();
	int jumlahKelas, jumlahData;
	gerakGaris();
    printf("\n\t\t\t\t\tBucket Sorting\n");
    gerakGaris();
    printf("\nMasukkan Banyak Kelas : ");
    jumlahKelas = getValidInt();
    printf("Masukkan Banyak Data : ");
    jumlahData = getValidInt();
    jumlahData *= 2;
    int data[jumlahData];
    printf("\nMasukkan %d data\n", jumlahData);
    for (int i = 0; i < jumlahData; i++) {
        printf("Data ke %d : ", i + 1);
        data[i] = getValidInt();
    }
    tampilkanKelasBucketSort(jumlahKelas, jumlahData, data);
}

void sistemMenu(){
	systemClose();
	char _Menu[100];
    gerakGaris();
    printf("\n\t\t\t\t\tSPK Pembagian Kelas\n");
    gerakGaris();
    printf("\n1. Metode GnomeSort\n");
    printf("2. Metode BubbleSort\n");
    printf("3. Metode BucketSort\n");
    printf("4. Keluar Aplikasi\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;

    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "metode gnomesort") == 0) {
    	mainGnomeSort();
    	sistemSubMenu();
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "metode bubblesort") == 0) {
        mainBubbleSort();
        sistemSubMenu();
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "metode bucketsort") == 0) {
		mainBucketSort();
        sistemSubMenu();
    } else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
        noticeDefault();
        sistemMenu();
    }
}

void sistemSubMenu(){
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
