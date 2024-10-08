/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:48:43 by locharve          #+#    #+#             */
/*   Updated: 2024/10/08 10:04:03 by locharve         ###   ########.fr       */
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
	EA_,
	F_,
	C_
}	t_av_id;

typedef struct s_cub
{
	char	**param_id;
	char	*av[6];
	char	*path[4]; // !
	char	rgb[2][3]; // ?
	char
	char	**map;
	t_error	error;
}	t_cub;

#endif