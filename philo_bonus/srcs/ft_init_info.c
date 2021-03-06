/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:03:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/27 13:00:00 by sikeda           ###   ########.fr       */
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
	memset(info->philo_pid, 0, sizeof(pid_t) * info->num_of_philo);
	return (true);
}

static bool
	is_succeeded_init_semaphore(t_info *info)
{
	info->forks_lock = sem_open(
			SEM_FORKS, O_CREAT, S_IRWXU, info->num_of_philo);
	if (info->forks_lock == SEM_FAILED)
		return (false);
	info->print_lock = sem_open(SEM_PRINT, O_CREAT, S_IRWXU, 1);
	if (info->print_lock == SEM_FAILED)
	{
		sem_close(info->forks_lock);
		return (false);
	}
	info->eatcnt_lock = sem_open(SEM_EATCNT, O_CREAT, S_IRWXU, 0);
	if (info->eatcnt_lock == SEM_FAILED)
	{
		sem_close(info->forks_lock);
		sem_close(info->print_lock);
		return (false);
	}
	return (true);
}

t_status
	ft_init_info(t_info *info, int argc, const char **argv)
{
	const bool	valid_args = ft_is_valid_arg_nums(argc, argv);

	if (!valid_args)
		return (ft_puterror_and_return(ERR_INVAL, FAILURE));
	memset(info, 0, sizeof(t_info));
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_EATCNT);
	set_args_to_info(info, argc, argv);
	if (!is_positive_nums(info, argc))
		return (ft_puterror_and_return(ERR_INVAL, FAILURE));
	else if (!is_succeeded_alloc_philo_pid(info))
		return (ft_puterror_and_return(ERR_MALLOC, FAILURE));
	else if (!is_succeeded_init_semaphore(info))
	{
		ft_puterror(ERR_SEMAPHORE);
		free(info->philo_pid);
		return (FAILURE);
	}
	return (SUCCESS);
}
