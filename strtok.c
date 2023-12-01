#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[]= "Simple shell project";
	char *delim = " ";
	char *token;

	token = strtok(str, delim);
	printf("%s ", token);

	token = strtok(NULL, delim);
	printf("%s ", token);

	return 0;
}
