/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:53:45 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 18:53:46 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_routine.h"

static bool
	check_if_dead(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->time_to_die <= crnt_time - philo->last_ate)
		return (true);
	return (false);
}

static void
	philo_do(t_philo *philo, t_philo_status status)
{
	if (philo->finished)
		return ;
	if (status != ST_DIE && check_if_dead(philo))
		return ;
	ft_sem_print(philo, status);
}

static void
	philo_eat(t_philo *philo)
{
	philo_do(philo, ST_EAT);
	philo->last_ate = ft_get_mstime();
	philo->eat_cnt++;
	if (philo->eat_cnt < 0)
		philo->eat_cnt = 0;
	if (philo->eat_cnt == philo->info->num_must_eat
		&& philo->info->num_must_eat != NO_OPTION)
	{
		philo->finished = true;
	}
	ft_usleep(philo->info->time_to_eat);
}

static void
	*monitor(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	usleep(500);
	while (true)
	{
		if (philo->finished)
			return (NULL);
		if (check_if_dead(philo))
		{
			philo_do(philo, ST_DIE);
			return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}

void
	ft_philo_routine(t_info *info, t_philo *philo)
{
	pthread_t	monitor_tid;

	if (pthread_create(&monitor_tid, NULL, monitor, philo))
		exit(ft_puterror_and_return(ERR_THREAD, EXIT_FAILURE));
	if (pthread_detach(monitor_tid))
		exit(ft_puterror_and_return(ERR_THREAD, EXIT_FAILURE));
	philo->last_ate = ft_get_mstime();
	while (philo->finished == false)
	{
		sem_wait(info->forks_lock);
		philo_do(philo, ST_FORK);
		if (info->num_of_philo == 1)
			exit(EXIT_SUCCESS);
		sem_wait(info->forks_lock);
		philo_do(philo, ST_FORK);
		philo_eat(philo);
		sem_post(info->forks_lock);
		sem_post(info->forks_lock);
		philo_do(philo, ST_SLEEP);
		ft_usleep(info->time_to_sleep);
		philo_do(philo, ST_THINK);
	}
	exit(EXIT_SUCCESS);
}
