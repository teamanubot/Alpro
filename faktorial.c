// Library Input-Output //
#include <stdio.h>
 
int main(){
	// Menggunakan Variable TipeData Integer (Bilangan Bulat), Karena Faktorial Bilangan Bulat //
	int angka, hasil, i;
	
	// Menggunakan Printf Dan Scanf Untuk Memasukkan Bilangan Bulat Ke Variable TipeData Integer angka //
	printf("Input angka: ");
	scanf("%d", &angka);
	printf("%d! = ", angka);
	
	// Variable Hasil Dibawah Ini Supaya Untuk Mengkalikan Tiap Angka Menurunnya Dengan 1, Jika Dipaksakan Menulis Angka 1 Maka Akan Sulit Dimengerti Oleh Komputer //
	hasil = 1;
	
	// Pengulangan Menggunakan For, i Adalah Angka Yang Berarti Sesuai Inputan Data Yang Terscan. Lalu i Menggambarkan Sebuah Bilangan Bulat Lebih Dari 0, i-- Berfungsi Untuk Membaca Menurun Dari Inputan Variable angka //
	for(i = angka; i > 0; i--) {
		hasil = hasil * i;
		printf("%d", i);
		
		// if Untuk Menggambarkan Kondisi, Jika i Terbaca Tidak Sama Dengan 1 Maka Akan Menambahkan Sebuah Kata * // 
		if(i != 1) {
			printf (" * ");
		}
	}
	
	// Kodingan Dibawah Ini printf Untuk Menampilkan Hasil Faktorial Tersebut, Dan return Sebagai Pengakhirkan Kodingan (Selesai/End) //
	printf(" = %d \n", hasil);
	return 0;
}
