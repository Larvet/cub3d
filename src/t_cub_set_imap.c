/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_imap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:56:20 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 12:07:55 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	imap_print(t_cub cub, int **map)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (i < cub.height)
	{
		j = 0;
		while (j < cub.width)
		{
			c = map[i][j] + 48;
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	intptrtab_free(int **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

int	*set_inttab(t_cub *cub, char *line)
{
	int		*dst;
	size_t	i;

	dst = ft_calloc(cub->width, sizeof(int));
	if (dst)
	{
		i = 0;
		while (i < cub->width && line[i])
		{
			if (line[i] == 'X' || line[i] == '0')
				dst[i] = 0;
			else if (line[i] == '1')
				dst[i] = 1;
			else if (is_in_str("NSWE", line[i]))
				dst[i] = 2;
			else
			{
				print_error(ERR_BADMAP, NULL);
				break;
			}
			i++;
		}
	}
	else
	{
		print_error(ERR_MALLOC, "set_inttab()");
	}
	if (dst && i < cub->width)
	{
		free(dst);
		dst = NULL;
	}
	return (dst);
}

int	t_cub_set_imap(t_cub *cub, char **cmap)
{
	int		**new_tab;
	size_t	i;

	new_tab = ft_calloc(cub->height + 1, sizeof(int *));
	i = 0;
	while (new_tab && i < cub->height)
	{
		new_tab[i] = set_inttab(cub, cmap[i]);
		if (!new_tab[i])
			break;
		i++;
	}
	if (cmap[i])
	{
		intptrtab_free(new_tab);
	}
	cub->imap = new_tab;
	return (cub->imap != NULL);
}