/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:57:37 by locharve          #+#    #+#             */
/*   Updated: 2024/10/10 11:57:50 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	strtab_print(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	char	**strtab;

	if (argc == 2)
	{
		t_cub_init(&cub);
		strtab = make_strtab_from_file(argv[1]);
		if (strtab)
		{
			printf("check_format = %d\n", check_format(cub.param_id, strtab)); ///
			strtab_print(strtab);
			strtab_free(strtab); // strtab_free
		}
		t_cub_destroy(&cub);
	}
	else
		print_error(ERR_BADARG, NULL);
}