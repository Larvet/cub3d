/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:55:32 by locharve          #+#    #+#             */
/*   Updated: 2024/10/10 10:57:03 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	t_cub_init(t_cub *cub)
{
	ft_bzero(cub, sizeof(cub));
	cub->param_id = strtab_init(4, "NO\0", "SO\0", "WE\0", "EA\0");
	if (!cub->param_id)
		return (0);
	cub->path = NULL;
	cub->map = NULL;
	return (1);
}

void	t_cub_destroy(t_cub *cub)
{
	strtab_free(cub->param_id);
	strtab_free(cub->path);
	strtab_free(cub->map);
}