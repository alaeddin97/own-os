.global _start

.extern displayMessage

.section .text
    _start:
    call displayMessage
