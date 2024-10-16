/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:46:58 by locharve          #+#    #+#             */
/*   Updated: 2024/10/16 08:56:42 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc == 2)
	{
		t_cub_init(&cub);
		if (parsing_cub(&cub, argv[1]))
			t_cub_print(&cub);
		// execution
		t_cub_destroy(&cub);
	}
	else
		print_error(ERR_BADARG, NULL);
	return (0);
}