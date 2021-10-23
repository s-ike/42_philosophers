/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:40:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 14:29:43 by sikeda           ###   ########.fr       */
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
			while (++i < info->num_of_philo)
				waitpid(-1, &wait_status, 0);
		return (status);
	}
	while (++i < info->num_of_philo)
		kill(info->philo_pid[i], SIGTERM);
	return (status);
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
			return (FAILURE);
		else if (pid == 0)
		{
			philo->id = i + 1;
			ft_philo_routine(info, philo);
		}
		info->philo_pid[i] = pid;
	}
	return (terminate_routine(info));
}
