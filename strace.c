#define __TRACING_HEADERS

#include <errno.h>
#include <signal.h>

#include "headers/headers.h"
#include "headers/syscall_64.h"
#include "headers/syscall_printer.h"
#include "headers/console_writer.h"


int start_tracing(char *program[]){

	pid_t pid = fork();
	
	switch(pid){
		case -1 :
			FATAL();
		case 0:
			ptrace(PT_TRACE_ME,0,0,0);
			execvp(program[0],program);
			FATAL();
	}

	waitpid(pid,0,0);
	ptrace(PTRACE_SETOPTIONS,pid,0,PTRACE_O_EXITKILL);
	for (;;){
		syscall_trace(pid);
	}
}

int main(int argc, char const *argv[])
{
	#ifdef __x86_64__

		if (argc < 2)
			USAGE("%s <name of the program to trace>",argv[0]);

		char *program[argc];

		for (int i = 0;i < argc -1 ; i++){
			program[i] = argv[i+1]; 
		}

		program[argc] = NULL;
		start_tracing(program);
	#else
		printf("Not supported architecture");
	#endif	
	
	return 0;
}
