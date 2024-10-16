/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_edges.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:59:07 by locharve          #+#    #+#             */
/*   Updated: 2024/10/16 10:05:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(t_cub cub, char **map, int x, int y)
{
	if (y < 0 || y >= (int)cub.height
		|| x < 0 || x >= (int)cub.width)
		return (1);
	else if (map[y][x] == '1' || map[y][x] == 'X')
		return (1);
	else if (map[y][x] == ' ')
	{
		map[y][x] = 'X';
		return (flood_fill(cub, map, x - 1, y)
			&& flood_fill(cub, map, x + 1, y)
			&& flood_fill(cub, map, x, y - 1)
			&& flood_fill(cub, map, x, y + 1));
	}
	else
		return (0);
}

int	check_map_edges(t_cub cub, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = skip_outcharset(map[y], WHITESPACES);
		while (map[y][x])
		{
			if (map[y][x] && !flood_fill(cub, map, x, y))
			{
				print_error(ERR_OPENM, NULL);
				return (0);
			}
			x += skip_outcharset(&map[y][x], WHITESPACES);
		}
		y++;
	}
	return (1);
}
