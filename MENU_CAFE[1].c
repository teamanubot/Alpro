#include <stdio.h>
 
int main(){
	char ulang;
	int pilihan, i, n, deret;
	do {
		system("CLS");
		printf(" TP3 - Pengulangan \n");
		printf("============================== \n");
		printf("1. Pembuatan Program \n");
		printf("2. Penjumlahan Deret \n");
		printf("3. Menampilkan Banyak Bilangan  \n");
		printf("4. Rata - Rata \n");
		printf("5. Faktorial\n");
		printf("6. Keluar\n\n");
		printf("Pilihan anda: ");
		scanf("%d",&pilihan);
		switch(pilihan){
			case 1:
				printf("\n");
			
				// Tampilkan biodata mahasiswa
				printf("BIODATA\n");
				printf("================== \n");
				printf("Nama    : DINI FEBRYANA SARI \n");
				printf("NIM     : 20230801168 \n");
				printf("E-mail  : dinifeb8@gmail.com \n");
				break;
    	
			case 2:
				printf("\n");
				printf ("Penjumlahan Deret \n");
				printf("=================\n");
				printf ("Masukan Angka = ");
				scanf("%d",&n);
				deret = 0;
				for (i = 1; i <= n;i++){ //perulangan untuk deret angka sesuai masukan angka
					//tampilan hasil
					deret = deret + i;
					printf("%d",i);
					if (i != n) {
						printf(" + ");
					}
				}
				printf(" = %d\n", deret); //tampilan deret akhir dan hasil 
				break;
	    	case 3:
    	    	printf("Menampilkan Banyak Bilangan\n");
        		break;
    		case 4:
       			printf(" Rata - Rata \n");
        		break;
    		case 5:
        		printf(" Faktorial \n");
        		break;
    		case 6:
    			printf(" Keluar \n\n");
    			break;
    		default:
        		printf("Menu tidak tersedia \n");
		}
    	printf("\n");
    	printf("Ingin Melakukan Sekali Lagi? (Y/N) : ");
    	scanf(" %c", &ulang);
    	printf("\n");
    }while(ulang == 'Y' || ulang == 'y' );
	printf("Terimakasih... \n");
	return 0;
}
