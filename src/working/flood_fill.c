/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:32:39 by locharve          #+#    #+#             */
/*   Updated: 2024/10/09 10:45:15 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_pos(char **map, int *x, int *y)
{
	*y = 0;
	while (map && map[*y] && !str_contains(map[*y], "NSWE"))
		*y += 1;
	*x = 0;
	while (map && map[*y] && map[*y][*x]
		&& !is_in_str("NSWE", map[*y][*x]))
		*x += 1;
}

int	flood_fill(char **map) // int ** ?
{
	int	x;
	int	y;

	set_pos(map, x, y);

}