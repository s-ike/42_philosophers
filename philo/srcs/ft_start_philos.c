/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 18:51:57 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_start_philos.h"

static void
	philo_die(t_philo *philo)
{
	if (!philo->info->someone_is_dead)
		ft_philo_do(philo, ST_DIE);
}

static void
	*monitor(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	usleep(500);
	while (true)
	{
		if (philo->info->someone_is_dead)
			return (NULL);
		if (ft_check_if_dead(philo))
		{
			philo_die(philo);
			return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}

static void
	*philo(void *philo_p)
{
	t_philo		*philo;
	pthread_t	monitor_tid;

	philo = (t_philo *)philo_p;
	if (pthread_create(&monitor_tid, NULL, monitor, philo))
		return (NULL);
	if (pthread_detach(monitor_tid))
		return (NULL);
	while (!philo->info->someone_is_dead)
		ft_philo_routine(philo);
	return (NULL);
}

t_status
	ft_start_philos(t_info *info, t_philo *philos)
{
	const t_time	crnt_time = ft_get_mstime();
	int				i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		philos[i].last_ate = crnt_time;
		if (pthread_create(&philos[i].thread, NULL, philo, (void *)&philos[i]))
			return (ft_puterror_and_return(ERR_THREAD, FAILURE));
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (ft_puterror_and_return(ERR_THREAD, FAILURE));
	}
	return (SUCCESS);
}
