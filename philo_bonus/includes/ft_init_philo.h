/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 13:52:23 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_PHILO_H
# define FT_INIT_PHILO_H

# include <stdlib.h>
# include <string.h>
# include "def_error.h"
# include "t_info.h"
# include "t_philo.h"
# include "t_status.h"
# include "ft_puterror.h"

t_status	ft_init_philo(t_info *info, t_philo *philo);

#endif
