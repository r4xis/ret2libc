#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln()
{
	char buf[64];
	gets(buf);
}

int main(int argc, char **argv)
{
	vuln();

	return 0;
}
