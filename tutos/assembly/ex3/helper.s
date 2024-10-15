
.section .data
    msg:
    .ascii "Hello! from the other side!\n"
    len = . - msg

.section .text


.global displayMessage


displayMessage:
    mov $4, %eax
    mov $1, %ebx
    mov $msg, %ecx
    mov $len, %edx
    int $0x80
    mov $1, %eax
    mov $0, %ebx
    int $0x80
