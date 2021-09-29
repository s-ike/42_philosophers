#include "philo.h"

static int
	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int
	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\t' || c == '\v');
}

bool
	ft_philo_atoi(const char *str, int *n)
{
	unsigned int	num;

	num = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		return (false);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		num = (num * 10) + (*str++ - '0');
		if (__INT_MAX__ < num)
			return (false);
	}
	if (num == 0)
		return (false);
	*n = (int)num;
	return (true);
}
