/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:06:21 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 15:08:37 by sikeda           ###   ########.fr       */
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
	sem_close(info->forks_lock);
	sem_close(info->print_lock);
	sem_close(info->eatcnt_lock);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_EATCNT);
	free(info->philo_pid);
}
