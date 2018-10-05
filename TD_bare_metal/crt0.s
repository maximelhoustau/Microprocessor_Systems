.syntax unified
.global _start
.global _zero
/*On initialise le sp en haut de la pile (descendante) puis branchement à main */
_start:
    ldr sp, =_stack
    bl main

_zero:
  word 0
