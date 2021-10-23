/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:30:43 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 19:00:06 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_ROUTINE_H
# define FT_PHILO_ROUTINE_H

# include <stdlib.h>
# include <pthread.h>
# include "def_error.h"
# include "t_info.h"
# include "t_philo.h"
# include "ft_puterror.h"
# include "ft_sem_print.h"

void	ft_philo_routine(t_info *info, t_philo *philo);

#endif
