/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:26:27 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 11:59:19 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include <stdbool.h>
# include "t_info.h"

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	bool			is_dead;
	long long		last_eat;
	t_info			*info;
	// enum e_status	status;
	// pthread_mutex_t	status_lock;
}	t_philo;

#endif
