#include "functions.h"

void prompt_and_read_input(char **con, ssize_t *ch, int value_fd)
{
	if (value_fd != 0)
	write(1, "#cisfun$ ", 10);

	*con = read_line(c);

	if (*ch == EOF)
	{
		free(*con);
		write(1, "\n", 2);
		exit(3);
	}

	if (**con == '\n')
	{
		free(*con);
		return;
	}
}

void handle_built_in_commands(char **tokenizado, char **environ)
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
		int j = 0;

		while (environ[j] != NULL)
		{
			write(1, environ[j], _strlen(environ[j]));
			write(1, "\n", 1);
			j++;
		}
	}
}

void execute_child_process(int argc, char *argv[], char **environ)
{
	char *con, *result;
	char **tokenizado;
	ssize_t ch;
	int value_fd = 0;

	value_fd = isatty(STDIN_FILENO);

	if (argc == 1)
	{
		prompt_and_read_input(&con, &ch, value_fd);
		if (con == NULL)
			return;

	tokenizado = words(con, " \t\r\n");

	handle_built_in_commands(tokenizado, environ);

	result = l_path(tokenizado[0], environ);

	if (execve(result, tokenizado, NULL) == -1)
	{
		free(result);
		free(tokenizado);
		perror(argv[0]);
		exit(EXIT_FAILURE);
		if (value_fd == 0)
			exit(2);
		return;
	}
	}
}

int main(int argc, char *argv[], char **environ)
{
	int status = 0, value_fd = 0;
	pid_t child;

	while (1)
	{
	child = fork();
	if (child == -1)
	{
	perror("Error: child");
	return (-1);
	}

	value_fd = isatty(STDIN_FILENO);

	if (child == 0)
	{
	execute_child_process(argc, argv, environ);
	}
	else
	{
	wait(&status);
	status = WEXITSTATUS(status);
	if (status == 2)
	exit(127);
	if (value_fd == 0 || status == 3)
	{
	break;
	}
	}
	}

	return (0);
}
