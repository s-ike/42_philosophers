#include "mutex_print.h"

static void
	print(t_philo *philo, enum e_philo_status status)
{
	static t_time	start = 0;
	char			*msg;

	msg = "is died";
	if (status == ST_EAT)
		msg = "is eating";
	else if (status == ST_SLEEP)
		msg = "is sleeping";
	else if (status == ST_THINK)
		msg = "is thinking";
	if (start == 0)
		start = get_mstime();
	printf("%llu %d %s\n", get_mstime() - start, philo->id, msg);
}

void
	ft_mutex_print(t_philo *philo, t_philo_status status)
{
	pthread_mutex_lock(&philo->info->print_lock);
	print(philo, status);
	pthread_mutex_unlock(&philo->info->print_lock);
}
