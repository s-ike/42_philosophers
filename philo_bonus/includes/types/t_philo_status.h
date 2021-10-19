/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo_status.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:47:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 23:08:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_STATUS_H
# define T_PHILO_STATUS_H

typedef enum e_philo_status
{
	ST_FORK,
	ST_EAT,
	ST_SLEEP,
	ST_THINK,
	ST_DIE,
	ST_END
}	t_philo_status;

#endif
