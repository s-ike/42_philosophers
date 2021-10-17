/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:03:21 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/17 16:40:18 by sikeda           ###   ########.fr       */
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
}

#include <pthread.h>

static void
	*func(void *philo_p)
{
	t_philo *philo;

	philo = (t_philo *)philo_p;
	pthread_mutex_lock(&philo->info->cnt_lock);
	philo->info->cnt_finished++;
	if (philo->info->cnt_finished == philo->info->num_of_philo)
		philo->info->someone_is_dead = true;
	pthread_mutex_unlock(&philo->info->cnt_lock);
	return (NULL);
}
void
	ft_philo_eat(t_philo *philo)
{
	pthread_t	tid;

	ft_philo_do(philo, ST_EAT);
	philo->last_ate = ft_get_mstime();
	philo->eat_cnt++;
	if (philo->eat_cnt < 0)
		philo->eat_cnt = 0;
	if (philo->info->num_must_eat != NO_OPTION && philo->eat_cnt == philo->info->num_must_eat)
	{
		if (pthread_create(&tid, NULL, func, philo))
			return ;
		if (pthread_detach(tid))
			return ;
		// pthread_mutex_lock(&philo->info->cnt_lock);
		// philo->info->cnt_finished++;
		// if (philo->info->cnt_finished == philo->info->num_of_philo)
		// 	philo->info->someone_is_dead = true;
		// pthread_mutex_unlock(&philo->info->cnt_lock);
	}
	ft_usleep(philo->info->time_to_eat);
}
