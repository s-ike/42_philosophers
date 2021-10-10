/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:26:27 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 09:27:28 by sikeda           ###   ########.fr       */
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
	t_info			*info;
	// enum e_status	status;
	// pthread_mutex_t	status_lock;
}	t_philo;

#endif
