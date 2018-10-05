.cpu arm7tdmi
.syntax unified
.global _start
.global _stack

_start:
    ldr sp, =_stack
    bl main
