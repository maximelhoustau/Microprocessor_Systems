//Exercice destiné à trouver les @ mémoires des différentes sections sur Linux
#include <stdio.h>
#include <stdlib.h>

int test(int a, int b);
int addition (int d, int e);

const int rodata = 10;
int data = 11;
int bss;

int addition(int d, int e) {
	printf("addresse de d: %p, addresse de e: %p \n", &d, &e);
	int f = d + e;
	return f;
}

int test(int a, int b) {
	printf("addrese de a: %p, addresse de b: %p \n", &a, &b);
	int c = addition(3,2);
	return c;
}

int main() {
	char * pointeur = malloc(20*sizeof(char));
	printf("valeur de a + b = %d \n", test(3,4));
	printf("adresse de rodata: %p, adresse de data: %p, adresse de bss: %p \n", &rodata, &data, &bss);
	printf("addresse du pointeur malloc: %p \n", pointeur);
	free(pointeur);
	return 0;
}
