#include "ft_start_philos.h"
#include <stdio.h>

t_status
	ft_start_philos(t_info *info, t_philo *philos)
{
	static t_time	start = 0;
	int				i;

	i = -1;
	if (start == 0)
		start = ft_get_mstime();
	while (++i < info->num_of_philo)
	{
		pid_t	pid;
		int		wait_status;

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
			printf("%lld %d has taken a fork\n", ft_get_mstime() - start, philos[i].id);
			printf("%lld %d has taken a fork\n", ft_get_mstime() - start, philos[i].id);
			printf("%lld %d is eating\n", ft_get_mstime() - start, philos[i].id);
			ft_usleep(info->time_to_eat);
			printf("%lld %d is sleeping\n", ft_get_mstime() - start, philos[i].id);
			ft_usleep(info->time_to_sleep);
			printf("%lld %d is thinking\n", ft_get_mstime() - start, philos[i].id);
			exit(EXIT_SUCCESS);
		}
		// parent
		if (waitpid(pid, &wait_status, WUNTRACED | WCONTINUED) < 0) {
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
