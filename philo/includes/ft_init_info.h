/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/24 10:48:27 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_INFO_H
# define FT_INIT_INFO_H

# include <stdlib.h>
# include <string.h>
# include "def_error.h"
# include "t_info.h"
# include "t_status.h"
# include "ft_is_valid_arg_nums.h"
# include "ft_puterror.h"
# include "ft_utils.h"

t_status	ft_init_info(t_info *info, int argc, const char **argv);

#endif
