/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 11:11:27 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_philos.h"

bool
	check_if_dead(t_philo *philo, t_time crnt_time)
{
	if (philo->info->time_to_die < crnt_time - philo->last_eat)
		return (true);
	return (false);
}

static void
	ph_do(t_philo *philo, t_philo_status status, t_time crnt_time)
{
	if (status != ST_DIE && check_if_dead(philo, crnt_time))
		return ;
	// TODO: printを別スレッドで行う実験
	ft_mutex_print(philo, status, crnt_time);
	if (status == ST_EAT)
		ft_usleep(philo->info->time_to_eat);
	else if (status == ST_SLEEP)
		ft_usleep(philo->info->time_to_sleep);
}

void
	ph_died(t_philo *philo, t_time crnt_time)
{
	if (philo->info->someone_is_dead == false)
		ph_do(philo, ST_DIE, crnt_time);
}

void
	ph_take_fork(t_philo *philo, int fork_id)
{
	t_time	crnt_time;

	if (philo->info->someone_is_dead)
		return ;
	pthread_mutex_lock(&philo->info->fork_lock[fork_id]);
	crnt_time = ft_get_mstime();
	ph_do(philo, ST_FORK, crnt_time);
}

void
	ph_drop_forks(t_philo *philo)
{
	const int	left_fork_id = philo->id - 1;
	const int	right_fork_id = philo->id % philo->info->num_of_philo;

	pthread_mutex_unlock(&philo->info->fork_lock[left_fork_id]);
	pthread_mutex_unlock(&philo->info->fork_lock[right_fork_id]);
}

void
	ph_eat(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->someone_is_dead)
		return ;
	philo->last_eat = crnt_time;
	ph_do(philo, ST_EAT, philo->last_eat);
}

void
	ph_sleep(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->someone_is_dead)
		return ;
	ph_do(philo, ST_SLEEP, crnt_time);
}

void
	ph_think(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->someone_is_dead)
		return ;
	ph_do(philo, ST_THINK, crnt_time);
}

void
	*ft_monitor(void *philo_p)
{
	t_philo	*philo;
	t_time	crnt_time;

	philo = (t_philo *)philo_p;
	// TODO: 検証
	usleep(500);
	while (true)
	{
		crnt_time = ft_get_mstime();
		if (check_if_dead(philo, crnt_time))
			break ;
		usleep(500);
	}
	ph_died(philo, crnt_time);
	return (NULL);
}

void
	*philo(void *philo_p)
{
	const t_philo	*const_philo = philo_p;
	const int		left_fork_id = const_philo->id - 1;
	const int		right_fork_id = const_philo->id % const_philo->info->num_of_philo;
	t_philo			*philo;
	pthread_t		monitor;

	philo = (t_philo *)const_philo;
	if (pthread_create(&monitor, NULL, ft_monitor, philo_p))
		return (NULL);
	if (pthread_detach(monitor))
		return (NULL);
	philo->last_eat = ft_get_mstime();
	while (philo->info->someone_is_dead == false)
	{
		if (ft_isodd(philo->id))
			ph_take_fork(philo, left_fork_id);
		else
			ph_take_fork(philo, right_fork_id);
		if (ft_isodd(philo->id))
			ph_take_fork(philo, right_fork_id);
		else
			ph_take_fork(philo, left_fork_id);
		ph_eat(philo);
		ph_drop_forks(philo);
		ph_sleep(philo);
		ph_think(philo);
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
