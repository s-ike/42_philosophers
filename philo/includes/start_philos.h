/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:56:42 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 12:03:35 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_PHILOS_H
# define START_PHILOS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "time.h"
# include "t_info.h"
# include "t_philo.h"
# include "t_status.h"

enum e_philo_status
{
	ST_EAT,
	ST_SLEEP,
	ST_THINK,
	ST_DIE,
	ST_END
};

t_status	ft_start_philos(t_info *info, t_philo *philos);

#endif
