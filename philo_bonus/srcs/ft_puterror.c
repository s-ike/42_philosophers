/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:08:09 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 14:00:00 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puterror.h"

int
	ft_puterror(const char *str)
{
	return (printf("%s%s%s\n", COLOR_B_RED, str, COLOR_RESET));
}

int
	ft_puterror_and_return(const char *str, int return_status)
{
	ft_puterror(str);
	return (return_status);
}
