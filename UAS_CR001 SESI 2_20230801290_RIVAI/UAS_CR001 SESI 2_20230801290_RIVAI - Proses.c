#include "UAS_CR001 SESI 2_20230801290_RIVAI - Pustaka.h"

void gerakGaris(char *kata, int jumlah) {
    int garis = jumlah;
    while (garis--) {
        printf("%s", kata);
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

void systemPause() {
    #ifdef _WIN32
        system("pause");
    #else
        system("read -p 'Press Enter to continue...' key");
    #endif
}

int getValidInt() {
    char buffer[100];
    int validInput, value;
    do {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
                len--;
            }
            validInput = 0;
            for (size_t i = 0; i < len; i++) {
                if (!isspace(buffer[i])) {
                    validInput = 1;
                    break;
                }
            }
            if (!validInput) {
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

void kapitalAwal(char str[]) {
    int i;
    int len = strlen(str);
    int wordStart = 1;
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (wordStart) {
                str[i] = toupper(str[i]);
                wordStart = 0;
            } else {
                str[i] = tolower(str[i]);
            }
        } else {
            wordStart = 1;
        }
    }
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

void mainSumpah(){
	systemClose();
	printf("Dengan nama Allah, saya RIVAI bersumpah bahwa saya tidak melakukan kecurangan (mencontek ataupun memberikan contekan) selama UAS Algoritma dan Pemrograman ini berlangsung, jika pengawas menemukan saya melakukan kecurangan maka saya siap mendapatkan nilai 0 pada UAS, dan apabila kecurangan saya tidak diketahui oleh pengawas maka saya siap mendapatkan azab dari Allah baik di dunia maupun di akhirat kelak\n\n\n");
}

void mainTransfer() {
	systemClose();
	int nominal;
	struct AkunBank penerima;
	printf("Masukkan nomor rekening tujuan: ");
	penerima.norekening = getValidInt();
    printf("Masukkan nominal transfer: ");
    nominal = getValidInt();
    if (nominal > akun.saldo) {
        printf("Saldo tidak mencukupi. Transfer gagal.\n\n\n");
	} else {
        akun.saldo -= nominal;
        penerima.saldo += nominal;
        printf("Transfer berhasil. Sisa saldo: %d\n\n\n", akun.saldo);
    }
}

void mainNabung() {
	systemClose();
    int nominal;
    printf("Masukkan nominal uang yang ingin ditabung: ");
    nominal = getValidInt();
    akun.saldo += nominal;
    printf("Tabungan berhasil. Sisa saldo: %d\n\n\n", akun.saldo);
}

void mainTarikTunai() {
	systemClose();
    int nominal;
    printf("Masukkan nominal uang yang ingin ditarik: ");
    nominal = getValidInt();
    if (nominal < 50000 || akun.saldo - nominal < 0) {
        printf("Penarikan tunai tidak valid. Minimal penarikan: 50000 dan saldo mencukupi.\n\n\n");
    } else {
        akun.saldo -= nominal;
        printf("Penarikan tunai berhasil. Sisa saldo: %d\n\n\n", akun.saldo);
    }
}

void mainCekSaldo() {
	systemClose();
    printf("Saldo Anda saat ini: %d\n\n\n", akun.saldo);
}

void sistemMenu() {
	char _Menu[100];
	systemClose();
    gerakGaris("=", 100);
    printf("\n\t\t\t\tPROGRAM SIMULASI BANK\n");
    gerakGaris("=", 100);
    printf("\n1. Sumpah\n");
    printf("2. Transfer\n");
    printf("3. Nabung\n");
    printf("4. Tarik Tunai\n");
    printf("5. Cek Saldo\n");
    printf("6. Keluar Aplikasi\n");
    printf("\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(_Menu, sizeof(_Menu), stdin);
    _Menu[strcspn(_Menu, "\n")] = 0;

    if (strcmp(_Menu, "1") == 0 || strcasecmp(_Menu, "sumpah") == 0) {
    	mainSumpah();
    	sistemSubMenu();
    } else if (strcmp(_Menu, "2") == 0 || strcasecmp(_Menu, "transfer") == 0) {
    	mainTransfer();
        sistemSubMenu();
    } else if (strcmp(_Menu, "3") == 0 || strcasecmp(_Menu, "nabung") == 0) {
    	mainNabung();
        sistemSubMenu();
    } else if (strcmp(_Menu, "4") == 0 || strcasecmp(_Menu, "tarik tunai") == 0) {
    	mainTarikTunai();
        sistemSubMenu();
    } else if (strcmp(_Menu, "5") == 0 || strcasecmp(_Menu, "cek saldo") == 0) {
    	mainCekSaldo();
        sistemSubMenu();
	} else if (strcmp(_Menu, "6") == 0 || strcasecmp(_Menu, "keluar aplikasi") == 0) {
    	noticeExit();
    } else {
        noticeDefault();
        sistemMenu(); // Bu sebenarnya ini Rekursif, saya memakainya dibagian sistemMenu dan subMenu
    }
}

void sistemSubMenu() {
	char subMenu[100];
    gerakGaris("=", 100);
    printf("\n\t\t\t\t\t   Pilihan Menu\n");
    gerakGaris("=", 100);
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
        sistemSubMenu(); // Bu sebenarnya ini Rekursif, saya memakainya dibagian sistemMenu dan subMenu
    }
}
