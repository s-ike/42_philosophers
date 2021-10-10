/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 16:17:17 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_philos.h"

static void
	ph_do(t_philo *philo, t_philo_status status, t_time crnt_time)
{
	ft_mutex_print(philo, status, crnt_time);
	if (status == ST_EAT)
		ft_usleep(philo->info->time_to_eat);
	else if (status == ST_SLEEP)
		ft_usleep(philo->info->time_to_sleep);
}

void
	ph_eat(t_philo *philo)
{
	philo->last_eat = ft_get_mstime();
	ph_do(philo, ST_EAT, philo->last_eat);
}

void
	ph_sleep(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	ph_do(philo, ST_SLEEP, crnt_time);
}

void
	ph_think(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	ph_do(philo, ST_THINK, crnt_time);
}

void
	ph_died(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->time_to_die < crnt_time - philo->last_eat)
		philo->is_dead = true;
	if (philo->is_dead)
		ph_do(philo, ST_DIE, crnt_time);
}

void
	*philo(void *philo_p)
{
	t_philo	*philo;

	philo = philo_p;
	while (philo->is_dead == false)
	{
		pthread_mutex_lock(&philo->info->fork_lock[philo->id - 1]);
		pthread_mutex_lock(&philo->info->fork_lock[philo->id % philo->info->num_of_philo]);
		ph_eat(philo);
		pthread_mutex_unlock(&philo->info->fork_lock[philo->id - 1]);
		pthread_mutex_unlock(&philo->info->fork_lock[philo->id % philo->info->num_of_philo]);

		ph_sleep(philo);
		ph_think(philo);
		ph_died(philo);
	}
	return (NULL);
}

t_status
	ft_start_philos(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, philo, (void *)&philos[i]))
			return (FAILURE);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (FAILURE);
	}
	return (SUCCESS);
}
