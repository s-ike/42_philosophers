/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:44 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 10:51:39 by sikeda           ###   ########.fr       */
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
# include "terminate.h"
# include "utils.h"
# include "t_info.h"
# include "t_philo.h"

enum e_philo_status
{
	ST_EAT,
	ST_SLEEP,
	ST_THINK,
	ST_DIE,
	ST_END
};

#endif