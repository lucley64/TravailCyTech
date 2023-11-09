section .data
    ask db 'Entrer un caractere : '
    lenask equ $ - ask

    prout db 'Caractere saisit : '
    lenprout equ $ - prout

section .bss
    char resb 1

section .text
    global _start

_start: 
    mov eax, 4
    mov ebx, 1
    mov ecx, ask
    mov edx, lenask
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, char
    mov edx, 1
    int 0x80


    mov eax, 4
    mov ebx, 1
    mov ecx, prout
    mov edx, lenprout
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, char
    mov edx, 1
    int 0x80


    mov eax, 1      ;system call number
    mov ebx, 0      ;   0 = exit code
    int 0x80        ;call kernel
