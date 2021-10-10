/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:48:24 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 15:29:03 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_PRINT_H
# define MUTEX_PRINT_H

# include <stdio.h>
# include "time.h"
# include "def_color.h"
# include "t_philo_status.h"
# include "t_philo.h"

void	ft_mutex_print(t_philo *philo, t_philo_status status);

#endif