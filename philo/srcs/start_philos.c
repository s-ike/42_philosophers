/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:05:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 11:34:19 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_philos.h"

void
	print(t_philo *philo, enum e_philo_status status)
{
	char	*msg;

	msg = "is died";
	if (status == ST_EAT)
		msg = "is eating";
	else if (status == ST_SLEEP)
		msg = "is sleeping";
	else if (status == ST_THINK)
		msg = "is thinking";
	printf("%llu %d %s\n", get_mstime(), philo->id, msg);
}

// static bool
// 	ft_usleep(int time)
// {
// 	long long	crnt_tstamp;
// 	long long	end_tstamp;

// 	crnt_tstamp = get_microtime();
// 	if (crnt_tstamp == -1)
// 		return (false);
// 	end_tstamp = crnt_tstamp + time * 1000LL;
// 	while (crnt_tstamp < end_tstamp)
// 	{
// 		usleep(200);
// 		crnt_tstamp = get_microtime();
// 		if (crnt_tstamp == -1)
// 			return (false);
// 	}
// 	return (true);
// }

static bool
	ft_usleep(int time)
{
	long long	crnt_tstamp;
	long long	end_tstamp;

	crnt_tstamp = get_mstime();
	if (crnt_tstamp == -1)
		return (false);
	end_tstamp = crnt_tstamp + time;
	while (crnt_tstamp < end_tstamp)
	{
		usleep(500);
		crnt_tstamp = get_mstime();
		if (crnt_tstamp == -1)
			return (false);
	}
	return (true);
}

static void
	ph_do(t_philo *philo, enum e_philo_status status)
{
	pthread_mutex_lock(&philo->info->print_lock);
	print(philo, status);
	pthread_mutex_unlock(&philo->info->print_lock);
	if (status == ST_EAT)
		ft_usleep(philo->info->time_to_eat);
	else if (status == ST_SLEEP)
		ft_usleep(philo->info->time_to_sleep);
}

void
	ph_eat(t_philo *philo)
{
	ph_do(philo, ST_EAT);
}

void
	ph_sleep(t_philo *philo)
{
	ph_do(philo, ST_SLEEP);
}

void
	ph_think(t_philo *philo)
{
	ph_do(philo, ST_THINK);
}

void
	ph_died(t_philo *philo)
{
	if (philo->id == 5)
		philo->is_dead = true;
	if (philo->is_dead)
		ph_do(philo, ST_DIE);
}
# include <sys/time.h>
void
	*philo(void *philo_p)
{
	t_philo			*philo;
	struct timeval	time;

	philo = philo_p;
	gettimeofday(&time, NULL);
	printf("%d %d comming! num of philo: %d\n",
		(int)time.tv_usec, philo->id, philo->info->num_of_philo);
	while (philo->is_dead == false)
	{
		pthread_mutex_lock(&philo->info->fork_lock[philo->id - 1]);
		pthread_mutex_lock(&philo->info->fork_lock[philo->id % philo->info->num_of_philo]);
		ph_eat(philo);
		pthread_mutex_unlock(&philo->info->fork_lock[philo->id - 1]);
		pthread_mutex_unlock(&philo->info->fork_lock[philo->id % philo->info->num_of_philo]);

		ph_sleep(philo);
		ph_think(philo);
		ph_died(philo);
	}
	if (philo->is_dead)
		printf("%d dead", philo->id);
	return (NULL);
}

t_status
	start_philos(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].is_dead = false;
		philos[i].info = info;
		if (pthread_create(&philos[i].thread, NULL, philo, (void *)&philos[i]))
			return (FAILURE);
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (FAILURE);
	}
	return (SUCCESS);
}
