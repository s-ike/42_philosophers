/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:56:42 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 11:03:11 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_START_PHILOS_H
# define FT_START_PHILOS_H

# include <unistd.h>
# include <stdlib.h>
# include "def_error.h"
# include "t_info.h"
# include "t_philo.h"
# include "t_status.h"
# include "ft_philo_routine.h"
# include "ft_puterror.h"
# include "ft_time.h"

t_status	ft_start_philos(t_info *info, t_philo *philos);

#endif
