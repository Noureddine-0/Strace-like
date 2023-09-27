/*Some header files may not be usuable for the program in hand , but because i often use those
*headers i got tired of typing them many times.
*/
#ifndef __HEADERS_H
#define __HEADERS_H

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

#ifdef __PRIMITIVE_HEADERS
		
#define __ESSENTAIL
		
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#endif

#ifdef __TRACING_HEADERS

#ifndef __ESSENTAIL
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#endif

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <syscall.h>

typedef struct user_regs_struct pt_user_regs;

#endif
#endif



