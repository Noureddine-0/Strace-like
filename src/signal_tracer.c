#define __TRACING_HEADERS

#include <errno.h>
#include <signal.h>

#include "headers/headers.h"
#include "headers/syscall_64.h"
#include "headers/syscall_printer.h"
#include "headers/console_writer.h"

void signal_trace(pid_t pid){
	siginfo_t signal_info ;
	
}