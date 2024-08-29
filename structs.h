/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:20:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/08/29 17:25:20 by akurochk         ###   ########.fr       */
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
	/* data */
}			t_ray;	


#endif
