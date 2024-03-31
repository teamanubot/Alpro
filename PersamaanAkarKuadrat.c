#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
 
int main(void){
  printf("## Program Bahasa C Mencari Akar Persamaan Kuadrat ## \n");
  printf("===================================================== \n\n");
 
  int a, b, c, D, sq;
  float x1, x2;
 
  printf("Format persamaan: ax^2 + bx + c = 0 \n");
  printf("Input nilai a: ");
  scanf("%d",&a);
  printf("Input nilai b: ");
  scanf("%d",&b);
  printf("Input nilai c: ");
  scanf("%d",&c);
 
  printf("\n");
 
  D = (b*b)-(4*a*c);
  printf("Diskriminan = %d",D);
  sq = sqrt(D);
 
  if (D>0){
    printf(" (akar real dan berbeda) \n");
 
    x1 = (-b + sq) / (2*a);
    x2 = (-b - sq) / (2*a);
 
    printf("x1 = %.2f \n",x1);
    printf("x2 = %.2f \n",x2);
  }
  else if (D==0){
    printf(" (akar real dan sama) \n");
 
    x1 = x2 = (-b + sq) / (2*a);
 
    printf("x1 = %.2f \n",x1);
    printf("x2 = %.2f \n",x2);
  }
  else {
    printf(" (akar tidak real / imajiner) \n");
  }
 
  return 0;
}
