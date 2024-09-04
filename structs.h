/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:20:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/03 16:14:56 by akurochk         ###   ########.fr       */
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

	// we can add structure to collect image data
	void		*img;	// img_ptr
	char		*d_a;	// data_addr
	int			bpp;	// bits_per_pixel
	int			s_l;	// size_line
	int			en;		// endian;
		
	void		*win;
	
	void		*mlx;
	
	t_textures	txtr;
}				t_data;

typedef struct s_ray
{
	float dx;	// x distance to the wall
	float dy;	// y distance to the wall

	int x_sign;	// sign of the x direction
	int y_sign;	// sign of the y direction

	float x_hor; // for horizonal wall collision
	float y_hor; // for horizonal wall collision
	
	float x_ver; // for vertical wall collision
	float y_ver; // for vertical wall collision

	float s_hor; // horizontal step of the ray
	float s_ver; // vertical step of the ray

	float d_hor; // distance to horizontal wall or grid
	float d_ver; // distance to vertical wall or grid
	
}			t_ray;	


#endif
