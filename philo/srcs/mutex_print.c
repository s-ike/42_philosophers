/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:19:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 16:17:23 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex_print.h"

static void
	print(t_philo *philo, t_philo_status status, t_time time)
{
	static t_time	start = 0;
	char			*msg;

	msg = COLOR_RED"is died"COLOR_RESET;
	if (status == ST_EAT)
		msg = COLOR_GREEN"is eating"COLOR_RESET;
	else if (status == ST_SLEEP)
		msg = COLOR_BLUE"is sleeping"COLOR_RESET;
	else if (status == ST_THINK)
		msg = COLOR_YELLOW"is thinking"COLOR_RESET;
	if (start == 0)
		start = ft_get_mstime();
	printf("%llu %d %s\n", time - start, philo->id, msg);
}

void
	ft_mutex_print(t_philo *philo, t_philo_status status, t_time time)
{
	pthread_mutex_lock(&philo->info->print_lock);
	print(philo, status, time);
	pthread_mutex_unlock(&philo->info->print_lock);
}
