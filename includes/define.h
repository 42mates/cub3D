/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:40:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/11 15:16:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define PROGRAM_NAME "cub3d"

# define SPACES " \t\r\f\v"
# define SPACES_NL " \t\r\f\v\n"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 0
# define C 1

// width of the window
# define SIZE_X 	1280
// height of the window
# define SIZE_Y 	720

// field of view (60 degrees)
# define FOV		1.0471976f

# define SPEED		0.2f
// rotation speed
# define SPEED_R	0.1f

# define KEY_W 		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define KEY_M		109
# define KEY_MIN	45
# define KEY_PLUS	61

//number of pixels per element in the minimap
# define MINIMAP_SCALE	8

# define MINIMAP_PLAYER	0xEB5149
# define MINIMAP_WALL	0x17181A
# define MINIMAP_GROUND	0xF1EFDF

#endif