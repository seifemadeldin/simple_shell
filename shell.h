#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int str_cmp(char *s1, char *s2);
size_t str_ncmp(char *s1, char *s2, size_t n);
int str_len(char *s);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);
int _putchar(char c);

char *get_path(char **env);
int _split(char **arg, char **env);
char *my_getline(void);
void get_env(char **env);
char **get_token(char *lineptr);
void exit_command(char **args, char *lineptr, int _exit);
int fork_func(char **arg, char **av, char **env,
char *lineptr, int np, int c);
char *my_strtok(char *str, const char *delim);

#endif /* SHELL_H */
