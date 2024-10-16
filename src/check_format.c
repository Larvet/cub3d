/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:23:29 by locharve          #+#    #+#             */
/*   Updated: 2024/10/16 08:11:41 by locharve         ###   ########.fr       */
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

	if (line && param_id && !ft_strncmp(line, param_id, 2))
	{
		i = 2;
		while (line[i] && is_in_str(WHITESPACES, line[i]) >= 0)
			i++;
		while (line[i] && ft_isascii(line[i]))
			i++;
		while (line[i] && is_in_str(WHITESPACES, line[i]) >= 0)
			i++;
		return (!line[i]);
	}
	return (0);
}

static int	color_line_format(char *line, char fc_id)
{
	int	i;
	int	count;

	if (line && *line == fc_id)
	{
		i = 1;
		count = 0;
		while (line[i])
		{
			while (line[i] && is_in_str(WHITESPACES, line[i]) >= 0)
				i++;
			count += ft_isdigit(line[i]) != 0;
			while (line[i] && ft_isdigit(line[i]))
				i++;
			while (line[i] && is_in_str(WHITESPACES, line[i]) >= 0)
				i++;
			i += line[i] == ',';
		}
		return (!line[i] && count == 3);
	}
	return (0);
}

int	check_map_format(char **strtab)
{
	int	i;
	int	pos_count;

	i = 0;
	pos_count = 0;
	while (strtab && strtab[i] && pos_count <= 1
		&& !str_isonly(strtab[i], WHITESPACES))
	{
		if (str_contains(strtab[i], "NSWE"))
			pos_count++;
		else if (!str_isonly(strtab[i], "01 \n"))
			break ;
		i++;
	}
	i += skip_empty_lines(&strtab[i]);
	return (strtab && i && !strtab[i] && pos_count == 1);
}

int	check_format(char **av, char **strtab)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (strtab && strtab[++i] && av[++j])
	{
		i += skip_empty_lines(&strtab[i]);
		if (!nswe_line_format(strtab[i], av[j]))
			return (1);
	}
	i += skip_empty_lines(&strtab[i]);
	if (!color_line_format(strtab[i], 'F'))
		return (2);
	i++;
	i += skip_empty_lines(&strtab[i]);
	if (!color_line_format(strtab[i], 'C'))
		return (2);
	i++;
	i += skip_empty_lines(&strtab[i]);
	if (!check_map_format(&strtab[i]))
		return (3);
	return (0);
}
