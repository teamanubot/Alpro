/*
  Nama      : Rivai
  Nim       : 20230801290
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

#define cetak printf
#define sistem system
#define pergi_ke goto
#define jika if
#define kalau else
#define Tidur Sleep

struct sistemVariable {
    int input, angka, hasil, i, j, jumlahGenap, jumlahGanjil, jumlahKelipatan7, value, validInput, hanyaEnter;
    double sum, average;
    char _Menu[100], subMenu[100], data[100], buffer[100];
};

struct sistemVariable struktur;

void RapsodiWAV();

void SeventeenWAV();

void TokyoDriftWAV();

void sistemMenu();

void sistemSubMenu();

void noticeDefault() {
    cetak("\t\033[1;32mMasukkan Dengan Benar\n");
    cetak("\tSilahkan Coba Lagi.\033[0m\n");
    getch();
    sistem("CLS");
}

void gerakGaris() {
    int garis = 100;
    while (garis--) {
        cetak("=");
        Tidur(5);
    }
}

int getValidInt() {
    do {
        cetak("\033[1;32m");
        jika (fgets(struktur.buffer, sizeof(struktur.buffer), stdin) != NULL) {
            size_t len = strlen(struktur.buffer);
            jika (len > 0 && struktur.buffer[len - 1] == '\n') {
                struktur.buffer[len - 1] = '\0';
                len--;
            }
            struktur.hanyaEnter = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isspace(struktur.buffer[i])) {
                    struktur.hanyaEnter = 0;
                    break;
                }
            }
            jika (struktur.hanyaEnter) {
                cetak("\033[1;32m\tMasukkan Angka : ");
                continue;
            }
            struktur.validInput = 1;
            for (size_t i = 0; i < len; i++) {
                jika (!isdigit(struktur.buffer[i])) {
                    struktur.validInput = 0;
                    break;
                }
            }
            jika (struktur.validInput) {
                sscanf(struktur.buffer, "%d", &struktur.value);
                cetak("\033[0m");
            } kalau {
                cetak("\033[1;32m\tMasukkan Angka Bukan Huruf/Simbol : ");
            }
        }
    } while (!struktur.validInput);
    return struktur.value;
}

void waktuDanTanggal(){
    time_t rawtime;
    struct tm *info_waktu;

    time(&rawtime);
    info_waktu = localtime(&rawtime);

    char *hari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
    char *bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    int tanggal = info_waktu->tm_mday;
    int indeks_bulan = info_waktu->tm_mon;
    int tahun = info_waktu->tm_year + 1900;
    int jam = info_waktu->tm_hour;
    int menit = info_waktu->tm_min;
    int detik = info_waktu->tm_sec;

    char *nama_hari = hari[info_waktu->tm_wday];
    char *nama_bulan = bulan[indeks_bulan];

    cetak("\033[0m\033[1;32mTanggal dan Waktu : %s, %02d %s %04d %02d:%02d:%02d\033[0m\n", nama_hari, tanggal, nama_bulan, tahun, jam, menit, detik);
    return;
}

void lirikRapsodi(){
	sistem("CLS");
	cetak("\033[0m\033[1;34m\t\t\tJKT48 - Rapsodi\n\n\t");
	Tidur(19500);
	cetak("\n\tKulihat ada yang bersinar\n\tDi kedua bola matamu (oh kasihku)\n\tKau buat malam gelap ini\n\tJadi penuh cahaya\n\tTerang kilau pesona\n\t");
	Tidur(26000);
	cetak("\n\tKasih andai anganku bersuara dia kan bernyanyi\n\tRapsodi indah yang kan bermuara di fajar hati\n\tKelingking kita berjanji\n\tJari manis jadi saksi\n\tBahagia\n\tHingga sang bumi\n\tEnggan berputar lagi\n\t");
    Tidur(34000);
	cetak("\n\tKau buat aku sempurna\n\tSaat kau berkata iya (oh kasihku)\n\tKau izinkan ku berlaga\n\tMengarungi dunia (mengarungi dunia)\n\tDi sisimu selamanya\n\t");
	Tidur(25000);
	cetak("\n\tKasih andai anganku bersuara dia kan bernyanyi\n\tRapsodi indah yang kan bermuara di fajar hati\n\tKelingking kita berjanji\n\tJari manis jadi saksi\n\tBahagia\n\tHingga sang bumi\n\tTak berputar lagi\n\t");
	Tidur(32000);
	cetak("\n\tKita saling bersandar\n\tHingga bumi tak berputar\n\tCinta kita takkan pudar\n\tSelamanya\n\t");
	Tidur(21000);
	cetak("\n\tKasih dengar anganku bersuara di fajar hati\n\tKelingking kita berjanji\n\tJari manis jadi saksi\n\tBahagia\n\tTuk selamanya\n\t");
	Tidur(21000);
	cetak("\n\tKasih andai anganku bersuara dia kan bernyanyi\n\tRapsodi indah yang kan bermuara di fajar hati\n\tKelingking kita berjanji\n\tJari manis jadi saksi\n\tBahagia\n\tHingga sang bumi (tak berputar lagi)\n\t");
	Tidur(26000);
	cetak("\n\tKasih andai anganku bersuara dia kan bernyanyi (di sisiku)\n\tRapsodi indah yang kan bermuara di fajar hati\n\tKelingking kita berjanji\n\tJari manis jadi saksi\n\tBahagia\n\tHingga sang bumi\n\tEnggan berputar lagi\033[0m\n\t");
	Tidur(36000);
	cetak("\n\n");
}

void lirikSeventeen(){
	sistem("CLS");
	cetak("\033[0m\033[1;34m\t\tJKT48 - Seventeen\n\n\t");
	Tidur(30200);
	cetak("\n\tDi tempatku lahir dan dibesarkan\n\tDi kota yang dekat laut ini\n\tSetelah sekian lama aku pulang\n\tSudah ada shopping mall berdiri\n\t");
	Tidur(16500);
	cetak("\n\tWaktu itu selalu seperti tongkat sihir\n\tWalaupun telah mengubah pemandangan\n\tSuara ombak dan aroma gelombang\n\tMasih sama seperti dulu\n\tSeventeen\n\t");
	Tidur(18500);
	cetak("\n\tSekarang juga kamu yang teristimewa\n\tAda di pojok kanan buku tahunan kita\n\tSungguh memang kamu yang teristimewa\n\tBerapa kali kubuka untuk memastikannya\n\t");
	Tidur(28500);
	cetak("\n\tRumahmu yang dulu toko minuman\n\tSekarang menjadi minimarket\n\tSaatku intip ke balik jendela\n\tKamu berdiri di kasir counter\n\t");
	Tidur(16500);
	cetak("\n\tCita-citamu menjadi seorang hair stylist\n\tWaktu itu kamu pernah bercerita\n\tWalau tak seperti yang kamu bayangkan\n\tKamu terlihat bahagia\n\tAku jadi lega\n\t");
	Tidur(18500);
	cetak("\n\tKudengar kalau kamu sudah menikah\n\tAku terlambat bilang suka kepadamu\n\tKudengar kamu pun sekarang punya anak\n\tTak sanggup memanggilmu\n\tFarewell masa mudaku\n\t");
	Tidur(41000);
	cetak("\n\tSekarang juga kamu yang teristimewa\n\tAda di pojok kanan buku tahunan kita\n\tSungguh memang kamu yang teristimewa\n\tBerapa kali kubuka untuk memastikannya\n\tSekarang juga kamu yang teristimewa\n\tBerkilau dengan terang di dalam kenangan\n\tSungguh memang kamu yang teristimewa\n\tSeperti ini selamanya\n\tCintaku yang pertama\n\t");
	Tidur(50500);
	cetak("\n\n");
}

void liriktTokyoDrift(){
	sistem("CLS");
	cetak("\033[0m\033[1;34m\t\tTokyo Drift - Teriyaki Boyz\n\n\t");
	Tidur(11500);
	cetak("\n\tI wonder if you know\n\tHow they live in Tokyo\n\tIf you see me then you mean it\n\tThen you know you have to go\n\tFast and furious (Drift, Drift, Drift)\n\tFast and furious (Drift, Drift, Drift)\n\twonder if you know\n\tHow they live in Tokyo\n\tIf you see me then you mean it\n\tThen you know you have to go\n\tFast and furious (Drift, Drift, Drift)\n\tFast and furious (Drift, Drift, Drift)\n\t");
	Tidur(29500);
	cetak("\n\tIrasshai, omachidosama\n\tKenso-mamire kono machi no enso\n\tDamatta mama ichido tsuite oide\n\tSekaiju miryo suru hodo ni gokana\n\tJapan, ichiban\n\tJump around\n\tSaa uchira no deban\n\tTeriyaki Boyz in the place to be\n\tMisete yaru (hai) in VIP\n\t");
	Tidur(15000);
	cetak("\n\tMany, many diamonds danglin'\n\tBag full of money we stranglin'\n\tHate me, fry me, bake me, try me\n\tAll the above cuz you can't get in\n\tI don't want no puroburemu\n\tBecause me purofesshonaru\n\tMake you shake your ketsu (Thank you!)\n\tHaters take it pasonaru\n\t");
	Tidur(16000);
	cetak("\n\tLike a Kaneda tai Tetsuo\n\tNeo Tokyo metsubo\n\tNakunatchimau mae ni netsu o\n\tHassan shi kitchimaou ze, let's go\n\tNetsubo\n\tZu-hiru gi-roppon rabo kara esukoto (e?! sugoi)\n\tNijuroku-go janai, Nigo\n\tNyuryoku soru no zahyo pinpointo\n\t");
	Tidur(15000);
	cetak("\n\tI wonder if you know\n\tHow they live in Tokyo\n\tIf you see me then you mean it\n\tThen you know you have to go\n\tFast and furious (Drift, Drift, Drift)\n\tFast and furious (Drift, Drift, Drift)\n\t");
	Tidur(15000);
	cetak("\n\tHai! Watashi Teriyaki Boizu\n\tAt-to iu ma fukitobasu noizu\n\tMaishin shitemasunde getto\n\tFan no kazu mo fuetemasu\n\tBeshikku wa sapuraizu de\n\tMaji mainichi ga abunai ze\n\tNinja-fu kenja-fu dakedo geisha\n\tBAPE no wakusei kara no shisha\n\t");
	Tidur(15000);
	cetak("\n\tYou should see me in the parking lot\n\t7-11 is the spot\n\tBikes with wings and shiny things\n\tAnd lions, tigers, bears\n\tOh, my ride\n\tWe're furious and fast\n\tSupersonic like J.J. Fad\n\tAn' we ride till the wheels are flat\n\tCan't beat that with a baseball bat\n\t");
	Tidur(15000);
	cetak("\n\tLike a koankyuka Togusa\n\tMateba yoi zehi soku saiyo\n\tIntaseputa shite\n\tKokusai-teki hanzai wa banzai\n\tHora hands up\n\tFareru ga bomb otosu to\n\tOdori dasu kon'ya no four boyz\n\tFrom fa isuto kosuto\n\tDo sasayaku (Watashi no gosuto wa?)\n\t");
	Tidur(15500);
	cetak("\n\tI wonder if you know\n\tHow they live in Tokyo\n\tIf you see me then you mean it\n\tThen you know you have to go\n\tFast and furious (Drift, Drift, Drift)\n\tFast and furious (Drift, Drift, Drift)\n\t");
	Tidur(18500);
	cetak("\n\tYah, Japan mainichi doki-doki desu\n\tHito airando tobi-tobi de\n\tMoeru yoshi de bochi-bochi nee~\n\tTemaneki de izanau kotchi-kotchi e\n\tHito appu de odoriso\n\tMachiju subette norikomu\n\tMetcha kawarimono demo shaffuru\n\tGocha-gocha no fast and furious\n\t");
	Tidur(15500);
	cetak("\n\tIt's gotta be the shoes\n\tGotta be the furs\n\tThat's why ladies choose me\n\tAll up in the news\n\tCuz we so cute\n\tThat's why we so hug-e\n\tHarajuku girls know how I firu\n\tThey respect I keeps it riaru\n\tNot a Chinaman cuz I ain't from China, man\n\tI am Japanman\n\t");
	Tidur(15000);
	cetak("\n\tWatashi wa Tokyo suki\n\tWatashi no kuruma suteki\n\t(You see me go coming out of the black Benz SLR?)\n\tAnata mo Tokyo suki (I wonder where he get that kind of money)\n\t(Don`t worry about it) Anata no kuruma suteki (Let's go)\n\t");
	Tidur(15000);
	cetak("\n\tI wonder if you know\n\tHow they live in Tokyo\n\tIf you see me then you mean it\n\tThen you know you have to go\n\tFast and furious (Drift, Drift, Drift)\n\tFast and furious (Drift, Drift, Drift)\n\twonder if you know\n\tHow they live in Tokyo\n\tIf you see me then you mean it\n\tThen you know you have to go\n\tFast and furious (Drift, Drift, Drift)\n\tFast and furious (Drift, Drift, Drift)\033[0m\n\t");
	Tidur(43000);
	cetak("\n\n");
}

void RapsodiWAV(){
	const char* wavFilePath = "rapsodi.wav";
	jika (PlaySoundA(wavFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
		lirikRapsodi();
        PlaySoundA(NULL, 0, SND_PURGE);
Menu:
        cetak("\t\033[1;33m");
		gerakGaris();
    	cetak("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
    	gerakGaris();
    	cetak("\n\t1. Ulangi Musik\n");
    	cetak("\t2. JKT48 - Seventeen\n");
    	cetak("\t3. Tokyo Drift - Teriyaki Boyz\n");
    	cetak("\t4. Kembali Ke Awal\033[0m\n\n");
    	cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    	fgets(struktur.subMenu, sizeof(struktur.subMenu), stdin);
    	struktur.subMenu[strcspn(struktur.subMenu, "\n")] = 0;

    	jika (strcmp(struktur.subMenu, "1") == 0 || strcasecmp(struktur.subMenu, "Ulangi Musik") == 0) {
        	RapsodiWAV();
        } kalau jika (strcmp(struktur.subMenu, "2") == 0 || strcasecmp(struktur.subMenu, "jkt48 - seventeen") == 0) {
        	SeventeenWAV();
    	} kalau jika (strcmp(struktur.subMenu, "3") == 0 || strcasecmp(struktur.subMenu, "tokyo drift - teriyaki boyz") == 0) {
        	TokyoDriftWAV();
        } kalau jika (strcmp(struktur.subMenu, "4") == 0 || strcasecmp(struktur.subMenu, "kembali ke awal") == 0) {
        	sistemMenu();
   		} kalau {
        	noticeDefault();
        	pergi_ke Menu;
    	}
    } kalau {
        cetak("\t\033[1;32mGagal memutar audio.\033[0m\n\n");
    }
}

void SeventeenWAV(){
	const char* wavFilePath = "seventeen.wav";
	jika (PlaySoundA(wavFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
		lirikSeventeen();
        PlaySoundA(NULL, 0, SND_PURGE);
Menu:
        cetak("\t\033[1;33m");
		gerakGaris();
    	cetak("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
    	gerakGaris();
    	cetak("\n\t1. Ulangi Musik\n");
    	cetak("\t2. JKT48 - Rapsodi\n");
    	cetak("\t3. Tokyo Drift - Teriyaki Boyz\n");
    	cetak("\t4. Kembali Ke Awal\033[0m\n\n");
    	cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    	fgets(struktur.subMenu, sizeof(struktur.subMenu), stdin);
    	struktur.subMenu[strcspn(struktur.subMenu, "\n")] = 0;

    	jika (strcmp(struktur.subMenu, "1") == 0 || strcasecmp(struktur.subMenu, "Ulangi Musik") == 0) {
        	SeventeenWAV();
        } kalau jika (strcmp(struktur.subMenu, "2") == 0 || strcasecmp(struktur.subMenu, "jkt48 - rapsodi") == 0) {
        	RapsodiWAV();
    	} kalau jika (strcmp(struktur.subMenu, "3") == 0 || strcasecmp(struktur.subMenu, "tokyo drift - teriyaki boyz") == 0) {
        	TokyoDriftWAV();
        } kalau jika (strcmp(struktur.subMenu, "4") == 0 || strcasecmp(struktur.subMenu, "kembali ke awal") == 0) {
        	sistemMenu();
   		} kalau {
        	noticeDefault();
        	pergi_ke Menu;
    	}
    } kalau {
        cetak("\t\033[1;32mGagal memutar audio.\033[0m\n\n");
    }
}

void TokyoDriftWAV(){
	const char* wavFilePath = "tokyo_drift.wav";
	jika (PlaySoundA(wavFilePath, NULL, SND_FILENAME | SND_ASYNC)) {
		liriktTokyoDrift();
        PlaySoundA(NULL, 0, SND_PURGE);
Menu:
		cetak("\t\033[1;33m");
		gerakGaris();
    	cetak("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
    	gerakGaris();
    	cetak("\n\t1. Ulangi Musik\n");
    	cetak("\t2. JKT48 - Rapsodi\n");
    	cetak("\t3. JKT48 - Seventeen\n");
    	cetak("\t4. Kembali Ke Awal\033[0m\n\n");
    	cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    	fgets(struktur.subMenu, sizeof(struktur.subMenu), stdin);
    	struktur.subMenu[strcspn(struktur.subMenu, "\n")] = 0;

    	jika (strcmp(struktur.subMenu, "1") == 0 || strcasecmp(struktur.subMenu, "Ulangi Musik") == 0) {
        	TokyoDriftWAV();
    	} kalau jika (strcmp(struktur.subMenu, "2") == 0 || strcasecmp(struktur.subMenu, "jkt48 - rapsodi") == 0) {
        	RapsodiWAV();
        } kalau jika (strcmp(struktur.subMenu, "3") == 0 || strcasecmp(struktur.subMenu, "jkt48 - seventeen") == 0) {
        	SeventeenWAV();
        } kalau jika (strcmp(struktur.subMenu, "4") == 0 || strcasecmp(struktur.subMenu, "kembali ke awal") == 0) {
        	sistemMenu();
   		} kalau {
        	noticeDefault();
        	pergi_ke Menu;
    	}
    } kalau {
        cetak("\t\033[1;32mGagal memutar audio.\033[0m\n\n");
    }
}

void sistemMusik() {
Menu:
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tAplikasi Membuat Program (Musik)\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;37m\n\t1. JKT48 - Rapsodi\n");
    cetak("\t2. JKT48 - Seventeen\n");
    cetak("\t3. Tokyo Drift - Teriyaki Boyz\n");
    cetak("\t4. Kembali Ke Awal\033[0m\n\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur.data, sizeof(struktur.data), stdin);
    struktur.data[strcspn(struktur.data, "\n")] = 0;

    jika (strcmp(struktur.data, "1") == 0 || strcasecmp(struktur.data, "jkt48 - rapsodi") == 0) {
		RapsodiWAV();
	} kalau jika (strcmp(struktur.data, "2") == 0 || strcasecmp(struktur.data, "jkt48 - seventeen") == 0) {
		SeventeenWAV();
    } kalau jika (strcmp(struktur.data, "3") == 0 || strcasecmp(struktur.data, "tokyo drift - teriyaki boyz") == 0) {
		TokyoDriftWAV();
    } kalau jika (strcmp(struktur.data, "4") == 0 || strcasecmp(struktur.data, "kembali ke awal") == 0) {
    	sistemMenu();
    } kalau {
        noticeDefault();
        pergi_ke Menu;
    }
}

void sistemPenjumlahanDeret() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Penjumlahan Deret\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Angka : ");
    struktur.angka = getValidInt();
    cetak("\n\t\033[1;34m");
    for(struktur.i = 1; struktur.i <= struktur.angka ; struktur.i++) {
		struktur.hasil = struktur.hasil + struktur.i;
		cetak("%d", struktur.i);
		jika (struktur.i != struktur.angka) {
			cetak (" + ");
		}
	}
    cetak(" = %d\n\n\n\033[0m", struktur.hasil);
}

void sistemBanyakBilangan() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tAplikasi Menampilkan Banyak Bilangan\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Angka Awal : ");
    struktur.angka = getValidInt();
    cetak("\033[1;32m\n\tMasukkan Angka akhir : ");
    struktur.input = getValidInt();
    
    cetak("\n\n\t\033[1;34mBilangan Genap\n\t");
    for (struktur.i = struktur.angka; struktur.i <= struktur.input; struktur.i++) {
        jika (struktur.i % 2 == 0) {
            cetak("%d ", struktur.i);
            struktur.jumlahGenap++;
        }
    }

    cetak("\n\n\tBilangan Ganjil\n\t");
    for (struktur.i = struktur.angka; struktur.i <= struktur.input; struktur.i++) {
        jika (struktur.i % 2 != 0) {
            cetak("%d ", struktur.i);
            struktur.jumlahGanjil++;
        }
    }

    cetak("\n\n\tKelipatan 7\n\t");
    for (struktur.i = struktur.angka; struktur.i <= struktur.input; struktur.i++) {
        jika (struktur.i % 7 == 0) {
            cetak("%d ", struktur.i);
            struktur.jumlahKelipatan7++;
        }
    }
    cetak("\n\n\tJumlah Genap : %d\n\t", struktur.jumlahGenap);
    cetak("Jumlah Ganjil : %d\n\t", struktur.jumlahGanjil);
    cetak("Jumlah Kelipatan 7 : %d\033[0m\n\n\n", struktur.jumlahKelipatan7);
}

void sistemRataRata() {
    sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Rata - Rata\n\t");
    gerakGaris();
    cetak("\033[0m\033[1;32m\n\tMasukkan Banyak Bilangan : ");
    struktur.input = getValidInt();
    cetak("\n");

    jika (struktur.input <= 0) {
        cetak("Masukkan minimal 1 bilangan.\n");
    }
    for (struktur.i = 1; struktur.i <= struktur.input; struktur.i++) {
        cetak("\t\033[1;32mBilangan ke-%d : ", struktur.i);
        struktur.angka = getValidInt();
        struktur.sum += struktur.angka;
    }

    struktur.average = struktur.sum / struktur.input;
    cetak("\n\n\t\033[0m\033[1;34mRata - Rata = %.2f\033[0m\n\n\n", struktur.average);
}

void sistemFaktorial() {
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Faktorial\n\t");
    gerakGaris();
    cetak("\033[1;32m\n\tMasukkan Angka : ");
    struktur.angka = getValidInt();
	cetak("\033[1;34m\t%d! = ", struktur.angka);
	struktur.hasil = 1;
	for(struktur.i = struktur.angka; struktur.i > 0; struktur.i--) {
		struktur.hasil = struktur.hasil * struktur.i;
		cetak("%d", struktur.i);
		jika (struktur.i != 1) {
			cetak (" * ");
		}
	}
	cetak(" = %d\033[0m\n\n\n", struktur.hasil);
}

void sistemDeretMundur() {
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\tAplikasi Deret Mundur\n\t");
    gerakGaris();
    cetak("\033[1;32m\n\tMasukkan Angka : ");
    struktur.input = getValidInt();
	cetak("\033[1;34m\n\t");
	struktur.angka = struktur.input * struktur.input;
    for (struktur.i = 1; struktur.i <= struktur.angka; struktur.i += 2) {
		for (struktur.j = 1; struktur.j <= struktur.i; struktur.j++) {
            cetak("%d ", struktur.angka);
            struktur.angka--;
        }
        cetak("\n\t");
    }
    cetak("\033[0m\n\n");
}

void sistemPembuka() {
    sistem("CLS");
    cetak("\t\t\t\t\033[1;33mTugas Praktikum ALPRO 3 [Aplikasi Beta Sudah Dekat V2]\n\t");
    gerakGaris();
    cetak("\n\tNama\t : Rivai\n");
    cetak("\tNIM\t : 20230801290\n\t");
    gerakGaris();
    cetak("\n\n");
    cetak("\tWelcome, ");
    sistem("PAUSE");
}

void sistemMenu(){
	sistem("CLS");
    cetak("\t\033[0m\033[1;31m");
    gerakGaris();
    cetak("\n\t\t\t\t\tAplikasi Beta Sudah Dekat V2\n\t");
    gerakGaris();
    cetak("\n\t1. Membuat Program\n");
    cetak("\t2. Penjumlahan Deret\033[0m\n");
    cetak("\033[1;37m\t3. Menampilkan Banyak Bilangan\n");
    cetak("\t4. Rata - Rata\n");
    cetak("\t5. Faktorial\n");
    cetak("\t6. Deret Mundur\n");
    cetak("\t7. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur._Menu, sizeof(struktur._Menu), stdin);
    struktur._Menu[strcspn(struktur._Menu, "\n")] = 0;

    jika (strcmp(struktur._Menu, "1") == 0 || strcasecmp(struktur._Menu, "membuat program") == 0) {
        sistemMusik();
    } kalau jika (strcmp(struktur._Menu, "2") == 0 || strcasecmp(struktur._Menu, "penjumlahan deret") == 0) {
        sistemPenjumlahanDeret();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "3") == 0 || strcasecmp(struktur._Menu, "menampilkan banyak bilangan") == 0) {
        sistemBanyakBilangan();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "4") == 0 || strcasecmp(struktur._Menu, "rata - rata") == 0) {
        sistemRataRata();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "5") == 0 || strcasecmp(struktur._Menu, "faktorial") == 0) {
        sistemFaktorial();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "6") == 0 || strcasecmp(struktur._Menu, "deret mundur") == 0) {
        sistemDeretMundur();
        sistemSubMenu();
    } kalau jika (strcmp(struktur._Menu, "7") == 0 || strcasecmp(struktur._Menu, "keluar aplikasi") == 0) {
    	sistem("CLS");
        waktuDanTanggal();
        cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
        return;
    } kalau {
        noticeDefault();
        sistemMenu();
    }
}

void sistemSubMenu(){
	cetak("\t\033[1;36m");
    gerakGaris();
    cetak("\n\t\t\t\t\t\t   Pilihan Menu\n\t");
    gerakGaris();
    cetak("\n\t1. Kembali Ke Awal\n");
    cetak("\t2. Keluar Aplikasi\033[0m\n");
    cetak("\n");
    cetak("\t\033[1;32mMasukkan Pilihan Menu Sesuai Nomor Menu Atau Tulis Nama Menunya : ");
    fgets(struktur.subMenu, sizeof(struktur.subMenu), stdin);
    struktur.subMenu[strcspn(struktur.subMenu, "\n")] = 0;

    jika (strcmp(struktur.subMenu, "1") == 0 || strcasecmp(struktur.subMenu, "kembali ke awal") == 0) {
        sistemMenu();
    } kalau jika (strcmp(struktur.subMenu, "2") == 0 || strcasecmp(struktur.subMenu, "keluar aplikasi") == 0) {
    	sistem("CLS");
        waktuDanTanggal();
        cetak("\033[1;32mTerima Kasih Telah Menggunakan Aplikasi Beta Sudah Dekat V2 >_<");
        return;
    } kalau {
        noticeDefault();
        sistemSubMenu();
    }
}

void sistemInti() {
	sistemPembuka();
	sistemMenu();
}
