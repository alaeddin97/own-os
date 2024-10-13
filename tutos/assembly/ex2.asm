global _start

section .data
    msg db "Hello, world!", 0x0a
    len equ $ - msg

section .text

_start:
    mov eax, 4; tells the os that we'll gonna write somthing
    mov ebx, 1; tells the os that we'll gonna write to the terminal
    mov ecx, msg;tells the os that msg is the string to be written
    mov edx, len; tells the os that len is the length of the message to be written
    int 0x80; tells the os to make the system call
    mov eax, 1; tells the os to use the exit system call
    mov ebx, 0; provides the exit status to the system
    int 0x80; makes the system call
