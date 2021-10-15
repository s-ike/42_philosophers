/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:03:21 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/15 13:03:21 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_routine.h"

bool
	ft_check_if_dead(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->time_to_die <= crnt_time - philo->last_ate)
		return (true);
	return (false);
}

void
	ft_philo_do(t_philo *philo, t_philo_status status)
{
	if (status != ST_DIE && ft_check_if_dead(philo))
		return ;
	ft_mutex_print(philo, status);
	if (status == ST_EAT)
		ft_usleep(philo->info->time_to_eat);
	else if (status == ST_SLEEP)
		ft_usleep(philo->info->time_to_sleep);
}
