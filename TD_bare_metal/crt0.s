.cpu cortex-m4
.syntax unified
.global _start

/*On initialise le sp en haut de la pile (descendante) puis branchement à main */
	.thumb_func
_start:
    bl init_bss
    bl recopie 
    bl main

/*boucle infinie pour terminer l'exercice*/
end:
  b end
