/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:16:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/29 13:50:29 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>      // for open
#include <unistd.h>     // for close, read, write
#include <stdio.h>      // for printf
#include <stdlib.h>     // for malloc, free, exit
#include <errno.h>      // for perror, strerror
#include <sys/time.h>   // for gettimeofday
#include <math.h>       // for math functions

# include "defines.h"
# include "enum.h"
# include "libft/libft.h"
# include "structs.h"

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

int	parsing(int ac, char **av, t_data *data);

#endif
