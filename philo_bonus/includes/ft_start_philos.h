/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:02:14 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/21 16:42:17 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_START_PHILOS
# define FT_START_PHILOS

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <semaphore.h>
# include <stdio.h>
# include "def_color.h"
# include "t_info.h"
# include "t_philo.h"
# include "t_status.h"
# include "ft_time.h"

t_status	ft_start_philos(t_info *info, t_philo *philo);

#endif
