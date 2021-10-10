/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:56:42 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 14:53:00 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_PHILOS_H
# define START_PHILOS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "mutex_print.h"
# include "time.h"
# include "t_info.h"
# include "t_philo_status.h"
# include "t_philo.h"
# include "t_status.h"

t_status	ft_start_philos(t_info *info, t_philo *philos);

#endif
