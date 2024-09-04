/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:40:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/04 16:50:37 by akurochk         ###   ########.fr       */
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

# define SIZE_X 	640
# define SIZE_Y 	480
# define FOV		1.0471976f // (M_PIf / 3) field_of_view 60 degrees in radians ( is used for console games )

# define SPEED		0.2f // 0.2f : walk 20% of block size each keypress
# define SPPED_R	0.2f // 0.2f : view direction roration 0.2*PI each keypress


// hope there is a way how to use correct KEY-set during compilation

// for linux
# define KEY_W 		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
// # define KEY_UP		65362
// # define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307

// for apple
// # define KEY_W 		13
// # define KEY_A		0
// # define KEY_S		1
// # define KEY_D		2
// # define KEY_UP		126
// // # define KEY_DOWN	125
// // # define KEY_LEFT	123
// # define KEY_RIGHT	124
// # define KEY_ESC	53

#endif