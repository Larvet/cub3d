/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:38:37 by locharve          #+#    #+#             */
/*   Updated: 2024/10/16 09:40:21 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing_cub(t_cub *cub, char *path)
{
	int	tmp;

	if (t_cub_make_strtab_from_file(cub, path))
	{
		tmp = check_format(cub->param_id, cub->raw);
		if (tmp)
		{
			print_format_error(tmp);
			return (0);
		}
		if (t_cub_set_args(cub, cub->raw))
		{
			cub->cmap = smooth_map(cub, cub->cmap);
			if (cub->cmap && check_map_edges(*cub, cub->cmap)
				&& t_cub_set_imap(cub, cub->cmap))
				return (1);
		}
	}
	return (0);
}