#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#ifndef PUSTAKA_H
#define PUSTAKA_H

#define MAX_LOKET 5
#define MAX_NAMA 100
#define MAX_ANTRIAN 100

struct Antrian {
    int nomorAntrian;
    char nama[MAX_NAMA];
};

struct Loket {
    char nama[MAX_NAMA];
    struct Antrian antrian[MAX_ANTRIAN];
    int jumlahAntrian;
};

struct Queue {
    struct Antrian antrian[MAX_ANTRIAN];
    int front, rear;
    int jumlahAntrian;
    int nomorAntrianTerakhir;
};

struct BarberShop {
    struct Antrian antrian[MAX_ANTRIAN];
    int jumlahAntrian;
    int pendapatan[3];
    int pendapatanMitra;
    int nomorAntrianTerakhir;
};

#endif

void mainLoket1();

void mainLoket2();

void mainDinamis();
