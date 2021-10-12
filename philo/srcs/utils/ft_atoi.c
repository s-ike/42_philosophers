/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:08:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 11:18:46 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ft_atol(const char *str)
{
	uint64_t	num;
	int			sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
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

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}
