#include "ft_start_philos.h"

bool
	ft_check_if_dead(t_philo *philo)
{
	const t_time	crnt_time = ft_get_mstime();

	if (philo->info->time_to_die <= crnt_time - philo->last_ate)
		return (true);
	return (false);
}

void
	philo_do(t_philo *philo, t_philo_status status)
{
	if (status != ST_DIE && ft_check_if_dead(philo))
		return ;
	ft_sem_print(philo, status);
}

static void
	philo_routine(t_info *info, t_philo *philo)
{
	philo->last_ate = ft_get_mstime();
	sem_wait(info->forks_lock);
	philo_do(philo, ST_FORK);
	sem_wait(info->forks_lock);
	philo_do(philo, ST_FORK);
	philo_do(philo, ST_EAT);
	philo->last_ate = ft_get_mstime();
	philo->eat_cnt++;
	if (philo->eat_cnt < 0)
		philo->eat_cnt = 0;
	// TODO:
	ft_usleep(info->time_to_eat);
	sem_post(info->forks_lock);
	sem_post(info->forks_lock);
	philo_do(philo, ST_SLEEP);
	ft_usleep(info->time_to_sleep);
	philo_do(philo, ST_THINK);
	exit(EXIT_SUCCESS);
}

t_status
	ft_start_philos(t_info *info, t_philo *philo)
{
	pid_t	pid;
	int		wait_status;
	int		i;

	i = -1;
	philo->start_time = ft_get_mstime();
	while (++i < info->num_of_philo)
	{
		pid = fork();
		if (pid < 0)
			return (FAILURE);
		else if (pid == 0)
		{
			philo->id = i + 1;
			philo_routine(info, philo);
		}
		info->philo_pid[i] = pid;
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (waitpid(-1, &wait_status, WUNTRACED | WCONTINUED) < 0) {
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
