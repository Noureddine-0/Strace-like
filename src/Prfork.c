#define __TRACING_HEADERS
#include "../headers/syscall_printer.h"
#include "../headers/headers.h"

void Prfork(){
	printf("fork()\t\t\t= ");
}

void outfork(pt_user_regs *regs){
	printf("%lld\n",regs->rax);
}

syscall_printer func_57 = (syscall_printer)&Prfork;
syscall_printer outf_57 = (syscall_printer)&outfork;