#define __TRACING_HEADERS
#include "../headers/syscall_printer.h"
#include "../headers/headers.h"

void Prbrk(long pid , pt_user_regs *regs){
	if (regs->rdi == 0 ){
		printf("brk(NULL) \t\t\t= ");
	}
	else{
		printf("brk(0x%llx) \t\t\t= ",regs->rax);
	}
}


void outbrk(pt_user_regs *regs){
	if (regs->rax == 0)
		printf("NULL\n");
	else
		printf("0x%llx\n",regs->rax);
}

syscall_printer func_12 = (syscall_printer)&Prbrk;
syscall_printer outf_12 = (syscall_printer)&outbrk;
