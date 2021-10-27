/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:40:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/27 16:49:01 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_start_philos.h"

static t_status
	terminate_routine(t_info *info)
{
	int			wait_status;
	t_status	status;
	int			i;

	waitpid(-1, &wait_status, 0);
	if (info->eatcnt_pid)
	{
		kill(info->eatcnt_pid, SIGTERM);
		info->eatcnt_pid = 0;
	}
	status = SUCCESS;
	i = -1;
	if (WIFEXITED(wait_status))
	{
		if (WEXITSTATUS(wait_status) == EXIT_FAILURE)
			status = FAILURE;
		while (++i < info->num_of_philo && info->philo_pid[i])
			kill(info->philo_pid[i], SIGTERM);
		return (status);
	}
	if (WIFSIGNALED(wait_status) && WTERMSIG(wait_status) == SIGTERM)
		return (status);
	while (++i < info->num_of_philo && info->philo_pid[i])
		kill(info->philo_pid[i], SIGTERM);
	return (status);
}

static t_status
	launch_eat_counter(t_info *info)
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid < 0)
		return (ft_puterror_and_return(ERR_FORK, FAILURE));
	else if (pid == 0)
	{
		i = -1;
		while (++i < info->num_of_philo)
			sem_wait(info->eatcnt_lock);
		exit(EXIT_SUCCESS);
	}
	info->eatcnt_pid = pid;
	return (SUCCESS);
}

static bool
	needs_terminate_routine(t_info *info, t_status fork_status)
{
	if ((fork_status == FAILURE || launch_eat_counter(info) == FAILURE)
		&& info->philo_pid[0])
	{
		kill(info->philo_pid[0], SIGKILL);
	}
	if (!info->philo_pid[0])
		return (false);
	return (true);
}

t_status
	ft_start_philos(t_info *info, t_philo *philo)
{
	pid_t		pid;
	t_status	fork_status;
	int			i;

	fork_status = SUCCESS;
	i = -1;
	philo->start_time = ft_get_mstime();
	while (fork_status == SUCCESS && ++i < info->num_of_philo)
	{
		pid = fork();
		if (pid < 0)
			fork_status = ft_puterror_and_return(ERR_FORK, FAILURE);
		else if (pid == 0)
		{
			philo->id = i + 1;
			ft_philo_routine(info, philo);
		}
		else
			info->philo_pid[i] = pid;
	}
	if (!needs_terminate_routine(info, fork_status))
		return (FAILURE);
	return (terminate_routine(info));
}
