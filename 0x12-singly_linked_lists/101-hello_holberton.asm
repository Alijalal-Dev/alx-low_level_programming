section .data
    msg db "Hello, Holberton", 0

section .text
    global _start

_start:
    mov rdi, msg
    xor rax, rax
    call printf

    mov rax, 60
    xor rdi, rdi
    syscall
