/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:20:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/16 13:13:17 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_ray
{
	float	dx;
	float	dy;
	int		x_sign;
	int		y_sign;
	float	x_h;
	float	y_h;
	float	x_v;
	float	y_v;
	float	s_hor;
	float	s_ver;
	float	d_h;
	float	d_v;

}			t_ray;

typedef struct s_img
{
	void	*img_ptr;
	char	*d_a;
	int		bpp;
	int		s_l;
	int		en;
	int		size_x;
	int		size_y;
}			t_img;

typedef struct s_data
{
	char			*textures[4];
	int				colors[2];
	char			**map;
	int				map_h;
	int				map_w;
	float			p_x;
	float			p_y;
	float			dir_v;
	t_img			img;
	t_img			img_txt[4];
	int				id_txt;
	float			w_txt;
	int				allow_minimap;
	unsigned char	mini_scale;
	void			*win;
	void			*mlx;
	int				mouse_down;
	int				mouse_x;
}			t_data;

#endif
