/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/15 22:44:40 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_INFO_H
# define FT_INIT_INFO_H

# include <stdlib.h>
# include <string.h>
# include "ft_is_valid_arg_nums.h"
# include "ft_utils.h"
# include "t_info.h"

t_info	*ft_init_info(int argc, const char **argv);

#endif
