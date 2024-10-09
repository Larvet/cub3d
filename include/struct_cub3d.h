/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:48:43 by locharve          #+#    #+#             */
/*   Updated: 2024/10/09 11:07:16 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_CUB3D_H
# define STRUCT_CUB3D_H

tupedef enum e_error
{}	t_error;

typedef enum e_av_id
{
	NO_,
	SO_,
	WE_,
	EA_
}	t_av_id;

typedef enum e_color_id // to be able to write rgb[F_][R_], rgb[F_][G_] etc.
{
	F_,
	C_
}	t_color_id;

typedef enum e_rgb_id
{
	R_,
	G_,
	B_
}	t_rgb_id;

typedef struct s_cub
{
	char			**param_id;
//	char			**raw;
//	char			*av[4];
	char			*path[4];
	int				rgb[2][3]; // 0 = F_ ; 1 = C_
//	t_rgb			rgb_f;
//	t_rgb			rgb_c;
	char	**map;

	t_error	error;
}	t_cub;

#endif