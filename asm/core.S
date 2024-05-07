// FILE NOT REQUIRED
.syntax unified
.cpu cortex-m4
.thumb

.global vtable
.global rest_handler


.type vtable, %object
.section .vector_table,"a",%progbits
vtable:
    .word _estack
    .word reset_handler
.size vtable, .-vtable