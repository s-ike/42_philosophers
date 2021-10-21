/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:03:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/21 17:59:16 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_info.h"

static void
	set_args_to_info(t_info *info, int argc, const char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == OPTIONAL_ARGC)
		info->num_must_eat = ft_atoi(argv[5]);
	else
		info->num_must_eat = NO_OPTION;
}

static bool
	is_positive_nums(const t_info *info, int argc)
{
	if (!ft_ispositive(info->num_of_philo)
		|| !ft_ispositive(info->time_to_die)
		|| !ft_ispositive(info->time_to_eat)
		|| !ft_ispositive(info->time_to_sleep))
		return (false);
	if (argc == OPTIONAL_ARGC
		&& !ft_ispositive(info->num_must_eat))
		return (false);
	return (true);
}

static bool
	is_succeeded_alloc_philo_pid(t_info *info)
{
	info->philo_pid = (pid_t *)malloc(sizeof(pid_t) * info->num_of_philo);
	if (!info->philo_pid)
		return (false);
	return (true);
}

static bool
	is_succeeded_init_semaphore(t_info *info)
{
	info->forks_lock = sem_open(SEM_FORKS, O_CREAT, S_IRWXU, info->num_of_philo);
	if (info->print_lock == SEM_FAILED)
		return (false);
	info->print_lock = sem_open(SEM_PRINT, O_CREAT, S_IRWXU, 1);
	if (info->print_lock == SEM_FAILED)
	{
		sem_close(info->forks_lock);
		return (false);
	}
	return (true);
}

t_status
	ft_init_info(t_info *info, int argc, const char **argv)
{
	const bool	valid_args = ft_is_valid_arg_nums(argc, argv);

	if (!valid_args)
		return (FAILURE);
	memset(info, 0, sizeof(t_info));
	info->someone_is_dead = false;
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	set_args_to_info(info, argc, argv);
	if (is_positive_nums(info, argc)
		&& is_succeeded_alloc_philo_pid(info)
		&& is_succeeded_init_semaphore(info))
		return (SUCCESS);
	free(info->philo_pid);
	return (FAILURE);
}
