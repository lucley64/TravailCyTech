section .data 
msg db 'Hello, world!', 0xa ;string to be printed
len equ $ - msg ;lenght of the string

section .text 
    global _start ;must be declared for linker

_start: ;tells linker entry point
    mov edx, len    ;message length
    mov ecx, msg    ;message to write
    mov ebx, 1      ;file descroptor
    mov eax, 4      ;system call number
    int 0x80        ;call kernel

    mov eax, 1      ;system call number
    mov ebx, 0      ;   0 = exit code
    int 0x80        ;call kernel
