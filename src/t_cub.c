/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:55:32 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 12:06:43 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	t_cub_init(t_cub *cub)
{
	ft_bzero(cub, sizeof(cub));
	cub->param_id = strtab_init(4, "NO\0", "SO\0", "WE\0", "EA\0");
	if (!cub->param_id)
	{
		print_error(ERR_MALLOC, "t_cub_init");
		return (0);
	}
	cub->path = (char **)ft_calloc(5, sizeof(char *));
	if (!cub->path)
	{
		print_error(ERR_MALLOC, "t_cub_init");
		return (0);
	}
	cub->raw = NULL;
	cub->cmap = NULL;
	return (1);
}

void	print_rgb(int rgb[2][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 3)
		{
			ft_putnbr_fd(rgb[i][j], 1);
			if (j < 2)
				ft_putstr_fd(" , ", 1);
			j++;
		}
		i++;
		ft_putstr_fd("\n", 1);
	}
}

void	t_cub_print(t_cub *cub)
{
	ft_putstr_fd("\n======= T_CUB_PRINT =======\n", 1);
	ft_putstr_fd("\n-------  param_id   -------\n", 1);
	strtab_print(cub->param_id);
	ft_putstr_fd("\n-------     path    -------\n", 1);
	strtab_print(cub->path);
	ft_putstr_fd("\n-------     rgb     -------\n", 1);
	print_rgb(cub->rgb);
	ft_putstr_fd("\n-------     raw     -------\n", 1);
	strtab_print(cub->raw);
	ft_putstr_fd("\n-------     cmap    -------\n", 1);
	strtab_print(cub->cmap);
}

void	t_cub_destroy(t_cub *cub)
{
	strtab_free(cub->param_id);
	strtab_free(cub->path);
	strtab_free(cub->raw);
	strtab_free(cub->cmap);
	intptrtab_free(cub->imap);
}
