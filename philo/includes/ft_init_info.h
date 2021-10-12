/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/12 12:41:48 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_INFO_H
# define FT_INIT_INFO_H

# include <stdlib.h>
# include <string.h>
# include "ft_utils.h"
# include "t_info.h"

t_info	*ft_init_info(int argc, const char **argv);

#endif
