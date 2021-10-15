/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_arg_nums.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:42:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/15 22:42:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is_valid_arg_nums.h"

bool
	ft_is_valid_arg_nums(int argc, const char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumeric(argv[i])
			|| ft_isover_intrange(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
