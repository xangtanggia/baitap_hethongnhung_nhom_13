.syntax unified
.cpu cortex-m3
.thumb

.global Reset_Handler
.global Default_Handler
.global _estack

.extern main

.section .isr_vector, "a", %progbits
.word _estack
.word Reset_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word 0
.word 0
.word 0
.word 0
.word Default_Handler
.word Default_Handler
.word 0
.word Default_Handler
.word Default_Handler

.section .text.Reset_Handler
.type Reset_Handler, %function

Reset_Handler:
    bl main

1:
    b 1b

.section .text.Default_Handler
.type Default_Handler, %function

Default_Handler:
    b Default_Handler
