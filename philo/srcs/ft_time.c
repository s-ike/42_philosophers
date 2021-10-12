/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:30 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 12:37:20 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time.h"

t_time
	ft_get_mstime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000LL);
}

t_time
	ft_get_microtime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000000LL + time.tv_usec);
}

bool
	ft_usleep(int usleep_time)
{
	t_time	crnt_time;
	t_time	end_time;

	crnt_time = ft_get_mstime();
	if (crnt_time == -1)
		return (false);
	end_time = crnt_time + usleep_time;
	while (crnt_time < end_time)
	{
		usleep(500);
		crnt_time = ft_get_mstime();
		if (crnt_time == -1)
			return (false);
	}
	return (true);
}
