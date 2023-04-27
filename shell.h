#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

/*execmd.c*/
void execmd(char **argv);

/*get_location.c*/
char *get_location(char *command);