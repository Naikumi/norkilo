#ifndef MAIN_H
#define MAIN_H
#define _POSIX_SOURCE
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void prompt_and_read_input(char **con, ssize_t *ch, int value_fd);
void handle_built_in_commands(char **tokenizado, char **environ);
void execute_child_process(int argc, char *argv[], char **environ);
void handle_parent_process(int *status, int value_fd);
int main(int argc, char *argv[], char **environ);
char *_path(char *con, char **environ);
char *str_concate(char *str1, char *str2, char *str3);
int _strcmp(char *str1, char *str2);
int _strlen(char *s);
char *_getenviron(char *name, char **environ);
char *read_lines(ssize_t *ch);
char **words(char *lineptr, char *separ);

#endif
