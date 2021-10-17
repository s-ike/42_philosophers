/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:12:32 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/17 15:58:24 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static void	recursive_putnbr(unsigned int n, int fd)
{
	if (n / 10 == 0)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	recursive_putnbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int num, int fd)
{
	unsigned int	un;

	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		un = -num;
	}
	else
		un = num;
	recursive_putnbr(un, fd);
}
