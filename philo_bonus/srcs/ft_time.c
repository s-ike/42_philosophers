/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:30 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/17 23:02:03 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time.h"

t_time
	ft_get_mstime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (FT_TIME_ERROR);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000LL);
}

bool
	ft_usleep(int usleep_time)
{
	t_time	crnt_time;
	t_time	end_time;

	crnt_time = ft_get_mstime();
	if (crnt_time == FT_TIME_ERROR)
		return (false);
	end_time = crnt_time + usleep_time;
	while (crnt_time < end_time)
	{
		usleep(500);
		crnt_time = ft_get_mstime();
		if (crnt_time == FT_TIME_ERROR)
			return (false);
	}
	return (true);
}
