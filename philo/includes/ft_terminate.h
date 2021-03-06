/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:26:30 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 12:42:59 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINATE_H
# define FT_TERMINATE_H

# ifdef LEAKS
#  include <unistd.h>
#  include <stdio.h>
# endif
# include <stdlib.h>
# include "t_info.h"
# include "t_philo.h"

void	ft_terminate_info(t_info *info);
void	ft_terminate_philos(t_philo *philos);

#endif
