/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:44 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/09 16:03:41 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIOL_H
# define PHIOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "init_info.h"
# include "philo_def.h"
# include "utils.h"
# include "t_status.h"
# include "t_info.h"

enum e_philo_status
{
	ST_EAT,
	ST_SLEEP,
	ST_THINK,
	ST_DIE,
	ST_END
};

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	bool			is_dead;
	t_info			*info;
	// enum e_status	status;
	// pthread_mutex_t	status_lock;
}	t_philo;

/* terminate.c */
int		ft_terminate(t_info *info, t_philo *philos, bool should_destroy, int ret);

#endif