/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:00:38 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 22:37:31 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_philos.h"

t_philo	*ft_init_philos(t_info *info)
{
	t_philo	*philos;
	int		id;
	int		i;

	if (info->num_of_philo == 0)
		return (NULL);
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		id = i + 1;
		philos[i].id = id;
		philos[i].right_fork_id = id - 1;
		philos[i].left_fork_id = id % info->num_of_philo;
		philos[i].has_right_fork = false;
		philos[i].has_left_fork = false;
		philos[i].finished = false;
		philos[i].eat_cnt = 0;
		philos[i].last_ate = 0;
		philos[i].info = info;
		i++;
	}
	return (philos);
}
