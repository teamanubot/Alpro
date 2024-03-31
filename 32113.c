#include <stdio.h>
#include <string.h>
#include <conio.h>

int main() {
    char username[20] = "pengguna";
    char password[20] = "rahasia";
    char inputUsername[20];
    char inputPassword[20];
    int attempts = 0, login = 0, maxAttempts = 3, loginmax = 3;
    FILE *logFile;
	
    logFile = fopen("login.txt", "r");
    if (logFile != NULL) {
        fscanf(logFile, "[ERROR] Gagal Login : %d", &login);
        fclose(logFile);
    }
    
    if (login >= loginmax) {
        printf("Anda telah melebihi batas percobaan untuk login jadi dibanned. Program akan keluar.\n");
        return 0;
    }
    
    while (attempts < maxAttempts) {
        do {
            printf("Masukkan username: ");
            if (fgets(inputUsername, sizeof(inputUsername), stdin) != NULL) {
                inputUsername[strcspn(inputUsername, "\n")] = '\0';
            }
        } while (strlen(inputUsername) == 0);

        do {
            printf("Masukkan password: ");
            int i = 0;
            char ch;
        	while (1) {
            	ch = _getch();
            	if (ch == 13) {
                	inputPassword[i] = '\0';
                	break;
            	} else if (ch == 8) {
                	if (i > 0) {
                    	i--;
                    	printf("\b \b");
                	}
            	} else {
                	inputPassword[i] = ch;
                	i++;
                	printf("*");
            	}
        	}
        	printf("\n");
        } while (strlen(inputPassword) == 0);
		
        if (strcmp(inputUsername, username) == 0 && strcmp(inputPassword, password) == 0) {
            printf("\nLogin sukses! Selamat datang, %s\n", username);
            remove("login.txt");
            break;
        } else {
            attempts++;
            printf("\nLogin gagal. Sisa percobaan: %d\n", maxAttempts - attempts);
        }
    }

    if (attempts == maxAttempts) {
        login++;
        logFile = fopen("login.txt", "w");
        if (logFile != NULL) {
            fprintf(logFile, "[ERROR] Gagal Login : %d", login);
            fclose(logFile);
        }
        printf("Anda telah melebihi batas percobaan. Program akan keluar.\n");

        return 0;
    }
    printf("berhasil hore");
}
        //if (remove("log.txt") == 0) {
            //printf("File log.txt berhasil dihapus.\n");
        //} else {
            //printf("Gagal menghapus file log.txt.\n");
        //}
