/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:03:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/11 22:21:30 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_info.h"

static bool
	is_valid_arg_nums(int argc, const char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumeric(argv[i])
			|| ft_isover_intrange(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

static void
	set_args_to_info(t_info *info, int argc, const char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == OPTIONAL_ARGC)
		info->num_must_eat = ft_atoi(argv[5]);
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

t_info
	*ft_init_info(int argc, const char **argv)
{
	const bool	valid_args = is_valid_arg_nums(argc, argv);
	t_info		*info;

	if (!valid_args)
		return (NULL);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	memset(info, 0, sizeof(t_info));
	info->someone_is_dead = false;
	set_args_to_info(info, argc, argv);
	if (is_succeeded_init_fork_locks(info)
		&& is_succeeded_init_mutex(info))
		return (info);
	free(info);
	return (NULL);
}
