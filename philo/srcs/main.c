#include "philo.h"

void
	print(t_philo *philo, enum e_status status)
{
	struct timeval	time;
	char			*msg;

	gettimeofday(&time, NULL);
	msg = "is died";
	if (status == ST_EAT)
		msg = "is eating";
	else if (status == ST_SLEEP)
		msg = "is sleeping";
	else if (status == ST_THINK)
		msg = "is thinking";
	printf("%d %d %s\n", time.tv_usec, philo->id, msg);
}

static void
	ph_do(t_philo *philo, enum e_status status)
{
	pthread_mutex_lock(&philo->info->print_lock);
	print(philo, status);
	pthread_mutex_unlock(&philo->info->print_lock);
	if (status == ST_EAT)
		usleep(philo->info->time_to_eat * 1000);
	else if (status == ST_SLEEP)
		usleep(philo->info->time_to_sleep * 1000);
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
	printf("%d %d comming! num of philo: %d\n", time.tv_usec, philo->id, philo->info->num_of_philo);
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
	fflush(stdout);
	return (NULL);
}

static void
	set_info(t_info *info, int argc, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		// TODO:
	}
}

int
	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philos;
	int		err;

	if (argc != 5 && argc != 6)
		return (1);
	// TODO: valid_arg
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (1);
	set_info(info, argc, argv);
	err = pthread_mutex_init(&info->print_lock, NULL);
	if (err != 0)
	{
		free(info);
		return (1);
	}
	printf("philo num %d\n", info->num_of_philo);
	info->fork_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->fork_lock)
	{
		free(info);
		return (1);
	}
	philos = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philos)
	{
		free(info->fork_lock);
		free(info);
		return (1);
	}
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		err = pthread_mutex_init(&info->fork_lock[i], NULL);
		if (err != 0)
		{
			free(info->fork_lock);
			free(philos);
			return (1);
		}
	}
	puts("make mutex done.");

	i = -1;
	while (++i < info->num_of_philo)
	{
		if (err != 0)
		{
			free(info->fork_lock);
			free(philos);
			return (1);
		}
		philos[i].id = i + 1;
		philos[i].is_dead = false;
		philos[i].info = info;
		err = pthread_create(&philos[i].thread, NULL, philo, (void *)&philos[i]);
		if (err != 0)
		{
			free(info->fork_lock);
			free(philos);
			return (1);
		}
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		err = pthread_join(philos[i].thread, NULL);
		if (err != 0)
		{
			free(info->fork_lock);
			free(philos);
			return (1);
		}
	}
	return (0);
}
