#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <stdint.h>

#define MAX_FILENAME_LEN 255

void print_filename(long pid ,long address){
	char local_buffer[MAX_FILENAME_LEN] = {0};

	struct iovec remote_iov={
		.iov_base = (void *)address ,
		.iov_len = MAX_FILENAME_LEN , 
	};

	struct iovec local_iov = {
		.iov_base = local_buffer,
		.iov_len = MAX_FILENAME_LEN,
	};

	ssize_t bytes_read = process_vm_readv(pid, &local_iov, 1, &remote_iov, 1, 0);
	printf("%s",local_buffer);
}

