#include "shell.h"
/**
 * main - main arguments functions
 * @ac:count of argumnents
 * @argv: arguments
 * Return: _exit = 0.
 */

int main(int ac, char **argv)
{
    char *prompt = "#cisfun$ ";
    char *lineptr = NULL;
    size_t n = 0; 
    ssize_t numchars_read;
    char *lineptr_copy = NULL;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    /* declaring void variables */
    (void)ac;

    /* create an infinite loop to make the shell always working*/
    while (1)
    {
        printf("%s", prompt);
        numchars_read = getline(&lineptr, &n, stdin);
        
        /* check if the getline function failed or reached EOF or user use CTRL + D */ 
        if (numchars_read == -1)
        {
            printf("Exiting shell....\n");
            return (-1);
        }

        /*allocate space to store a copy of lineptr*/
        lineptr_copy = malloc(sizeof(char) * numchars_read);
        if (lineptr_copy == NULL)
        {
            perror("Memory allocation error");
            return(-1);
        }

        /*copying lineptr to lineptr_copy*/
        strcpy(lineptr_copy, lineptr);

        /*Spliting lineptr into tokens*/
        token = strtok(lineptr, delim);

        /*calculate the total number of tokens*/
        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }

        num_tokens++;

        /*allocate space to hold array of tokens*/
        argv = malloc(sizeof(char *) * num_tokens);

        /*storing the tokens in an array*/
        token = strtok(lineptr_copy, delim);
        
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }

        argv[i] = NULL;

        /*execute the command in argv*/
        execmd(argv);
    }

    /* free up allocated memory */
    free(lineptr);
    free(lineptr_copy);

    return (0);
}