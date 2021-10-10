/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:54 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/09 15:59:55 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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