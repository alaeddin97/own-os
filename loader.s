.set MAGIC, 0x1BADB002
.set FLAGS, 0x0
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
         .long MAGIC
         .long FLAGS
         .long CHECKSUM

.section .text
.extern kernelMain
.extern callConstructors
.global loader

loader:
    mov $kernel_stack, %esp

    call callConstructors

    push %eax
    push %ebx
    call kernelMain

_stop:
    cli
    hlt
    jmp _stop


.section .bss
.space 2*1024*1024

kernel_stack:

.section .note.GNU-stack,"",@progbits

