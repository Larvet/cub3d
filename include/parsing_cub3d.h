/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub3d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:56 by locharve          #+#    #+#             */
/*   Updated: 2024/10/07 09:31:05 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
# define PARSING_CUB3D_H

typedef struct s_str
{
	char	*str;
	struct s_str	*next;
}	t_str;

/* parsing_cub3d.c */
char	**strlist_to_tab(t_str *list);
t_str	*read_file(int fd);
char	**make_strtab_from_file(char *filename);

/* t_str_utils.c */
t_str	*t_str_new(char *str);
void	t_str_addback(t_str **list, t_str *node);
size_t	t_str_listsize(t_str *list);
void	strlist_free(t_str *list, int free_str);

/* error.c */
void	print_error(char *error, char *context);

#endif