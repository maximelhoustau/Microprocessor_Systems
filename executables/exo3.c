#include <stdint.h>
#include <stdio.h>

//globale initialisée: data
int32_t x = 34;
//globale non initialisée: bss
int32_t y;
//globale initialisée
const char mesg[] = "Hello World!\n";

int main() {
   //locale statique non initialisée: bss
   static uint8_t z;
   //locale non initialisée: stack
   uint16_t t;  
   
   y = 12;
   z = z + 1;
   t = y+z;

   printf(mesg);
   printf("x = %d, y = %d, z = %d, t = %d\n",
           x, y, z, t);
   return 0;
}
//Compilation avec Os (optimisation en taille)
//taille de data: 32/8 = 4
//taille de bss: 32+8=40, 40/8=5 
//Compilation avec O0 (pas d'optimisation): 
//
//
//Compilation avec O1:
//
//
//Compilation avec O2:
