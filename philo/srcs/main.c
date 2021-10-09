#include "philo.h"

long long
	get_mstime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000LL);
}

long long
	get_microtime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000000LL + time.tv_usec);
}

void
	print(t_philo *philo, enum e_status status)
{
	char	*msg;

	msg = "is died";
	if (status == ST_EAT)
		msg = "is eating";
	else if (status == ST_SLEEP)
		msg = "is sleeping";
	else if (status == ST_THINK)
		msg = "is thinking";
	printf("%llu %d %s\n", get_mstime(), philo->id, msg);
}

// static bool
// 	ft_usleep(int time)
// {
// 	long long	crnt_tstamp;
// 	long long	end_tstamp;

// 	crnt_tstamp = get_microtime();
// 	if (crnt_tstamp == -1)
// 		return (false);
// 	end_tstamp = crnt_tstamp + time * 1000LL;
// 	while (crnt_tstamp < end_tstamp)
// 	{
// 		usleep(200);
// 		crnt_tstamp = get_microtime();
// 		if (crnt_tstamp == -1)
// 			return (false);
// 	}
// 	return (true);
// }

static bool
	ft_usleep(int time)
{
	long long	crnt_tstamp;
	long long	end_tstamp;

	crnt_tstamp = get_mstime();
	if (crnt_tstamp == -1)
		return (false);
	end_tstamp = crnt_tstamp + time;
	while (crnt_tstamp < end_tstamp)
	{
		usleep(500);
		crnt_tstamp = get_mstime();
		if (crnt_tstamp == -1)
			return (false);
	}
	return (true);
}

static void
	ph_do(t_philo *philo, enum e_status status)
{
	pthread_mutex_lock(&philo->info->print_lock);
	print(philo, status);
	pthread_mutex_unlock(&philo->info->print_lock);
	if (status == ST_EAT)
		ft_usleep(philo->info->time_to_eat);
	else if (status == ST_SLEEP)
		ft_usleep(philo->info->time_to_sleep);
}

void
	ph_eat(t_philo *philo)
{
	ph_do(philo, ST_EAT);
}

void
	ph_sleep(t_philo *philo)
{
	ph_do(philo, ST_SLEEP);
}

void
	ph_think(t_philo *philo)
{
	ph_do(philo, ST_THINK);
}

void
	ph_died(t_philo *philo)
{
	if (philo->id == 5)
		philo->is_dead = true;
	if (philo->is_dead)
		ph_do(philo, ST_DIE);
}

void
	*philo(void *philo_p)
{
	t_philo			*philo;
	struct timeval	time;

	philo = philo_p;
	gettimeofday(&time, NULL);
	printf("%d %d comming! num of philo: %d\n",
		(int)time.tv_usec, philo->id, philo->info->num_of_philo);
	while (philo->is_dead == false)
	{
		pthread_mutex_lock(&philo->info->fork_lock[philo->id - 1]);
		pthread_mutex_lock(&philo->info->fork_lock[philo->id % philo->info->num_of_philo]);
		ph_eat(philo);
		pthread_mutex_unlock(&philo->info->fork_lock[philo->id - 1]);
		pthread_mutex_unlock(&philo->info->fork_lock[philo->id % philo->info->num_of_philo]);

		ph_sleep(philo);
		ph_think(philo);
		ph_died(philo);
	}
	if (philo->is_dead)
		printf("%d dead", philo->id);
	return (NULL);
}

static bool
	can_init_info(t_info **info, int argc, char **argv)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!*info)
		return (false);
	memset(*info, 0, sizeof(t_info));
	if (!ft_philo_atoi(argv[1], &(*info)->num_of_philo)
		|| !ft_philo_atoi(argv[2], &(*info)->time_to_die)
		|| !ft_philo_atoi(argv[3], &(*info)->time_to_eat)
		|| !ft_philo_atoi(argv[4], &(*info)->time_to_sleep))
	{
		free(*info);
		return (false);
	}
	if (argc == OPTIONAL_ARGC
		&& !ft_philo_atoi(argv[5], &(*info)->num_must_eat))
	{
		free(*info);
		return (false);
	}
	(*info)->fork_lock = (pthread_mutex_t *)malloc(
		sizeof(pthread_mutex_t) * (*info)->num_of_philo);
	if (!(*info)->fork_lock)
	{
		free(*info);
		return (false);
	}
	return (true);
}

static bool
	init_philos(t_info **info, t_philo **philos)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * (*info)->num_of_philo);
	if (!*philos)
	{
		free((*info)->fork_lock);
		free(*info);
		return (false);
	}
	return (true);
}

static bool
	init_mutex(t_info **info, t_philo **philos)
{
	int	i;

	if (pthread_mutex_init(&(*info)->print_lock, NULL) != 0)
		return (ft_terminate(*info, *philos, false, (int)false));
	i = -1;
	while (++i < (*info)->num_of_philo)
	{
		if (pthread_mutex_init(&(*info)->fork_lock[i], NULL))
		{
			pthread_mutex_destroy(&(*info)->print_lock);
			while (0 <= i)
				pthread_mutex_destroy(&(*info)->fork_lock[i--]);
			return (ft_terminate(*info, *philos, false, (int)false));
		}
	}
	return (true);
}

static bool
	start_philos(t_info **info, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < (*info)->num_of_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].is_dead = false;
		(*philos)[i].info = *info;
		if (pthread_create(&(*philos)[i].thread, NULL, philo, (void *)&(*philos)[i]))
			return (ft_terminate(*info, *philos, true, (int)false));
	}
	i = -1;
	while (++i < (*info)->num_of_philo)
	{
		if (pthread_join((*philos)[i].thread, NULL))
			return (ft_terminate(*info, *philos, true, (int)false));
	}
	return (true);
}

int
	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;

	if ((argc != REQUIRED_ARGC && argc != OPTIONAL_ARGC)
		|| !can_init_info(&info, argc, argv)
		|| !init_philos(&info, &philos)
		|| !init_mutex(&info, &philos)
		|| !start_philos(&info, &philos))
		return (1);
	return (ft_terminate(info, philos, true, 0));
}
