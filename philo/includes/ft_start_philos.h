/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:56:42 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 12:42:52 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_START_PHILOS_H
# define FT_START_PHILOS_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_mutex_print.h"
# include "ft_time.h"
# include "ft_utils.h"
# include "t_info.h"
# include "t_philo_status.h"
# include "t_philo.h"
# include "t_status.h"

t_status	ft_start_philos(t_info *info, t_philo *philos);

#endif
