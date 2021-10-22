/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:02:14 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/22 11:40:09 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_START_PHILOS_H
# define FT_START_PHILOS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdio.h>
# include "t_info.h"
# include "t_philo.h"
# include "t_status.h"
# include "ft_sem_print.h"
# include "ft_time.h"

t_status	ft_start_philos(t_info *info, t_philo *philo);

#endif
