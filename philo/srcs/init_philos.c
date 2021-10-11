/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:00:38 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/11 22:21:03 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_philos.h"

t_philo	*ft_init_philos(t_info *info)
{
	t_philo	*philos;
	int		i;

	if (info->num_of_philo == 0)
		return (NULL);
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < info->num_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].last_eat = 0;
		philos[i].info = info;
		i++;
	}
	return (philos);
}
