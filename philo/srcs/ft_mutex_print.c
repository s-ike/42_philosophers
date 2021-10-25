/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:19:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/25 17:59:29 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mutex_print.h"

static char
	*get_msg(t_philo_status status)
{
	if (status == ST_DIE)
		return (COLOR_RED"died"COLOR_RESET);
	else if (status == ST_FORK)
		return (COLOR_CYAN"has taken a fork"COLOR_RESET);
	else if (status == ST_EAT)
		return (COLOR_GREEN"is eating"COLOR_RESET);
	else if (status == ST_SLEEP)
		return (COLOR_BLUE"is sleeping"COLOR_RESET);
	else if (status == ST_THINK)
		return (COLOR_YELLOW"is thinking"COLOR_RESET);
	else if (status == ST_END)
		return ("Error");
	return (NULL);
}

static void
	print(t_philo *philo, t_philo_status status)
{
	const t_time	crnt_time = ft_get_mstime();
	const t_time	elapsed_time = crnt_time - philo->info->start_time;

	printf("%lld %d %s\n", elapsed_time, philo->id, get_msg(status));
}

void
	ft_mutex_print(t_philo *philo, t_philo_status status)
{
	pthread_mutex_lock(&philo->info->print_lock);
	if (status == ST_DIE && !philo->info->someone_is_dead)
	{
		philo->info->someone_is_dead = true;
		print(philo, ST_DIE);
	}
	else if (status == ST_END || !philo->info->someone_is_dead)
	{
		print(philo, status);
	}
	pthread_mutex_unlock(&philo->info->print_lock);
}
