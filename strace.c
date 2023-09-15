#define __TRACING_HEADERS

#include <errno.h>
<<<<<<< HEAD
#include "headers.h"
#include "syscall_64.h"
#include "syscall_printer.h"
#include "console_writer.h"

#define FATAL() \
    do { \
        fprintf(stderr, "strace"); \
        perror(" "); \
        exit(EXIT_FAILURE); \
    } while (0)

#define USAGE(...) \
    do { \
        fprintf(stderr, "Usage : " __VA_ARGS__); \
        fputc('\n', stderr); \
        exit(EXIT_FAILURE); \
    } while (0)

int trace(char *program[]) {
    pt_user_regs regs;
    pid_t pid = fork();

    switch (pid) {
        case -1:
            FATAL(); // Fork failed, exit with an error
        case 0:
            // Child process
            ptrace(PT_TRACE_ME, 0, 0, 0); // Trace this child process
            execvp(program[0], program); // Execute the specified program
            FATAL(); // If execvp fails, exit with an error
    }

    waitpid(pid, 0, 0);
    ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_EXITKILL);

    for (;;) {
        if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
            FATAL(); // Error in tracing syscall entry

        if (waitpid(pid, 0, 0) == -1)
            FATAL(); // Error waiting for the child process

        if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1)
            FATAL(); // Error getting the registers of the child process

        char *syscall = all_syscalls[regs.orig_rax].name;
        if (regs.orig_rax == (long long int)2) {
            func_2((long)pid, &regs); // Handle syscall 2 specifically for now , newer syscalls will be added
        } else {
            printf("%s", syscall); // Print the syscall name
        }

        if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
            FATAL(); // Error in tracing syscall exit

        if (waitpid(pid, 0, 0) == -1)
            FATAL(); // Error waiting for the child process

        if (ptrace(PTRACE_GETREGS, pid, 0, &regs) == -1) {
            puts(" = ?\n");
            if (errno == ESRCH)
                printf("+++ exited with %lld +++", regs.rdi); // Print exit status
            exit(regs.rdi); // Exit with the exit status
            FATAL(); // If there's an error in getting the registers
        }

        printf("= 0x%llx\n", regs.rax); // Print the return value of the syscall
    }
}

int main(int argc, char const *argv[]) {
#ifdef __x86_64__
    if (argc < 2)
        USAGE("%s <name of the program to trace>", argv[0]);

    char *program[argc];

    for (int i = 0; i < argc - 1; i++) {
        program[i] = argv[i + 1];
    }

    program[argc] = NULL;
    trace(program); // Start tracing the specified program
#else
    printf("Not supported architecture");
#endif

    return 0;
}
=======
#include "headers/headers.h"
#include "headers/syscall_64.h"
#include "headers/syscall_printer.h"
#include "headers/console_writer.h"

#define FATAL() \
	do{ \
		fprintf(stderr,"strace");\
		perror(" "); \
		exit(EXIT_FAILURE); \
	} while (0)

#define USAGE(...) \
	do{ \
		fprintf(stderr,"Usage : "__VA_ARGS__);\
		fputc('\n',stderr);\
		exit(EXIT_FAILURE);\
	}while(0)


int trace(char *program[]){

	pt_user_regs regs;
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

	for(;;){
		if(ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
			FATAL();
		if(waitpid(pid, 0, 0) == -1)
			FATAL();

		if(ptrace(PTRACE_GETREGS, pid, 0 ,&regs) ==-1)
			FATAL();

		char *syscall = all_syscalls[regs.orig_rax].name;
		if(regs.orig_rax==(long long int)60)
			func_60((long)pid,&regs); // line only to test each syscall
		
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
		if(regs.orig_rax==(long long int)60)
			outf_60(&regs); // No need , already exit
		
		else
			printf("= %lld\n",regs.rax);
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
		trace(program);
	#else
		printf("Not supported architecture");
		return 0;
	#endif	
	
	return 0;
}
>>>>>>> 8565ea9 (Modify the repo and make it more clean)
