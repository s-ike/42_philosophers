/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:36 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/09 16:02:32 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_INFO_H
# define INIT_INFO_H

# include <stdlib.h>
# include <string.h>
# include "utils.h"
# include "t_info.h"

t_info	*init_info(int argc, const char **argv);

#endif
