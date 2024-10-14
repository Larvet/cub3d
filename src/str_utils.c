/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:30:03 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 10:47:19 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (str && str[i] == c);
}

int	str_isonly(const char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && is_in_str(set, str[i]))
		i++;
	return (str && i && !str[i]);
}

int	str_contains(const char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && !is_in_str(set, str[i]))
		i++;
	return (str[i]);
}

int	str_contains_n(const char *str, char *set)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		if (is_in_str(set, str[i]))
			count++;
		i++;
	}
	return (count);
}
