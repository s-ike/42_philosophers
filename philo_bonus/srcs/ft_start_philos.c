#include "ft_start_philos.h"

t_status
	ft_start_philos(t_info *info, t_philo *philo)
{
	pid_t	pid;
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
			printf("start: %lld\n", ft_get_mstime());
			sem_wait(info->forks_lock);
			ft_sem_print(philo, ST_FORK);
			sem_wait(info->forks_lock);
			ft_sem_print(philo, ST_FORK);
			ft_sem_print(philo, ST_EAT);
			ft_usleep(info->time_to_eat);
			sem_post(info->forks_lock);
			sem_post(info->forks_lock);
			ft_sem_print(philo, ST_SLEEP);
			ft_usleep(info->time_to_sleep);
			ft_sem_print(philo, ST_THINK);
			exit(EXIT_SUCCESS);
		}
		info->philo_pid[i] = pid;
	}
	int	wait_status;
	i = -1;
	while (++i < info->num_of_philo)
	{
		if (waitpid(-1, &wait_status, WUNTRACED | WCONTINUED) < 0) {
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
