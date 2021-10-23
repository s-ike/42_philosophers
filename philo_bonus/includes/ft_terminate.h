/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:26:30 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 21:39:04 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINATE_H
# define FT_TERMINATE_H

# ifdef LEAKS
#  include <unistd.h>
#  include <stdio.h>
# endif
# include <stdlib.h>
# include "def_philo.h"
# include "t_info.h"

void	ft_terminate_info(t_info *info);

#endif
