#include "shell.h"

char *get_location(char *command)
{
    char *path;
    char *path_copy;
    int command_len;
    char *path_token;
    char *file_path;
    int directory_len;
    struct stat buffer;

    path = getenv("PATH");

    if (path)
    {
        /*duplicate hte path*/
        path_copy = strdup(path);

        /*get length of the command*/
        command_len = strlen(command);

        /*break down the path_copy into tokens*/
        path_token = strtok(path_copy, ":");

        while(path_token != NULL)
        {
            /*length of tokens*/
            directory_len = strlen(path_token);

            /*allocating memory for the path*/
            file_path = malloc(command_len + directory_len + 2);

            /*making the file_path*/
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            /*checking if the file exist*/
            if (stat(file_path, &buffer) == 0)
            {
                /*return 0 means that the file_path is valid*/
                /*free up allocated memory before returning file_path*/
                free(path_copy);
                /*returning file_path*/
                return (file_path);
            }
            else
            {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        }

        /*if we don't get any file_path that exists for the command*/
        free(path_copy);

        /*see if the command itself is a file_path that exists*/
        if (stat(command, &buffer) == 0)
        {
            return (NULL);
        }

        return (NULL);
    }

    return (NULL);
}