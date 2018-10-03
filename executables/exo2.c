//Exercice destiné à trouver les @ mémoires des différentes sections sur Linux
#include <stdio.h>

const int rodata = 10;
int data = 11;
int bss;

int main() {
  printf("adresse de rodata: %p, adresse de data: %p, adresse de bss: %p \n", &rodata, &data, &bss);
  return 0;
}
