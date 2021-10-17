/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:55:22 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/17 15:13:38 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_ROUTINE_H
# define FT_PHILO_ROUTINE_H

# include <stdbool.h>
# include "t_philo_status.h"
# include "t_philo.h"
# include "t_time.h"
# include "ft_mutex_print.h"
# include "ft_time.h"
# include "ft_utils.h"

# define RIGHT 0
# define LEFT 1

/* ft_philo_routin2.c */
bool	ft_check_if_dead(t_philo *philo);
void	ft_philo_do(t_philo *philo, t_philo_status status);
void	ft_philo_eat(t_philo *philo);
/* ft_philo_routin.c */
void	ft_philo_die(t_philo *philo);
void	ft_philo_routine(t_philo *philo);

#endif