/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:19:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/17 16:05:32 by sikeda           ###   ########.fr       */
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
	print(t_philo *philo, t_philo_status status)
{
	static t_time	start = 0;
	const t_time	crnt_time = ft_get_mstime();

	if (start == 0)
		start = ft_get_mstime();
	// printf("%lld %d %s\n", crnt_time - start, philo->id, get_msg(status));
	ft_putnbr_fd(crnt_time - start, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putnbr_fd(philo->id, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putendl_fd(get_msg(status), STDOUT_FILENO);
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
	else if (!philo->info->someone_is_dead)
		print(philo, status);
	pthread_mutex_unlock(&philo->info->print_lock);
}
