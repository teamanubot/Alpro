#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

#ifndef PUSTAKA_H
#define Rivai_Munte main

struct AkunBank {
    int norekening;
    int saldo;
};

struct AkunBank akun = {02102002, 50000};

#endif

void sistemMenu();

void sistemSubMenu();
