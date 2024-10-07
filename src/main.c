/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:57:37 by locharve          #+#    #+#             */
/*   Updated: 2024/10/07 09:35:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_strtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		i++;
	}
}

static void	free_strtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	char	**strtab;

	if (argc == 2)
	{
		strtab = make_strtab_from_file(argv[1]);
		print_strtab(strtab);
		free_strtab(strtab);

	}
	else
		print_error(ERR_BADARG, NULL);
}