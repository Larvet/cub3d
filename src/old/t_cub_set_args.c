/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cub_set_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:23:39 by locharve          #+#    #+#             */
/*   Updated: 2024/10/16 08:15:20 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	strcmp_tab(char *str, char **tab)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(tab[i]);
	while (str && tab && tab[i] && len && strncmp(str, tab[i], len))
	{
		i++;
		len = ft_strlen(tab[i]);
	}
	if (str && tab && tab[i] && ft_strlen(str) > len
		&& is_in_str(WHITESPACES, str[len]) >= 0)
		return (i);
	else
		return (-1);
}

int	is_tab_filled(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (tab && tab[i] && i < size)
		i++;
	return (i == size);
}

static int	t_cub_set_av(t_cub *cub, char **tab)
{
	char	**av_tab;
	int		av_id;
	int		i;
	
//	av_tab = strtab_init(6, "NO", "SO", "WE", "EA", "F", "C");
	av_tab = cub->param_id;
	if (av_tab)
	{
		i = 0;
		while (cub && tab && tab[i] && !is_tab_filled(cub->av, 6))
		{
			if (!str_isonly(tab[i], WHITESPACES))
			{
				av_id = strcmp_tab(tab[i], av_tab);
				if (av_id < 0)
					return (-1); // print_error
				cub->av[av_id] = ft_strdup(tab[i]);
				if (!cub->av[av_id])
					// error handling malloc
				tab[av_id] = "";
			}
			i++;
		}
		while (tab && tab[i] && str_isonly(tab[i], WHITESPACES))
			i++;
	}
	return (i * (tab[i] != NULL));
	// if error return 0 else return index of map
}

int	t_cub_set_map(t_cub *cub, char **tab, int i)
{
	int	size;
	int	bool_nswe;
	int	j;
	int	count_nswe;

	size = 0;
	nswe = 0;
	while (tab && tab[i + size])
		size++;
	while (size && tab && tab[i + size - 1]
		&& str_isonly(tab[i + size - 1], WHITESPACES))
		size--;
	if (!size)
		return (0); // error handling map not found
	cub->map = ft_calloc(size + 1, sizeof(char *));
	if (cub->map)
	{
		j = 0;
		while (j < size)
		{
			cub->map[j] = ft_strdup(tab[i + j])
			if (!cub->map[j])
				// error handling malloc

			/* Check plus tard ? après l'initialisation
			count_nswe = str_contains_n(tab[i + j], VALID_POS);
			if ((count_nswe && bool_nswe) || count_nswe > 1)
				// error handling multiple NSWE
			else if (count_nswe == 1)
				bool_nswe = 1;
			*/
			j++;
		}
	}
	else
		// error handling
	return (1);
}

int	t_cub_set_args(t_cub *cub, char **tab)
{
	int	map_index;
	// skip empty lines
	// set av[6]
	map_index = t_cub_set_av(cub, tab);
	if (map_index <= 0)
		// error handling av not found
	if (!t_cub_set_map(cub, tab, map_index))
		// error handling map not found
	// set map
	return (1); // all good
}