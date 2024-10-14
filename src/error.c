/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:42:14 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 06:34:49 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *error, char *context)
{
	if (error)
	{
		write(2, error, ft_strlen(error));
		if (context)
			write(2, context, ft_strlen(context));
		write(2, "\n", 1);
	}
}

void	print_format_error(int check)
{
	char	**errtab;
	int		i;

	if (!check)
		return ;
	errtab = strtab_init(3, ERR_BADTEX, ERR_BADRGB, ERR_BADMAP);
	if (errtab)
	{
		i = 0;
		while (i < 3 && i != check - 1)
			i++;
		print_error(ERR_ERROR, errtab[i]);
		strtab_free(errtab);
	}
}
