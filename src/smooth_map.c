/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:04:50 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 12:06:40 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strcpy_fill(char *dst, char *src, size_t len, char fill)
{
	size_t	i;

	i = 0;
	while (dst && src && src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = fill;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**make_map_rectangle(char **dst, char **src, size_t len)
{
	int	i;

	i = 0;
	while (dst && src && src[i])
	{
		dst[i] = ft_calloc(len + 1, sizeof(char));
		if (!dst[i])
		{
			print_error(ERR_MALLOC, "make_map_rectangle");
			strtab_free(dst);
			return (NULL);
		}
		dst[i] = ft_strcpy_fill(dst[i], src[i], len, ' ');
		i++;
	}
	return (dst);
}

void	set_pos(t_pos *player_pos, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map && map[y] && !str_contains(map[y], "NSWE"))
		y++;
	x = 0;
	while (map && map[y] && map[y][x]
		&& !is_in_str("NSWE", map[y][x]))
		x++;
	player_pos->x = x;
	player_pos->y = y;
}

char	**smooth_map(t_cub *cub, char **map)
{
	char	**new_map;

	cub->width = strtab_max_len(map);
	cub->height = strtab_size(map);
	new_map = ft_calloc(cub->height + 1, sizeof(char *));
	if (!new_map)
	{
		print_error(ERR_MALLOC, "smooth_map");
		return (NULL);
	}
	new_map = make_map_rectangle(new_map, map, cub->width);
	if (new_map)
		set_pos(&cub->player_pos, new_map);
	strtab_free(map);
	return (new_map);
}
