#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

#ifndef PUSTAKA_H
#define Rivai_Munte main
using namespace std;

struct AkunBank {
    int norekening;
    int saldo;
};

struct AkunBank akun = {02102002, 50000};

#endif

void sistemMenu();

void sistemSubMenu();
