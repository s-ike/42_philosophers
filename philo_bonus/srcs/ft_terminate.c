/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:06:21 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/19 09:56:51 by sikeda           ###   ########.fr       */
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

void
	ft_terminate_info(t_info *info)
{
	free(info->philo_pid);
}

void
	ft_terminate_philos(t_philo *philos)
{
	free(philos);
}
