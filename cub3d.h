/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:16:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/04 16:50:54 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <math.h>

# include "enum.h"
# include "libft/libft.h"
# include "structs.h"
# include "define.h"

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

int		parsing(int ac, char **av, t_data *data);

#endif
