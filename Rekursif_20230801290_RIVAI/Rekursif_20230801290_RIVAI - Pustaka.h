#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#ifndef PUSTAKA_H
#define MAX 10000
#define Rivai_Munte main

unsigned long long factorial(int n);
unsigned long long permutation(int n, int r);
unsigned long long combination(int n, int r);
unsigned long long memo[MAX];

unsigned long long fibonacci(long long int n) {
    if (n == 0 || n == 1) {
        return n;
    } else if (memo[n] != 0) {
        return memo[n];
    } else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
}

#endif

void factorization(int num);

void sistemMenu();

void sistemSubMenu();
