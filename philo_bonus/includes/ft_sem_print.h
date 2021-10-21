/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:57:28 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/21 18:04:53 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEM_PRINT_H
# define FT_SEM_PRINT_H

# include <stdio.h>
# include <semaphore.h>
# include "def_color.h"
# include "t_philo_status.h"
# include "t_philo.h"
# include "ft_time.h"

void	ft_sem_print(t_philo *philo, t_philo_status status);

#endif
