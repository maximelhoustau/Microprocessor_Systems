//Exercice destiné à trouver les @ mémoires des différentes sections sur Linux
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int8_t test(int8_t a, int8_t b);
int8_t addition (int8_t d, int8_t e);

//Definition de variables dans chacune des 3 sections dont la variable est le nom
const int8_t rodata = 10;
int8_t data = 11;
int8_t bss;

//Definition de fonctions imbriquées pour determiner le sens de la pile
int8_t addition(int8_t d, int8_t e) {
	printf("addresse de d: %p, addresse de e: %p \n", &d, &e);
	int8_t f = d + e;
	return f;
}

int8_t test(int8_t a, int8_t b) {
	printf("addrese de a: %p, addresse de b: %p \n", &a, &b);
	int8_t c = addition(3,2);
	return c;
}

int main() {
	//malloc pour accéder au tas
	char * pointeur = malloc(20*sizeof(char));

	printf("valeur de a + b = %d \n", test(3,4));
	printf("adresse de rodata: %p, adresse de data: %p, adresse de bss: %p \n", &rodata, &data, &bss);
	printf("addresse du pointeur malloc: %p \n", pointeur);
	
	free(pointeur);
	return 0;
}
//On obtient directement l'ordre des différentes sections  en récupérant et classant les adresses de rodata, data et bss, l'adresse de pointeur (malloc) pour le tas, les arguments des fonctions pour la pile (possibilité de les avoir en debuggant avec gdb.
//Concernant le sens de la pile, ii suffit de regarder comment les adresses sont gérées dans les deux fonctions imbriquées addition et test comme vu dans le cours
