/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:26:27 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 18:08:49 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include "t_info.h"
# include "t_time.h"

typedef struct s_philo
{
	int			id;
	bool		is_complete_eating;
	int64_t		eat_cnt;
	pthread_t	thread;
	t_time		last_eat;
	t_info		*info;
}	t_philo;

#endif
