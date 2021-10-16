/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:26:27 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/16 09:52:11 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include <stdint.h>
# include "t_info.h"
# include "t_time.h"

typedef struct s_philo
{
	int			id;
	int			right_fork_id;
	int			left_fork_id;
	int64_t		eat_cnt;
	pthread_t	thread;
	t_time		last_ate;
	t_info		*info;
}	t_philo;

#endif
