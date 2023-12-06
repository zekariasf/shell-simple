#include "main.h"

int main(int ac __attribute__((unused)), char **argv __attribute__((unused)))
{
	//char *prompt = "(zshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	char *token;
	int num_tokens = 0;
	int i;	
//	int counter;
//	pid_t pid;
	/* declaring void variables */

	(void)ac; //(void)argv;
	/*creating a loop for the shell's prompt */
	//while(1)
	
	printf("$ ");
	nchars_read = getline(&lineptr, &n, stdin);
	if (nchars_read == -1){
              printf("Exiting shell...\n");
              return(-1);
         }
	/* allocate space for a copy of the lineptr*/
	lineptr_copy = malloc(sizeof(char) * nchars_read);
	if (lineptr_copy == NULL){
		perror("tsh: memory allocation error");
		return (-1);
	}
	else
	{
	/*copy lineptr to lineptr_copy */
	strcpy(lineptr_copy, lineptr);
	/*** split the string (lineptr) into an array of words **/
	/* calculate the total number of tokens */
	token = strtok(lineptr, delim);

	while(token != NULL){
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	/* allocate sapce to hold the array of strings */
	argv = malloc(sizeof(char *) * num_tokens);
	
	/* store each token in the argv array */
	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		printf(">>>> %s \n", argv[i]);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	/* print the content of argv */
	/* for (counter = 0; counter<num_tokens-1; counter++)
	{
		printf("%s\n", argv[counter]);
	}*/

	/*pid = fork();
	if (pid == -1)
		return -1;
	if (pid == 0)
	{
		counter = execve(argv[0], argv, NULL);
		if (counter == -1)
			perror("error");
	}
	else
	{
		wait(NULL);
		printf("Done with execve\n");
	}*/
	/* execute the command */

	execmd(argv);

	free(lineptr_copy);
       	free(lineptr);
	}
	return(0);
}
