/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:29:36 by locharve          #+#    #+#             */
/*   Updated: 2024/10/08 10:04:08 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	strtab_free(char **strtab)
{
	int	i;

	i = 0;
	while (strtab && strtab[i])
	{
		free(strtab[i]);
		i++;
	}
	if (strtab)
		free(strtab);
}

char	**strtab_init(size_t size, ...)
{
	va_list	p;
	char	**strtab;
	size_t	i;

	strtab = ft_calloc(size + 1, sizeof(char *));
	if (strtab)
	{
		va_start(p, size);
		i = 0;
		while (i < size)
		{
			strtab[i] = ft_strdup(va_arg(p, char *));
			if (!strtab[i])
			{
				strtab_free(strtab);
				break ;
			}
		}
		va_end(p);
	}
	return (strtab);
}