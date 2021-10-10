#include "terminate.h"

#ifdef LEAKS

void
	destructor(void)__attribute__((destructor));

void
	destructor(void)
{
	char	buf[20];

	snprintf(buf, 20, "leaks %d", getpid());
	system(buf);
}
#endif

static void
	destroy_all_mutex(t_info *info)
{
	int	i;

	pthread_mutex_destroy(&info->print_lock);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->fork_lock[i]);
}

void
	ft_terminate(t_info *info, t_philo *philos)
{
	destroy_all_mutex(info);
	free(info->fork_lock);
	free(info);
	free(philos);
}
