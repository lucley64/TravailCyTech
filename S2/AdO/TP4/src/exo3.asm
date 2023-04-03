section .data
    prompt1 db 'Entrer a : '
    lenprompt1 equ $ - prompt1

    prompt2 db 'Entrer b : '
    lenprompt2 equ $ - prompt2

    resu db 'a + b = '
    lenresu equ $ - resu

    nl db ,13,10
    lennl equ $ - nl

section .bss
    inp resb 5


section .text
    global _start

_start: 
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt1
    mov edx, lenprompt1
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, inp
    mov edx, 5




    mov eax, 1      ;system call number
    mov ebx, 0      ;   0 = exit code
    int 0x80        ;call kernel
