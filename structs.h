/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:20:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/28 16:55:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_textures
{
	int	no; //north texture file descriptor
	int	so; //south texture file descriptor
	int	we; //west texture file descriptor
	int	ea; //east texture file descriptor
	int	f; //floor rgb value
	int	c; //ceiling rgb value
}		t_textures;

typedef struct s_data
{
	int			mapfd;
	char		**map;
	t_textures	txtr;
}				t_data;

#endif
