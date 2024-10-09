/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:23:29 by locharve          #+#    #+#             */
/*   Updated: 2024/10/09 11:07:20 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_empty_lines(char **strtab)
{
	int	i;

	i = 0;
	while (strtab && strtab[i] && str_isonly(strtab[i], WHITESPACES))
		i++;
	return (i);
}

static int	nswe_line_format(char *line, char *param_id)
{
	int	i;

	if (line && param_id && !ft_strncmp(line, param_id))
	{
		i = 2;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		while (ft_isascii(line[i]))
			i++;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		return (!line[i]);
	}
	return (0);
}

static int	color_format(char *line, char fc_id)
{
	int	i;

	if (line && *line == fc_id)
	{
		i = 1;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		while (ft_isdigit(line[i]))
			i++;
		while (is_in_str(WHITESPACES, line[i]))
			i++;
		return (!line[i]);
	}
	return (0);
}

int	check_map_format(char **strtab)
{
	int	i;
	int	pos_count;

	i = 0;
	pos_count = 0;
	while (strtab && strtab[i] && !str_isonly(strtab[i], WHITESPACES))
	{
		if (str_contains(strtab[i], "NSWE") && !pos_count)
			pos_count++;
		else if (pos_count || !str_isonly(strtab[i], "01 "))
			break ;
		i++;
	}
	i += skip_empty_lines(&strtab[i]);
	return (strtab && i && !strtab[i]);
}

int	check_format(char **av, char **strtab) // av == cub->param_id
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strtab && strtab[i] && av[j])
	{
		i += skip_empty_lines(&strtab[i]);
		if (!nswe_line_format(strtab[i], av[j]))
			return (0);
		i++;
		j++;
	}
	i += skip_empty_lines(&strtab[i]);
	if (!color_line_format(strtab[i], 'F'))
		return (0);
	i += skip_empty_lines(&strtab[i]);
	if (!color_line_format(strtab[i], 'C'))
		return (0);
	i += skip_empty_lines(&strtab[i]);
	if (!check_map_format(&strtab[i]))
		return (0);
	return (1);
}