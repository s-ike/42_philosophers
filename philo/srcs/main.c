/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:54:55 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 11:31:43 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philos;
	t_status	successed;

	if (argc != REQUIRED_ARGC && argc != OPTIONAL_ARGC)
		return (EXIT_FAILURE);
	info = init_info(argc, (const char **)argv);
	if (!info)
		return (EXIT_FAILURE);
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philos)
	{
		ft_terminate_info(info);
		return (EXIT_FAILURE);
	}
	successed = start_philos(&info, &philos);
	ft_terminate_info(info);
	ft_terminate_philos(philos);
	if (successed == SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
