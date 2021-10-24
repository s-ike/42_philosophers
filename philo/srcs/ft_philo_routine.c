/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:18:29 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 11:19:54 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_routine.h"

void
	ft_philo_die(t_philo *philo)
{
	if (!philo->info->someone_is_dead || !philo->finished)
		ft_philo_do(philo, ST_DIE);
}

static void
	philo_take_fork(t_philo *philo, int right_or_left)
{
	const int	right_fork = philo->right_fork_id;
	const int	left_fork = philo->left_fork_id;

	if (right_or_left == RIGHT)
	{
		pthread_mutex_lock(&philo->info->fork_lock[right_fork]);
		philo->has_right_fork = true;
	}
	else
	{
		pthread_mutex_lock(&philo->info->fork_lock[left_fork]);
		philo->has_left_fork = true;
	}
	ft_philo_do(philo, ST_FORK);
}

static void
	philo_drop_forks(t_philo *philo)
{
	if (philo->has_right_fork)
		pthread_mutex_unlock(&philo->info->fork_lock[philo->right_fork_id]);
	if (philo->has_left_fork)
		pthread_mutex_unlock(&philo->info->fork_lock[philo->left_fork_id]);
	philo->has_right_fork = false;
	philo->has_left_fork = false;
}

static void
	philo_action(t_philo *philo, t_philo_status status)
{
	if (status == ST_FORK)
		philo_take_fork(philo, LEFT);
	else if (status == ST_EAT)
	{
		ft_philo_do(philo, ST_EAT);
		philo->last_ate = ft_get_mstime();
		ft_usleep(philo->info->time_to_eat);
		philo_drop_forks(philo);
		philo->eat_cnt++;
		if (philo->eat_cnt < 0)
			philo->eat_cnt = 0;
		if (philo->eat_cnt == philo->info->num_must_eat
			&& philo->info->num_must_eat != NO_OPTION)
		{
			philo->finished = true;
		}
	}
	else if (status == ST_SLEEP)
	{
		ft_philo_do(philo, status);
		ft_usleep(philo->info->time_to_sleep);
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
	if (philo->info->someone_is_dead || philo->finished)
		return ;
	philo_take_fork(philo, RIGHT);
	if (philo->left_fork_id == philo->right_fork_id)
		while (!philo->info->someone_is_dead)
			ft_usleep(500);
	status = ST_FORK;
	while (!philo->info->someone_is_dead && !philo->finished
		&& status <= ST_THINK)
	{
		philo_action(philo, status);
		status++;
	}
	philo_drop_forks(philo);
}
