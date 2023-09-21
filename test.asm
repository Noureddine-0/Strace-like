section .text
global _start

_start:

    mov rdi,0x0065742f706d742f
    mov rsi,1
    mov rdx , 0
    push rdi
    push rsp
    pop rdi
    mov rax,2
    syscall
    mov rax ,60
    mov rdi,1
    syscall
