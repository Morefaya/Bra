#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strcmp(char *str, int c)
{
	while (str && *str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

int	check_last(char *str, int i, int last)
{
	int	x;

	str[i] = 'A';
	str[last] = 'A';
	x = 1;
	while (x <= last && !ft_strcmp("({[", str[last - x]))
		x++;
	return (last - x);
}

int	brackets(char *str)
{
	int	last;
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	last = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			j++;
			last = i;
		}
		else if (str[i] == '{')
		{
			k++;
			last =  i;
		}
		else if (str[i] == '[')
		{
			l++;
			last = i;
		}
		else if (str[i] == ')')
		{
			j--;
			if (str[last] != '(')
				return (1);
			last = check_last(str, i, last);
		}
		else if (str[i] == '}')
		{
			k--;
			if (str[last] != '{')
				return (2);
			last = check_last(str, i, last);
		}
		else if (str[i] == ']')
		{
			l--;
			if (str[last] != '[')
				return (3);
			last = check_last(str, i, last);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (!(ret = brackets(av[i])))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;		
		}
	}
	else
		write(1, "\n", 1);
	return (ret);
}
