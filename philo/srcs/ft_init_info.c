/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:03:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 10:53:07 by sikeda           ###   ########.fr       */
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
	is_succeeded_init_fork_locks(t_info *info)
{
	info->fork_lock = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->fork_lock)
		return (false);
	return (true);
}

static bool
	is_succeeded_init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->print_lock, NULL))
		return (false);
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->fork_lock[i], NULL))
		{
			pthread_mutex_destroy(&info->print_lock);
			while (0 <= i)
				pthread_mutex_destroy(&info->fork_lock[i--]);
			return (false);
		}
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
	set_args_to_info(info, argc, argv);
	if (!is_positive_nums(info, argc))
		return (ft_puterror_and_return(ERR_INVAL, FAILURE));
	else if (!is_succeeded_init_fork_locks(info))
		return (ft_puterror_and_return(ERR_MALLOC, FAILURE));
	else if (!is_succeeded_init_mutex(info))
	{
		ft_puterror(ERR_MUTEX_INIT);
		free(info->fork_lock);
		return (FAILURE);
	}
	return (SUCCESS);
}
