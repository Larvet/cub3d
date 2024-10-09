/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_check_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:28:12 by locharve          #+#    #+#             */
/*   Updated: 2024/10/09 07:30:27 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	nswe_line_format(char *line, char *param_id)
{
	int	i;

	if (!ft_strcmp(line, param_id))
	{
		i = 2;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		while (ft_isascii(line[i]))
			i++;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		return (!line[i]);
	}
	return (0);
}

static int	color_format(char *line, char *param_id)
{
	int	i;

	if (!ft_strcmp(line, param_id))
	{
		i = 1;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		while (ft_isdigit(line[i])) // check value ?
			i++;
	}
	return (0);
}

static int	t_cub_check_av(char *av)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4 && nswe_line_format(av[i], cub->param_id[i])) // textures
		i++;
	while (i >= 4 && color_line_format(av[i], cub->param_id[i]))
		i++;
	return (i == 6);
}

int	t_cub_check_args(t_cub *cub)
{
	return (t_cub_check_av(cub->av) && t_cub_check_map(cub->map));
}