#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	size_t n = 10;
	char *buf = NULL;

	printf("enter name ");
	getline(&buf, &n, stdin);

	printf("Name is %sBuffer size is %ld\n",buf, n);

	free(buf);

	return 0;
}
	
