/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:40:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 10:42:33 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_start_philos.h"

bool
	ft_check_if_dead(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->time_to_die <= crnt_time - philo->last_ate)
		return (true);
	return (false);
}

void
	philo_do(t_philo *philo, t_philo_status status)
{
	if (philo->finished)
		return ;
	if (status != ST_DIE && ft_check_if_dead(philo))
		return ;
	ft_sem_print(philo, status);
}

void
	ft_philo_eat(t_philo *philo)
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

void
	*monitor(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	usleep(500);
	while (true)
	{
		if (philo->finished)
			return (NULL);
		if (ft_check_if_dead(philo))
		{
			philo_do(philo, ST_DIE);
			return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}

static void
	philo_routine(t_info *info, t_philo *philo)
{
	pthread_t	monitor_tid;

	if (pthread_create(&monitor_tid, NULL, monitor, philo))
		exit(EXIT_FAILURE);	// TODO:
	if (pthread_detach(monitor_tid))
		exit(EXIT_FAILURE);	// TODO:
	philo->last_ate = ft_get_mstime();
	while (philo->finished == false)
	{
		sem_wait(info->forks_lock);
		philo_do(philo, ST_FORK);
		if (info->num_of_philo == 1)
			exit(EXIT_SUCCESS);
		sem_wait(info->forks_lock);
		philo_do(philo, ST_FORK);
		ft_philo_eat(philo);
		sem_post(info->forks_lock);
		sem_post(info->forks_lock);
		philo_do(philo, ST_SLEEP);
		ft_usleep(info->time_to_sleep);
		philo_do(philo, ST_THINK);
	}
	exit(EXIT_SUCCESS);
}

t_status
	ft_start_philos(t_info *info, t_philo *philo)
{
	pid_t		pid;
	int			wait_status;
	t_status	status;
	int			i;

	i = -1;
	philo->start_time = ft_get_mstime();
	while (++i < info->num_of_philo)
	{
		pid = fork();
		if (pid < 0)
			return (FAILURE);
		else if (pid == 0)
		{
			philo->id = i + 1;
			philo_routine(info, philo);
		}
		info->philo_pid[i] = pid;
	}
	waitpid(-1, &wait_status, 0);
	status = SUCCESS;
	i = 0;
	if (WIFEXITED(wait_status))
	{
		if (WEXITSTATUS(wait_status) == EXIT_FAILURE
			|| WEXITSTATUS(wait_status) == EXIT_SOMEONE_IS_DEAD)
		{
			if (WEXITSTATUS(wait_status) == EXIT_FAILURE)
				status = FAILURE;
			while (++i < info->num_of_philo)
				kill(info->philo_pid[i], SIGTERM);
		}
		else
		{
			while (++i < info->num_of_philo)
				waitpid(-1, &wait_status, 0);
		}
	}
	else
		while (++i < info->num_of_philo)
			kill(info->philo_pid[i], SIGTERM);
	return (status);
}
