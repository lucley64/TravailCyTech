section .data
    prompt1 db 'Entrer a : '
    lenprompt1 equ $ - prompt1

    prompt2 db 'Entrer b : '
    lenprompt2 equ $ - prompt2

    resadd db 'a + b = '
    lenresadd equ $ - resadd

    ressub db 'a - b = '
    lenressub equ $ - ressub

    resmul db 'a × b = '
    lenresmul equ $ - resmul

    resdiv db 'a ÷ b = '
    lenresdiv equ $ - resdiv

    nl db 0xA
    lennl equ $ - nl


section .bss
    inp1 resb 10
    inp2 resb 10
    res resb 10
    resres resb 10


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
    mov ecx, inp1
    mov edx, 10
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, prompt2
    mov edx, lenprompt2
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, inp2
    mov edx, 10
    int 0x80


    mov eax, [inp1]
    sub eax, '0'
    mov ebx, [inp2]
    sub ebx, '0'

    add eax, ebx

    add eax, 0x30
    
    mov [res], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, resadd
    mov edx, lenresadd
    int 0x80

    printAdd:
        mov eax, [res]
        sub eax, 0x30
        mov ebx, 0xA
        div ebx
        add eax, 0x30
        mov [res], eax
        mov [resres], eax

        mov eax, 4
        mov ebx, 1
        mov ecx, res
        mov edx, 10
        int 0x80


        mov eax, [resres]
        mov [res], eax
        cmp eax, 0x0
        jne printAdd

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, lennl
    int 0x80

    mov eax, [inp1]
    sub eax, '0'
    mov ebx, [inp2]
    sub ebx, '0'

    sub eax, ebx

    add eax, 0x30
    
    mov [res], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, ressub
    mov edx, lenressub
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, res
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, lennl
    int 0x80

    mov eax, [inp1]
    sub eax, '0'
    mov ebx, [inp2]
    sub ebx, '0'

    mul ebx

    add eax, 0x30
    
    mov [res], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, resmul
    mov edx, lenresmul
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, res
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, lennl
    int 0x80

    mov eax, [inp1]
    sub eax, '0'
    mov ebx, [inp2]
    sub ebx, '0'

    div ebx

    add eax, 0x30
    
    mov [res], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, resdiv
    mov edx, lenresdiv
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, res
    mov edx, 1
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, lennl
    int 0x80

    mov eax, 1      ;system call number
    mov ebx, 0      ;   0 = exit code
    int 0x80        ;call kernel
