/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:54:55 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 15:34:43 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "def_philo.h"
#include "t_info.h"
#include "t_philo.h"
#include "t_status.h"
#include "init_info.h"
#include "init_philos.h"
#include "start_philos.h"
#include "terminate.h"

int
	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philos;
	t_status	successed;

	if (argc != REQUIRED_ARGC && argc != OPTIONAL_ARGC)
		return (EXIT_FAILURE);
	info = ft_init_info(argc, (const char **)argv);
	if (!info)
		return (EXIT_FAILURE);
	philos = ft_init_philos(info);
	if (!philos)
	{
		ft_terminate_info(info);
		return (EXIT_FAILURE);
	}
	successed = ft_start_philos(info, philos);
	ft_terminate_info(info);
	ft_terminate_philos(philos);
	if (successed == SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
