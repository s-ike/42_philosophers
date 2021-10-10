/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:02:01 by sikeda            #+#    #+#             */
/*   Updated: 2021/10/10 14:36:18 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <stdlib.h>
# include <sys/time.h>

typedef long long t_time;

t_time	get_mstime(void);
t_time	get_microtime(void);

#endif
