#include "shell.h"

static void sig_handler(int sig)
{
	(void)sig;
	_puts("\n");
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	unsigned int non_interactive = 0, i;
	size_t getline_buffer = 0;
	variables_t vbles = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	vbles.argv = argv;
	vbles.env = read_env(environment);
	signal(SIGINT, sig_handler);

	if (!isatty(STDIN_FILENO))
		non_interactive = 1;
	if (non_interactive == 0)
		_puts("$ ");

	while (getline(&(vbles.buffer), &(getline_buffer), stdin))
	{
		vbles.count++;
		vbles.commands = split_line(vbles.buffer, ";");
		for (i = 0; vbles.commands && vbles.commands[i] != NULL; i++)
		{
			        if (vbles.arguments && vbles.arguments[0])
				if (is_builtin(&vbles) == NULL)
					check_for_path(&vbles);
			free(vbles.arguments);
		}
		free(vbles.buffer);
		free(vbles.commands);
		if (non_interactive == 0)
			_puts("$ ");
		vbles.buffer = NULL;
	}
	if (non_interactive == 0)
		_puts("\n");
	free_env(vbles.env);
	free(vbles.buffer);
	exit(vbles.status);
}
