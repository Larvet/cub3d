/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:08:42 by locharve          #+#    #+#             */
/*   Updated: 2024/10/09 11:07:23 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_incharset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && set && is_in_str(set, str[i]))
		i++;
	return (i);
}

int	skip_outcharset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && set && !is_in_str(set, str[i]))
		i++;
	return (i);
}

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
		len = 0;
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

static int	t_cub_set_rgb(t_cub *cub, char **strtab)
{
	int	i;
	int	j;
	int	k;
	int	pos;

	i = 0;
	j = -1;
	while (strtab && strtab[i] && ++j < 2)
	{
		i += skip_empty_lines(&strtab[i]);
		k = -1;
		while (++k < 3)
		{
			pos = skip_incharset(&strtab[i][1], WHITESPACES);
			cub->rgb[j][k] = ft_atoi(&strtab[i][pos]); // protecc atoi ?
			if (cub->rgb[j][k] < 0 || cub->rgb[j][k] > 255)
			{
				print_error(ERR_BADRGB, NULL);
				break ;
			}
		}
	}
	return (i * (j == 2));
}

static int	t_cub_set_map(t_cub *cub, char **strtab)
{
	size_t	i;
	size_t	j;
	size_t	size;

	if (!cub || !strtab)
		return (0);
	size = skip_empty_lines(strtab);
	i = size;
	j = 0;
	while (strtab && strtab[size] && !str_isonly(strtab[size], WHITESPACES))
		size++;
	cub->map = ft_calloc(size + 1, sizeof(char *));
	while (cub->map && strtab[i + j] && i + j < size)
	{
		cub->map[j] = ft_strdup(strtab[i + j]);
		if (!cub->map[j])
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
	tmp = t_cub_set_rgb(cub, &strtab[i + 1]);
	if (!tmp)
		return (0);
	i += tmp;
	return (t_cub_set_map(cub, &strtab[i]));
	// strtab_free in calling function
}

// next steps :
// flood fill
// make map square