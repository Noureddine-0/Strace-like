#define __TRACING_HEADERS
#include "../headers/syscall_printer.h"
#include "../headers/headers.h"
#include "../headers/console_writer_helper.h"

char *flags_array[34] = {"O_RDONLY","O_WRONLY","O_RDWR","O_ACCMODE",NULL,
                        "O_CREAT","O_EXCL",NULL,"O_NOCTTY",NULL,"O_TRUNC",
                        "O_APPEND",NULL,"O_NONBLOCK",NULL,"O_DSYNC","FASYNC",NULL,"O_DIRECT",
                        NULL,"O_LARGEFILE","O_DIRECTORY",NULL,"O_NOFOLLOW",
                        NULL,"O_NOATIME","O_CLOEXEC",NULL,"__O_SYNC",
                        NULL,"O_PATH","__O_TMPFILE",NULL,"O_NDELAY"};



void Propen(long pid ,pt_user_regs *regs){
	long long int flags = regs->rsi;
    long long int permissions = regs->rdx;
    int rest,result,tracker;
    int entered = 0;

    printf("open(");
    printf("\"");
    print_filename(pid,regs->rdi);
    printf("\", ");
    rest = flags % 8 ;
    tracker = rest;
    result = (flags-rest) / 8;
    result =  result / 8;

    printf("%s",flags_array[rest]);
    while (result != 0){
        rest = result % 8;
        result = (result-rest) / 8;
        if(rest!=0)
            printf("|%s",flags_array[4+ (entered)*5 + rest]);
        entered++;
    }
    printf(" ,%d) ",permissions);
}

void outopen(pt_user_regs *regs){
        printf("= %lld\n", regs->rax);
}

syscall_printer func_2 = (syscall_printer)&Propen;
syscall_printer outf_2 = (syscall_printer)&outopen;