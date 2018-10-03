//On remarque en compilant pour différents types et tailles de données que l'adresse (également mentionnée comme étant la valeur de la variable dans le manuel de objdump) correspond à la taille en octets de la variable
//Que veut-on dire par corriger le slide?

#include <stdio.h>
#include <stdint.h>

int32_t x = 34;
int32_t y;
const char msg[]= "Hello World \n" ;

int main(){
  static uint8_t z;
  uint16_t t;

  y=12;
  z=z+1;
  t=y+z;

  printf(msg);
  printf("x=%d , y=%d, z=%d t=%d \n", x, y, z, t);

  return 0;
}
