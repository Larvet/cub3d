/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:08:42 by locharve          #+#    #+#             */
/*   Updated: 2024/10/16 09:40:14 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	t_cub_set_paths(t_cub *cub, char **strtab)
{
	int	i;
	int	j;
	int	pos;
	int	len;

	i = 0;
	j = 0;
	while (strtab && strtab[i] && j < 4)
	{
		i += skip_empty_lines(&strtab[i]);
		pos = 2 + skip_incharset(&strtab[i][2], WHITESPACES);
		len = skip_outcharset(&strtab[i][pos], WHITESPACES);
		cub->path[j] = ft_strndup(&strtab[i][pos], len);
		if (!cub->path[j])
		{
			print_error(ERR_MALLOC, "t_cub_set_paths");
			return (0);
		}
		i++;
		j++;
	}
	return (i);
}

static int	t_cub_set_map(t_cub *cub, char **strtab)
{
	size_t	i;
	size_t	j;
	size_t	size;

	if (!cub || !strtab)
		return (0);
	i = skip_empty_lines(strtab);
	size = i;
	j = 0;
	while (strtab && strtab[size] && !str_isonly(strtab[size], WHITESPACES))
		size++;
	cub->cmap = ft_calloc(size - i + 1, sizeof(char *));
	while (cub->cmap && strtab[i + j] && i + j < size)
	{
		cub->cmap[j] = ft_strdup(strtab[i + j]);
		if (!cub->cmap[j])
			break ;
		j++;
	}
	if (i + j < size)
		print_error(ERR_MALLOC, "t_cub_set_map");
	return (i + j == size);
}

int	t_cub_set_args(t_cub *cub, char **strtab)
{
	int	i;
	int	tmp;

	i = t_cub_set_paths(cub, strtab);
	if (!i)
		return (0);
	tmp = t_cub_set_rgb(cub, &strtab[i]);
	if (!tmp)
		return (0);
	i += tmp;
	return (t_cub_set_map(cub, &strtab[i]));
}
