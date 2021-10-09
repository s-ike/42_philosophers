#ifndef PHIOL_H
# define PHIOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>

# define REQUIRED_ARGC 5
# define OPTIONAL_ARGC 6

enum e_status
{
	ST_EAT,
	ST_SLEEP,
	ST_THINK,
	ST_DIE,
	ST_END
};

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	print_lock;
}	t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	bool			is_dead;
	t_info			*info;
	// enum e_status	status;
	// pthread_mutex_t	status_lock;
}	t_philo;

/* terminate.c */
int		ft_terminate(t_info *info, t_philo *philos, bool should_destroy, int ret);
/* utils.c */
bool	ft_philo_atoi(const char *str, int *n);

#endif