.syntax unified
.global _start

_start:
    ldr sp, =_stack
    bl main
