#define __TRACING_HEADERS

#include "../headers/headers.h"
#include "../headers/syscall_printer.h"

void Prclose(long pid , pt_user_regs *regs){
	printf("close(%d)\t\t\t", regs->rdi);
}

void outclose(pt_user_regs *regs){
	printf("= %d\n", regs->rax);
}

syscall_printer func_3 = (syscall_printer)&Prclose;
syscall_printer outf_3 = (syscall_printer)&outclose;

