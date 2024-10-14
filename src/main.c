/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:57:37 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 12:07:58 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc == 2)
	{
		t_cub_init(&cub);
		if (t_cub_make_strtab_from_file(&cub, argv[1]))
		{
			print_format_error(check_format(cub.param_id, cub.raw));
			if (t_cub_set_args(&cub, cub.raw))
			{
			//	strtab_print(cub.cmap);
				cub.cmap = smooth_map(&cub, cub.cmap);
				if (cub.cmap)
				{
				//	printf("height = %lu\twidth = %lu\n", cub.height, cub.width); //
				//	strtab_print(cub.cmap);
					int	tmp = check_map_edges(cub, cub.cmap); // 1 if ok
					printf("tmp = %d\n", tmp);
					strtab_print(cub.cmap);
					if (t_cub_set_imap(&cub, cub.cmap))
					{
						imap_print(cub, cub.imap);
					}
			//		strtab_print(cub.cmap);
			//		int	tmp = flood_fill(cub, cub.cmap,
			//			cub.player_pos.x, cub.player_pos.y);
			//		printf("\nflood_fill = %d\n", tmp);
					/////////////////////////////////
				}
			}
		//	t_cub_print(&cub);
		}
		t_cub_destroy(&cub);
	}
	else
		print_error(ERR_BADARG, NULL);
}