/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/13 13:04:44 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_start_philos.h"

bool
	check_if_dead(t_philo *philo, t_time crnt_time)
{
	if (philo->info->time_to_die <= crnt_time - philo->last_eat)
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
	pthread_mutex_unlock(&philo->info->fork_lock[philo->right_fork_id]);
	pthread_mutex_unlock(&philo->info->fork_lock[philo->left_fork_id]);
}

void
	ph_eat(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->someone_is_dead)
		return ;
	philo->last_eat = crnt_time;
	ph_do(philo, ST_EAT, philo->last_eat);
	philo->eat_cnt++;
	if (philo->info->num_must_eat != NO_OPTION
		&& philo->is_complete_eating == false
		&& philo->info->num_must_eat <= philo->eat_cnt)
		philo->is_complete_eating = true;
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
	usleep(500);
	while (true)
	{
		crnt_time = ft_get_mstime();
		if (philo->info->someone_is_dead)
			return (NULL);
		if (check_if_dead(philo, crnt_time))
		{
			ph_died(philo, crnt_time);
			return (NULL);
		}
		// TODO: 検証
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
	if (pthread_create(&monitor, NULL, ft_monitor, philo_p))
		return (NULL);
	if (pthread_detach(monitor))
		return (NULL);
	// 人数が多い時値が入っていない場合があった
	// philo->last_eat = ft_get_mstime();
	while (philo->info->someone_is_dead == false)
	{
		if (ft_iseven(philo->id))
			usleep(200);
		ph_take_fork(philo, philo->right_fork_id);
		if (philo->left_fork_id == philo->right_fork_id)
			ph_died(philo, philo->last_eat);
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

void
	*cnt_monitor(void *philos_p)
{
	t_philo	*philos;
	bool	end_flg;
	int		i;

	philos = philos_p;
	end_flg = false;
	usleep(500);
	while (!end_flg)
	{
		end_flg = true;
		i = -1;
		while (++i < (*philos).info->num_of_philo)
		{
			if (!philos[i].is_complete_eating)
			{
				end_flg = false;
				break ;
			}
		}
	}
	(*philos).info->someone_is_dead = true;
	return (NULL);
}

t_status
	ft_start_philos(t_info *info, t_philo *philos)
{
	pthread_t	cnt_monitor_id;
	t_time		crnt_time;
	int			i;

	if (info->num_must_eat != NO_OPTION)
	{
		if (pthread_create(&cnt_monitor_id, NULL, cnt_monitor, (void *)philos))
			return (FAILURE);
		if (pthread_detach(cnt_monitor_id))
			return (FAILURE);
	}
	i = -1;
	crnt_time = ft_get_mstime();
	while (++i < info->num_of_philo)
	{
		philos[i].last_eat = crnt_time;
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
