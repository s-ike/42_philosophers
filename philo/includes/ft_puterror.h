/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:07:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 10:58:16 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTERROR_H
# define FT_PUTERROR_H

# include <stdio.h>
# include "def_color.h"

int		ft_puterror(const char *str);
int		ft_puterror_and_return(const char *str, int return_status);
void	*ft_puterror_and_nullreturn(const char *str);

#endif
