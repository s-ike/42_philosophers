/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:06:21 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 16:38:33 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminate.h"

#ifdef LEAKS

void
	destructor(void)__attribute__((destructor));

void
	destructor(void)
{
	char	buf[20];

	snprintf(buf, 20, "leaks %d", getpid());
	system(buf);
}
#endif

static void
	destroy_all_info_mutex(t_info *info)
{
	int	i;

	pthread_mutex_destroy(&info->print_lock);
	pthread_mutex_destroy(&info->cnt_lock);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->fork_lock[i]);
}

void
	ft_terminate_info(t_info *info)
{
	destroy_all_info_mutex(info);
	free(info->fork_lock);
}

void
	ft_terminate_philos(t_philo *philos)
{
	free(philos);
}
