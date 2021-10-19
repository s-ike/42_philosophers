/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isover_intrange.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:03:16 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 12:43:32 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int
	ft_isover_intrange(const char *str)
{
	uint64_t	num;
	bool		is_minus;

	is_minus = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		is_minus = true;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		if (is_minus && (uint64_t)__INT_MAX__ + 1 < num)
			return (-1);
		else if (!is_minus && (uint64_t)__INT_MAX__ < num)
			return (1);
		str++;
	}
	return (0);
}
