/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub3d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 07:56:56 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 12:08:00 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
# define PARSING_CUB3D_H

/* check_format.c */
int		skip_empty_lines(char **strtab);
// int	nswe_line_format(char *line, char *param_id);
// int	color_line_format(char *line, char fc_id);
int		check_map_format(char **strtab);
int		check_format(char **av, char **strtab);

/* chek_map_edges.c */
int		flood_fill(t_cub cub, char **map, int x, int y);
int		check_map_edges(t_cub cub, char **map);

/* error.c */
void	print_error(char *error, char *context);
void	print_format_error(int check);

/* flood_fill.c */
int		flood_fill(t_cub cub, char **map, int px, int py);

/* smooth_map.c */
char	*ft_strcpy_fill(char *dst, char *src, size_t len, char fill);
char	**make_map_rectangle(char **dst, char **src, size_t max_len);
void	set_pos(t_pos *player_pos, char **map);
char	**smooth_map(t_cub *cub, char **raw);

/* str_utils.c */
int		is_in_str(char *str, char c);
int		str_isonly(const char *str, char *set);
int		str_contains(const char *str, char *set);
int		str_contains_n(const char *str, char *set);

/* str_utils2.c */
int	skip_incharset(char *str, char *set);
int	skip_outcharset(char *str, char *set);

/* strtab_utils.c */
size_t	strtab_max_len(char **strtab);
size_t	strtab_size(char **tab);
size_t	strtab_print(char **tab);
void	strtab_free(char **strtab);
char	**strtab_init(size_t size, ...);

/* t_cub_make_strtab_from_file.c */
char	**strlist_to_tab(t_str *list);
t_str	*read_file(int fd);
int		t_cub_make_strtab_from_file(t_cub *cub, char *filename);

/* t_cub_set_args.c */
// int	t_cub_set_paths(t_cub *cub, char **strtab);
// int	atoi_rgb(int *rgb, char *str);
// int	t_cub_set_rgb(t_cub *cub, char **strtab);
// int	t_cub_set_map(t_cub *cub, char **strtab);
int		t_cub_set_args(t_cub *cub, char **strtab);

/* t_cub_set_imap.c */
void	imap_print(t_cub cub, int **map);
void	intptrtab_free(int **tab);
int		*set_inttab(t_cub *cub, char *line);
int		t_cub_set_imap(t_cub *cub, char **cmap);

/* t_cub_set_rgb.c */
// int	atoi_rgb(int *rgb, char *str);
// int	t_cub_set_each_color(t_cub *cub, char *str, t_color_id c_id);
int	t_cub_set_rgb(t_cub *cub, char **strtab);

/* t_cub.c */
int		t_cub_init(t_cub *cub);
void	print_rgb(int rgb[2][3]);
void	t_cub_print(t_cub *cub);
void	t_cub_destroy(t_cub *cub);

/* t_str_utils.c */
t_str	*t_str_new(char *str);
void	t_str_addback(t_str **list, t_str *node);
size_t	t_str_listsize(t_str *list);
void	strlist_free(t_str *list, int free_str);

#endif