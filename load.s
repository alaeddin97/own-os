.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)


.section .txt
.extern kernelMain
.global laoder

loader:
    mov $kernel_stack, %esp
    push %eax
    push %ebx
    call kernelMain

_stop:
    cli
    hlt
    jmp_stop


.section .bss
.space 2*1024*1024; # 2 MiB

kernel_stack:
