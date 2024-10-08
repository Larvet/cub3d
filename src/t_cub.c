/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:55:32 by locharve          #+#    #+#             */
/*   Updated: 2024/10/08 10:04:11 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	t_cub_init(t_cub *cub)
{
	ft_bzero(cub, sizeof(cub));
	cub->param_id = strtab_init(6, "NO", "SO", "WE", "EA", "F", "C");
	if (!cub->param_id)
		return (0);
	return (1);
}

void	t_cub_delete(t_cub *cub)
{
	strtab_free(cub->param_id);
}