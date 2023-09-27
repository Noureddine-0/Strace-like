#define __TRACING_HEADERS

#include <errno.h>
#include <signal.h>
#include "../headers/headers.h"
#include "../headers/syscall_64.h"
#include "../headers/syscall_printer.h"
#include "../headers/console_writer.h"

void syscall_tracer(pid_t pid){

	pt_user_regs regs;
	if(ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
		FATAL();
	if(waitpid(pid, 0, 0) == -1)
		FATAL();
	if(ptrace(PTRACE_GETREGS, pid, 0 ,&regs) ==-1)
		FATAL();
	char *syscall = all_syscalls[regs.orig_rax].name;
	if(regs.orig_rax==(long long int)12){
		func_12((long)pid , &regs); // line only to test each syscall
	}
	
	else
		printf("%s",syscall);
	if(ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
		FATAL();
	if(waitpid(pid, 0, 0) == -1)
		FATAL();
	if(ptrace(PTRACE_GETREGS,pid,0,&regs)==-1){
		puts("= ?\n");
           if (errno == ESRCH)
           	printf("+++ exited with %lld +++",regs.rdi);
               exit(regs.rdi); 
           FATAL();
	}
	if(regs.orig_rax==(long long int)12)
	outf_12(&regs); // No need , already exit
	else{
		printf("= %lld\n",regs.rax);
	}
}
