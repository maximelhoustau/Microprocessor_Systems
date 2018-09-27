#include <stdio.h>
#include <stdint.h>

uint32_t a=5; // global variable
__attribute__((naked)) void f() {
    for (uint8_t i=0; i<=a; i++)
g(); }

/*
// Global variables
    uint32_t *a;
    uint32_t *b;
    uint32_t *c;
__attribute__((naked)) void f() { *a += *c;
*b += *c; }
*/
