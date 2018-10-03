//Exercice destiné à trouver les @ mémoires des différentes sections sur Linux
#include <stdio.h>

const int text = 10;
int data = 11;
int bss;

int main() {
  printf("adresse de text: %ls, adresse de data: %ls, adresse de bss: %ls", &text, &data, &bss);
  return 0;
}
