/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:42:14 by locharve          #+#    #+#             */
/*   Updated: 2024/10/07 07:56:38 by locharve         ###   ########.fr       */
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