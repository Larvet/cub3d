/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 06:32:45 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 10:26:54 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	atoi_rgb(int *rgb, char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && ft_isdigit(str[i]))
		i++;
	if (i > 3)
		return (0);
	*rgb = ft_atoi(str);
	if (*rgb < 0 || *rgb > 255)
		return (-1);
	return (i);
}

static int	t_cub_set_each_color(t_cub *cub, char *str, t_color_id c_id)
{
	int	i;
	int	pos;
	int	tmp;

	pos = 1;
	i = 0;
	while (i < 3)
	{
		pos += skip_incharset(&str[pos], WHITESPACES);
		tmp = atoi_rgb(&cub->rgb[c_id][i], &str[pos]);
		if (tmp < 0)
			break ;
		pos += tmp;
		pos += skip_incharset(&str[pos], WHITESPACES);
		if (i < 2 && str[pos] != ',')
			break ;
		pos++;
		i++;
	}
	return (i == 3);
}

int	t_cub_set_rgb(t_cub *cub, char **strtab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strtab && strtab[i] && j < 2)
	{
		i += skip_empty_lines(&strtab[i]);
		if (!t_cub_set_each_color(cub, strtab[i], (t_color_id)j))
			break ;
		i++;
		j++;
	}
	if (i && j == 2)
		return (i);
	else
		return (0);
}
