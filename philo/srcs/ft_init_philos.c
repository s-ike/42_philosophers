/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:00:38 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 12:40:47 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_philos.h"

static void
	set_first_value(t_info *info, t_philo *philo, int id)
{
	philo->id = id;
	philo->right_fork_id = id - 1;
	philo->left_fork_id = id % info->num_of_philo;
	philo->has_right_fork = false;
	philo->has_left_fork = false;
	philo->finished = false;
	philo->eat_cnt = 0;
	philo->last_ate = 0;
	philo->info = info;
}

t_philo	*ft_init_philos(t_info *info)
{
	t_philo	*philos;
	int		i;

	if (info->num_of_philo == 0)
		return (ft_puterror_and_nullreturn(ERR_INVAL));
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philos)
		return (ft_puterror_and_nullreturn(ERR_MALLOC));
	i = 0;
	while (i < info->num_of_philo)
	{
		set_first_value(info, &philos[i], i + 1);
		i++;
	}
	return (philos);
}
