#include "functions.h"

void prompt_and_read_input(char **cont, ssize_t *c, int val_fd)
{
    if (val_fd != 0)
        write(1, "#cisfun$ ", 10);

    *cont = read_line(c);

    if (*c == EOF)
    {
        free(*cont);
        write(1, "\n", 2);
        exit(3);
    }

    if (**cont == '\n')
    {
        free(*cont);
        return;
    }
}

void handle_built_in_commands(char **tokenizado, char **env)
{
    int comp = _strcmp(tokenizado[0], "exit");

    if (comp == 0 && tokenizado[1] == NULL)
    {
        free(tokenizado);
        exit(3);
    }

    comp = _strcmp(tokenizado[0], "env");

    if (comp == 0)
    {
        int i = 0;
        while (env[i] != NULL)
        {
            write(1, env[i], _strlen(env[i]));
            write(1, "\n", 1);
            i++;
        }
    }
}

void execute_child_process(int argc, char *argv[], char **env)
{
    char *cont, *result;
    char **tokenizado;
    ssize_t c;
    int val_fd = 0;

    val_fd = isatty(STDIN_FILENO);

    if (argc == 1)
    {
        prompt_and_read_input(&cont, &c, val_fd);

        if (cont == NULL)
            return;

        tokenizado = words(cont, " \t\r\n");

        handle_built_in_commands(tokenizado, env);

        result = l_path(tokenizado[0], env);

        if (execve(result, tokenizado, NULL) == -1)
        {
            free(result);
            free(tokenizado);
            perror(argv[0]);
            if (val_fd == 0)
                exit(2);
            return;
        }
    }
}

int main(int argc, char *argv[], char **env)
{
    int status = 0, val_fd = 0;
    pid_t hijo;

    while (1)
    {
        hijo = fork();
        if (hijo == -1)
        {
            perror("Error: hijo");
            return -1;
        }

        val_fd = isatty(STDIN_FILENO);

        if (hijo == 0)
        {
            execute_child_process(argc, argv, env);
        }
        else
        {
            wait(&status);
            status = WEXITSTATUS(status);
            if (status == 2)
                exit(127);
            if (val_fd == 0 || status == 3)
            {
                break;
            }
        }
    }

    return 0;
}
