/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:17:56 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/23 12:12:41 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "def_error.h"
#include "def_philo.h"
#include "t_info.h"
#include "t_philo.h"
#include "t_status.h"
#include "ft_init_info.h"
#include "ft_init_philo.h"
#include "ft_puterror.h"
#include "ft_start_philos.h"
#include "ft_terminate.h"

int
	main(int argc, char **argv)
{
	t_info		info;
	t_philo		philo;
	t_status	successed;

	if (argc != REQUIRED_ARGC && argc != OPTIONAL_ARGC)
		exit(ft_puterror_and_return(ERR_INVAL, EXIT_FAILURE));
	if (ft_init_info(&info, argc, (const char **)argv) == FAILURE)
		exit(EXIT_FAILURE);
	if (ft_init_philo(&info, &philo) == FAILURE)
	{
		ft_terminate_info(&info);
		exit(EXIT_FAILURE);
	}
	successed = ft_start_philos(&info, &philo);
	ft_terminate_info(&info);
	if (successed == SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
