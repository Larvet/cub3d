/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:10 by locharve          #+#    #+#             */
/*   Updated: 2024/10/10 11:57:52 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**strlist_to_tab(t_str *list)
{
	char	**tab;
	t_str	*head;
	size_t	list_size;
	size_t	i;

	head = list;
	list_size = t_str_listsize(list);
	tab = ft_calloc(list_size + 1, sizeof(char *));
	if (tab)
	{
		i = 0;
		while (i < list_size && list)
		{
			tab[i] = list->str;
			list = list->next;
			i++;
		}
	}
	else
		print_error(ERR_MALLOC, "strlist_to_tab");
	list = head;
	return (tab);
}

t_str	*read_file(int fd)
{
	t_str	*strlist;
	t_str	*tmp;
	char	*line;

	strlist = NULL;
	line = NULL;
	if (fd != -1)
	{
		line = get_next_line(fd);
		while (line)
		{
			tmp = t_str_new(line);
			if (!tmp)
				break ;
			t_str_addback(&strlist, tmp);
			line = get_next_line(fd);
		}
		if (line)
		{
			strlist_free(strlist, 1);
			strlist = NULL;
			free(line);
		}
	}
	return (strlist);
}

static int	extension_check(char *filename, char *ext)
{
	char	*ptr;

	ptr = ft_strrchr(filename, '.');
	if (!ptr || ft_strncmp(ptr, ext, ft_strlen(ext)))
		return (0);
	return (1);
}

char	**make_strtab_from_file(char *filename)
{
	char	**tab;
	t_str	*strlist;
	int		fd;

	tab = NULL;
	strlist = NULL;
	if (!extension_check(filename, ".cub"))
	{
		print_error(ERR_BADEXT, NULL); ///
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		strlist = read_file(fd);
		if (strlist)
		{
			tab = strlist_to_tab(strlist);
			strlist_free(strlist, 0);
		}
		close(fd);
	}
	else
		print_error(ERR_FILEOP, filename);
	return (tab);
}