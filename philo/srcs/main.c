/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:54:55 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 10:45:58 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "def_error.h"
#include "def_philo.h"
#include "t_info.h"
#include "t_philo.h"
#include "t_status.h"
#include "ft_init_info.h"
#include "ft_init_philos.h"
#include "ft_puterror.h"
#include "ft_start_philos.h"
#include "ft_terminate.h"

int
	main(int argc, char **argv)
{
	t_info		info;
	t_philo		*philos;
	t_status	successed;

	if (argc != REQUIRED_ARGC && argc != OPTIONAL_ARGC)
		return (ft_puterror_and_return(ERR_INVAL, EXIT_FAILURE));
	if (ft_init_info(&info, argc, (const char **)argv) == FAILURE)
		return (EXIT_FAILURE);
	philos = ft_init_philos(&info);
	if (!philos)
	{
		ft_terminate_info(&info);
		return (EXIT_FAILURE);
	}
	successed = ft_start_philos(&info, philos);
	ft_terminate_info(&info);
	ft_terminate_philos(philos);
	if (successed == SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
