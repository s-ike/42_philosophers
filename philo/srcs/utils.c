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

long
	ft_atol(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = (num * 10) + (*str++ - '0');
		if (num >> 63)
		{
			if (sign == -1)
				return (-__LONG_MAX__ - 1);
			return (__LONG_MAX__);
		}
	}
	return (num * sign);
}

int
	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}
