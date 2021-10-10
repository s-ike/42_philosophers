/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:30 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 11:05:31 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

long long
	get_mstime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000LL);
}

long long
	get_microtime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000000LL + time.tv_usec);
}
