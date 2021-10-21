/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:00:38 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/21 18:57:22 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_philo.h"

t_status	ft_init_philo(t_info *info, t_philo *philo)
{
	if (info->num_of_philo == 0)
		return (FAILURE);
	memset(philo, 0, sizeof(t_philo));
	philo->info = info;
	return (SUCCESS);
}
