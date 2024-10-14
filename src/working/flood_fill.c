/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:32:39 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 10:18:06 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h> /////////////

static char	*one_char_str(size_t size, char c)
{
	char	*dst;
	size_t	i;

	dst = ft_calloc(size + 1, sizeof(char));
	if (dst)
	{
		i = 0;
		while (i < size)
		{
			dst[i] = c;
			i++;
		}
	}
	return (dst);
}

static void	clear_terminal(size_t n)
{
	char	*str;

	str = one_char_str(n, '\b');
	if (str)
	{
		printf("%s", str);
//		write(1, str, ft_strlen(str));
		free(str);
//		str = one_char_str(n, ' ');
//		write(1, str, ft_strlen(str));
//		free(str);
	}
}

int	flood_fill(t_cub cub, char **map, int px, int py) // start: x = player_pos.x; y = player_pos.y;
{
	size_t	n;

//	printf("px = %d\tpy = %d\n", px, py);
//	strtab_print(map);
	//
	n = strtab_print(map);	//
//	fflush(stdout); //
	usleep(500000); ////
	if (n > 0)
		clear_terminal(n);	//
	if (px < 0 || px >= (int)cub.width || py < 0 || py >= (int)cub.height)
	{
		print_error(ERR_OPENM, NULL);
		return (0);
	}
	else if (map[py][px] == ' ')
	{
		print_error(ERR_SPACE, NULL);
		return (0);
	}
	else if (map[py][px] == '1' || map[py][px] == 'X')
		return (1);
	else if (map[py][px] == '0' || is_in_str("NSWE", map[py][px]))
	{
		map[py][px] = 'X';
		return (flood_fill(cub, map, px - 1, py)
			&& flood_fill(cub, map, px + 1, py)
			&& flood_fill(cub, map, px, py - 1)
			&& flood_fill(cub, map, px, py + 1));
	}
	else // invalid character
	{
		printf("px = %d\tpy = %d\tc = %c\n", px, py, map[py][px]);
		return (0);
	}
}
