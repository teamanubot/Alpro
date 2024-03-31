#include "UAS_CR001 SESI 2_20230801290_RIVAI - Pustaka2.h"

void gerakGaris(const string& kata, int jumlah) {
    int garis = jumlah;
    while (garis--) {
        cout << kata;
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
                cout << "Masukkan Angka : ";
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
                cout << "Masukkan Angka Bukan Huruf/Simbol : ";
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
    cout << "Masukkan Dengan Benar" << endl;
    cout << "Silahkan Coba Lagi." << endl;
    getch();
    systemClose();
}

void noticeExit(){
    systemClose();
    cout << "Terima Kasih Telah Menggunakan >_<";
    exit;
}

void mainSumpah(){
    systemClose();
    cout << "Dengan nama Allah, saya RIVAI bersumpah bahwa saya tidak melakukan kecurangan (mencontek ataupun memberikan contekan) selama UAS Algoritma dan Pemrograman ini berlangsung, jika pengawas menemukan saya melakukan kecurangan maka saya siap mendapatkan nilai 0 pada UAS, dan apabila kecurangan saya tidak diketahui oleh pengawas maka saya siap mendapatkan azab dari Allah baik di dunia maupun di akhirat kelak\n\n\n";
}

void mainTransfer() {
    systemClose();
    int nominal;
    struct AkunBank penerima;
    cout << "Masukkan nomor rekening tujuan: ";
    penerima.norekening = getValidInt();
    cout << "Masukkan nominal transfer: ";
    nominal = getValidInt();
    if (nominal > akun.saldo) {
        cout << "Saldo tidak mencukupi. Transfer gagal.\n\n\n";
    } else {
        akun.saldo -= nominal;
        penerima.saldo += nominal;
        cout << "Transfer berhasil. Sisa saldo: " << akun.saldo << "\n\n\n";
    }
}

void mainNabung() {
    systemClose();
    int nominal;
    cout << "Masukkan nominal uang yang ingin ditabung: ";
    nominal = getValidInt();
    akun.saldo += nominal;
    cout << "Tabungan berhasil. Sisa saldo: " << akun.saldo << "\n\n\n";
}

void mainTarikTunai() {
    systemClose();
    int nominal;
    cout << "Masukkan nominal uang yang ingin ditarik: ";
    nominal = getValidInt();
    if (nominal < 50000 || akun.saldo - nominal < 0) {
        cout << "Penarikan tunai tidak valid. Minimal penarikan: 50000 dan saldo mencukupi.\n\n\n";
    } else {
        akun.saldo -= nominal;
        cout << "Penarikan tunai berhasil. Sisa saldo: " << akun.saldo << "\n\n\n";
    }
}

void mainCekSaldo() {
    systemClose();
    cout << "Saldo Anda saat ini: " << akun.saldo << "\n\n\n";
}

void sistemMenu() {
    string _Menu;
    systemClose();
    gerakGaris("=", 100);
    cout << "\n\t\t\t\tPROGRAM SIMULASI BANK\n";
    gerakGaris("=", 100);
    cout << "\n1. Sumpah\n";
    cout << "2. Transfer\n";
    cout << "3. Nabung\n";
    cout << "4. Tarik Tunai\n";
    cout << "5. Cek Saldo\n";
    cout << "6. Keluar Aplikasi\n";
    cout << "\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ";
    getline(cin, _Menu);

    if (_Menu == "1" || _Menu == "sumpah") {
        mainSumpah();
        sistemSubMenu();
    } else if (_Menu == "2" || _Menu == "transfer") {
        mainTransfer();
        sistemSubMenu();
    } else if (_Menu == "3" || _Menu == "nabung") {
        mainNabung();
        sistemSubMenu();
    } else if (_Menu == "4" || _Menu == "tarik tunai") {
        mainTarikTunai();
        sistemSubMenu();
    } else if (_Menu == "5" || _Menu == "cek saldo") {
        mainCekSaldo();
        sistemSubMenu();
    } else if (_Menu == "6" || _Menu == "keluar aplikasi") {
        noticeExit();
    } else {
        noticeDefault();
        sistemMenu();
    }
}

void sistemSubMenu() {
    string subMenu;
    gerakGaris("=", 100);
    cout << "\n\t\t\t\t\t   Pilihan Menu\n";
    gerakGaris("=", 100);
    cout << "\n1. Kembali Ke Awal\n";
    cout << "2. Keluar Aplikasi\n";
    cout << "\nMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ";
    getline(cin, subMenu);

    if (subMenu == "1" || subMenu == "kembali ke awal") {
        sistemMenu();
    } else if (subMenu == "2" || subMenu == "keluar aplikasi") {
        noticeExit();
    } else {
        noticeDefault();
        sistemSubMenu();
    }
}
