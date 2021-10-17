/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_print.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:48:24 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/17 15:59:35 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUTEX_PRINT_H
# define FT_MUTEX_PRINT_H

// # include <stdio.h>
# include "ft_time.h"
# include "def_color.h"
# include "t_philo_status.h"
# include "t_philo.h"
# include "ft_utils.h"

void	ft_mutex_print(t_philo *philo, t_philo_status status);

#endif