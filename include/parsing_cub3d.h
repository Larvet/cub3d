/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub3d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:56 by locharve          #+#    #+#             */
/*   Updated: 2024/10/10 10:33:36 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
# define PARSING_CUB3D_H

/* check_format.c */
int	skip_empty_lines(char **strtab);
// int	nswe_line_format(char *line, char *param_id);
// int	color_line_format(char *line, char fc_id);
int	check_map_format(char **strtab);
int	check_format(char **av, char **strtab);

/* error.c */
void	print_error(char *error, char *context);

/* parsing_cub3d.c */
char	**strlist_to_tab(t_str *list);
t_str	*read_file(int fd);
char	**make_strtab_from_file(char *filename);

/* str_utils.c */
int	is_in_str(char *str, char c);
int	str_isonly(const char *str, char *set);
int	str_contains(const char *str, char *set);
int	str_contains_n(const char *str, char *set);

/* strtab_utils.c */
void	strtab_free(char **strtab);
char	**strtab_init(size_t size, ...);

/* t_cub_set_args.c */
int	skip_incharset(char *str, char *set);
int	skip_outcharset(char *str, char *set);
// int	t_cub_set_paths(t_cub *cub, char **strtab);
// int	atoi_rgb(int *rgb, char *str);
// int	t_cub_set_rgb(t_cub *cub, char **strtab);
// int	t_cub_set_map(t_cub *cub, char **strtab);
int	t_cub_set_args(t_cub *cub, char **strtab);

/* t_cub.c */
int	t_cub_init(t_cub *cub);
void	t_cub_destroy(t_cub *cub);

/* t_str_utils.c */
t_str	*t_str_new(char *str);
void	t_str_addback(t_str **list, t_str *node);
size_t	t_str_listsize(t_str *list);
void	strlist_free(t_str *list, int free_str);

#endif