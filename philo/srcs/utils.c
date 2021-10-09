#include "philo.h"

bool
	ft_philo_atoi(const char *str, int *n)
{
	unsigned int	num;

	num = 0;
	while (ft_isspace(*str))
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
