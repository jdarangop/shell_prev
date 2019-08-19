/**
  * _cd - Change the directory.
  * @args: List of arguments passed from parsing.
  * Return: 1 if works.
  */
int _cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}
/**
  * _help - Display the help about a command.
  * Return: 1 if works.
  */
int _help(void)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};

	for (i = 0; i < 3; i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	return (1);
}

/**
  * _exit - Exit to the shell.
  * Return: 0 if works.
  */
int _exit(void)
{
	return (0);
}
