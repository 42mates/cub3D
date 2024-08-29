/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:20:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/29 13:35:22 by akurochk         ###   ########.fr       */
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
	int			map_l;	// length of the map
	int			map_w;	// width of the map
	float		pos_x;	// x position of the player
	float		pos_y;	// y position of the player
	float		dir_v;	// view direction of the player

	void		*win;
	
	void		*mlx;
	void		*img;
	
	t_textures	txtr;
}				t_data;

#endif
