#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	printf("argc: %d\n", argc);

	for (int i = 0; argv[i] != NULL; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	return 0;
}
