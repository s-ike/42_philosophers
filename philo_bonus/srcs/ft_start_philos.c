/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:40:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 18:47:16 by sikeda           ###   ########.fr       */
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
		while (++i < info->num_of_philo)
			kill(info->philo_pid[i], SIGTERM);
		return (status);
	}
	if (WIFSIGNALED(wait_status) && WTERMSIG(wait_status) == SIGTERM)
		return (status);
	while (++i < info->num_of_philo)
		kill(info->philo_pid[i], SIGTERM);
	return (status);
}

t_status
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

t_status
	ft_start_philos(t_info *info, t_philo *philo)
{
	pid_t	pid;
	int		i;

	i = -1;
	philo->start_time = ft_get_mstime();
	while (++i < info->num_of_philo)
	{
		pid = fork();
		if (pid < 0)
			return (ft_puterror_and_return(ERR_FORK, FAILURE));
		else if (pid == 0)
		{
			philo->id = i + 1;
			ft_philo_routine(info, philo);
		}
		info->philo_pid[i] = pid;
	}
	if (launch_eat_counter(info) == FAILURE)
		kill(info->philo_pid[0], SIGKILL);
	return (terminate_routine(info));
}
