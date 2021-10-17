/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:54 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/17 16:04:35 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_iseven(int n);
int		ft_isnumeric(const char *str);
int		ft_isover_intrange(const char *str);
int		ft_ispositive(int n);
int		ft_isspace(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int num, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *str);

#endif
