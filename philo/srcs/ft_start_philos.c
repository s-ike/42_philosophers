/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/14 22:14:06 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_start_philos.h"

bool
	check_if_dead(t_philo *philo, t_time crnt_time)
{
	if (philo->info->time_to_die <= crnt_time - philo->last_ate)
		return (true);
	return (false);
}

static void
	ph_do(t_philo *philo, t_philo_status status)
{
	const t_time	crnt_time = ft_get_mstime();

	if (status != ST_DIE && check_if_dead(philo, crnt_time))
		return ;
	ft_mutex_print(philo, status);
	if (status == ST_EAT)
		ft_usleep(philo->info->time_to_eat);
	else if (status == ST_SLEEP)
		ft_usleep(philo->info->time_to_sleep);
}

void
	ph_died(t_philo *philo)
{
	if (philo->info->someone_is_dead == false)
		ph_do(philo, ST_DIE);
}

void
	ph_take_fork(t_philo *philo, int fork_id)
{
	if (philo->info->someone_is_dead)
		return ;
	pthread_mutex_lock(&philo->info->fork_lock[fork_id]);
	ph_do(philo, ST_FORK);
}

void
	ph_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork_lock[philo->right_fork_id]);
	pthread_mutex_unlock(&philo->info->fork_lock[philo->left_fork_id]);
}

void
	ph_eat(t_philo *philo)
{
	if (philo->info->someone_is_dead)
		return ;
	ph_do(philo, ST_EAT);
	// TODO: lockの位置
	philo->last_ate = ft_get_mstime();
	philo->eat_cnt++;
	if (philo->eat_cnt < 0)
		philo->eat_cnt = 0;
	if (philo->eat_cnt == philo->info->num_must_eat)
	{
		pthread_mutex_lock(&philo->info->cnt_lock);
		philo->info->cnt_finished++;
		if (philo->info->cnt_finished == philo->info->num_of_philo)
			philo->info->someone_is_dead = true;
		pthread_mutex_unlock(&philo->info->cnt_lock);
	}
}

void
	ph_sleep(t_philo *philo)
{
	if (philo->info->someone_is_dead)
		return ;
	ph_do(philo, ST_SLEEP);
}

void
	ph_think(t_philo *philo)
{
	if (philo->info->someone_is_dead)
		return ;
	ph_do(philo, ST_THINK);
}

void
	*ft_monitor(void *philo_p)
{
	t_philo	*philo;
	t_time	crnt_time;

	philo = (t_philo *)philo_p;
	usleep(500);
	while (true)
	{
		crnt_time = ft_get_mstime();
		if (philo->info->someone_is_dead)
			return (NULL);
		if (check_if_dead(philo, crnt_time))
		{
			ph_died(philo);
			return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}

void
	*philo(void *philo_p)
{
	t_philo		*philo;
	pthread_t	monitor;

	philo = (t_philo *)philo_p;
	if (pthread_create(&monitor, NULL, ft_monitor, philo))
		return (NULL);
	if (pthread_detach(monitor))
		return (NULL);
	while (philo->info->someone_is_dead == false)
	{
		if (ft_iseven(philo->id))
			usleep(200);
		ph_take_fork(philo, philo->right_fork_id);
		if (philo->left_fork_id == philo->right_fork_id)
			ph_died(philo);
		else
		{
			ph_take_fork(philo, philo->left_fork_id);
			ph_eat(philo);
			ph_drop_forks(philo);
			ph_sleep(philo);
			ph_think(philo);
		}
	}
	return (NULL);
}

t_status
	ft_start_philos(t_info *info, t_philo *philos)
{
	t_time		crnt_time;
	int			i;

	i = -1;
	crnt_time = ft_get_mstime();
	while (++i < info->num_of_philo)
	{
		philos[i].last_ate = crnt_time;
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
