#define __TRACING_HEADERS

#include "../headers/headers.h"
#include "../headers/syscall_printer.h"

void Prexit(long pid , pt_user_regs *regs){
	printf("exit(%d)\t\t\t",regs->rdi);
}

void outexit(pt_user_regs *regs){
	printf("= ",regs->rax);
}

syscall_printer func_60= (syscall_printer)&Prexit;
syscall_printer outf_60= (syscall_printer)&outexit;
