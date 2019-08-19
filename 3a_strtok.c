#include "shell.h"

int _strcspn(char *s, char *delim)
{
	int counter = 0, i;

	while (*s)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
				return (counter);
		}
		counter++;
		s++;
	}
	return (counter);
}

int _strspn(char *s, char *delim)
{
	int i;

	for (i = 0; (s[i] == delim[i]) && (s[i] != '\0' && delim[i] != '\0'); i++)
	{
		;
	}
	i++;
	return (i);
}

char *_strtok_r(char *s, const char *delim, char **save_ptr)
{
	char *end;

	if (s == NULL)
		s = *save_ptr;

	if (*s == '\0')
	{
		*save_ptr = s;
		return (NULL);
	}

	s += _strspn(s, delim);

	if (*s == '\0')
	{
		*save_ptr = s;
		return (NULL);
	}
	end = s + _strcspn(s, delim);

	if (*end == '\0')
	{
		*save_ptr = end;
		return (s);
	}

	*end = '\0';
	*save_ptr = end + 1;
	return (s);
}

char *_strtok(char *s, const char *delim)
{
	static char *olds;

	return (_strtok_r(s, delim, &olds));
}
