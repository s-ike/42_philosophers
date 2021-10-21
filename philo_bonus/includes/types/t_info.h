/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_info.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:47 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/21 17:45:09 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INFO_H
# define T_INFO_H

# include <stdbool.h>
# include <semaphore.h>
# include "def_philo.h"

typedef struct s_info
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_must_eat;
	int		cnt_finished;
	bool	someone_is_dead;
	pid_t	*philo_pid;
	sem_t	*forks_lock;
	sem_t	*print_lock;
}	t_info;

#endif
