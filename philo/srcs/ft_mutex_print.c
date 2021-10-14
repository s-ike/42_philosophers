/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:19:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/13 22:08:48 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mutex_print.h"

static char
	*get_msg(t_philo_status status)
{
	if (status == ST_DIE)
		return (COLOR_B_RED"is died"COLOR_RESET);
	else if (status == ST_FORK)
		return (COLOR_CYAN"has taken a fork"COLOR_RESET);
	else if (status == ST_EAT)
		return (COLOR_GREEN"is eating"COLOR_RESET);
	else if (status == ST_SLEEP)
		return (COLOR_BLUE"is sleeping"COLOR_RESET);
	else if (status == ST_THINK)
		return (COLOR_YELLOW"is thinking"COLOR_RESET);
	return (NULL);
}

static void
	print(t_philo *philo, t_philo_status status, t_time time)
{
	static t_time	start = 0;

	if (start == 0)
		start = ft_get_mstime();
	printf("%lld %d %s\n", time - start, philo->id, get_msg(status));
}

void
	ft_mutex_print(t_philo *philo, t_philo_status status, t_time time)
{
	pthread_mutex_lock(&philo->info->print_lock);
	if (status == ST_DIE && !philo->info->someone_is_dead)
	{
		philo->info->someone_is_dead = true;
		print(philo, status, time);
	}
	else if (!philo->info->someone_is_dead)
		print(philo, status, time);
	pthread_mutex_unlock(&philo->info->print_lock);
}