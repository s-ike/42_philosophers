#include "ft_start_philos.h"

t_status
	ft_start_philos(t_info *info, t_philo *philos)
{
	static t_time	start = 0;
	pid_t			pid;
	sem_t			*sem;
	int				i;

	sem = sem_open("/forks", O_CREAT, S_IRWXU, info->num_of_philo);

	i = -1;
	if (start == 0)
		start = ft_get_mstime();
	while (++i < info->num_of_philo)
	{
		pid = fork();
		if (pid < 0)
		{
			// error
			return (FAILURE);
		}
		else if (pid == 0)
		{

			// child
			printf("start: %lld\n", start);
			sem_wait(sem);
			printf("%lld %d %shas taken a fork%s\n", ft_get_mstime() - start, philos[i].id, COLOR_CYAN, COLOR_RESET);
			sem_wait(sem);
			printf("%lld %d %shas taken a fork%s\n", ft_get_mstime() - start, philos[i].id, COLOR_CYAN, COLOR_RESET);
			printf("%lld %d %sis eating%s\n", ft_get_mstime() - start, philos[i].id, COLOR_GREEN, COLOR_RESET);
			ft_usleep(info->time_to_eat);
			sem_post(sem);
			sem_post(sem);
			printf("%lld %d %sis sleeping%s\n", ft_get_mstime() - start, philos[i].id, COLOR_BLUE, COLOR_RESET);
			ft_usleep(info->time_to_sleep);
			printf("%lld %d %sis thinking%s\n", ft_get_mstime() - start, philos[i].id, COLOR_YELLOW, COLOR_RESET);
			exit(EXIT_SUCCESS);
		}
		// parent
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
	sem_close(sem);
	return (SUCCESS);
}
