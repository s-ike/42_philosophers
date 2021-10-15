/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:18:29 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/15 13:01:59 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_routine.h"

void
	ft_philo_die(t_philo *philo)
{
	if (philo->info->someone_is_dead == false)
		ft_philo_do(philo, ST_DIE);
}

static void
	philo_take_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->info->fork_lock[fork_id]);
	ft_philo_do(philo, ST_FORK);
}

static void
	philo_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork_lock[philo->right_fork_id]);
	pthread_mutex_unlock(&philo->info->fork_lock[philo->left_fork_id]);
}

static void
	philo_action(t_philo *philo, t_philo_status status)
{
	if (philo->info->someone_is_dead)
		return ;
	if (status == ST_FORK)
		philo_take_fork(philo, philo->left_fork_id);
	else if (status == ST_EAT)
	{
		ft_philo_do(philo, ST_EAT);
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
		philo_drop_forks(philo);
	}
	else
		ft_philo_do(philo, status);
}

void
	ft_philo_routine(t_philo *philo)
{
	t_philo_status	status;

	if (ft_iseven(philo->id))
		usleep(200);
	if (philo->info->someone_is_dead)
		return ;
	philo_take_fork(philo, philo->right_fork_id);
	if (philo->left_fork_id == philo->right_fork_id)
		ft_philo_die(philo);
	else
	{
		status = ST_FORK;
		while (status <= ST_THINK)
		{
			philo_action(philo, status);
			status++;
		}
	}
}
