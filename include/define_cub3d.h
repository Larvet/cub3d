/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:28 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 12:08:06 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_CUB3D_H
# define DEFINE_CUB3D_H

# define ERR_ERROR "Error\n" ////
# define ERR_MALLOC "Malloc error at: "
# define ERR_FILEOP "Cannot open file: "
# define ERR_BADARG "Invalid number of arguments (must be 1)"
# define ERR_BADTEX "Texture lines must be formated as follows:\n\t<NO> <path_to_north_texture>\n\t<SO> <path_to_north_texture>\n\t<WE> <path_to_north_texture>\n\t<EA> <path_to_north_texture>"
# define ERR_BADRGB "RGB lines must be formated as follows:\n\tF <0-255>,<0-255>,<0-255>\n\tC <0-255>,<0-255>,<0-255>"
# define ERR_BADMAP "Map must be at the end of file and formated with characters:\n\t'0', '1', 'N'/'S'/'W'/'E'\n\tThere can be no space inside the map."
# define ERR_BADEXT "Map file extension must be .cub"
# define ERR_OPENM "Map must be closed (surrounded by '1'). There can be no space inside the map"

# define WHITESPACES "\t\n\v\f\r "
# define VALID_MAP "01 " // deprecated
# define VALID_POS "NSWE" // deprecated

#endif