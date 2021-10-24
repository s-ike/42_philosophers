/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:57:25 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 15:43:52 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sem_print.h"

static char
	*get_msg(t_philo_status status)
{
	if (status == ST_DIE)
		return (COLOR_RED"is died"COLOR_RESET);
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
	const t_time	elapsed_time = crnt_time - philo->start_time;

	printf("%lld %d %s\n", elapsed_time, philo->id, get_msg(status));
}

void
	ft_sem_print(t_philo *philo, t_philo_status status)
{
	sem_wait(philo->info->print_lock);
	if (status == ST_DIE)
	{
		print(philo, ST_DIE);
		exit(EXIT_SOMEONE_IS_DEAD);
	}
	print(philo, status);
	sem_post(philo->info->print_lock);
}
