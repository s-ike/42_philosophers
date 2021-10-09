#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <stdbool.h>

long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isnumeric(const char *str);
int		ft_isover_intrange(const char *str);
int		ft_isspace(char c);

#endif
