.cpu cortex-m4
.syntax unified
.global _start

/*On initialise le sp en haut de la pile (descendante) puis branchement à main */
_start:
    ldr sp, =_stack
    bl init_bss
    bl main

/*boucle infinie pour terminer l'exercice*/
end:
  b end
