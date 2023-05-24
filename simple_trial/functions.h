#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _POSIX_SOURCE
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void prompt_and_read_input(char **cont, ssize_t *c, int val_fd);
void handle_built_in_commands(char **tokenizado, char **env);
void execute_child_process(int argc, char *argv[], char **env);
void handle_parent_process(int *status, int val_fd);
int main(int argc, char *argv[], char **env);
char *l_path(char *cont, char **env);
char *str_concat(char *s1, char *s2, char *s3);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_getenv(char *name, char **env);
char *read_line(ssize_t *c);
char **words(char *line, char *sep);

#endif
