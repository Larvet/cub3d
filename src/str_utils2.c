/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 06:30:49 by locharve          #+#    #+#             */
/*   Updated: 2024/10/14 10:55:31 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_incharset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && set && is_in_str(set, str[i]))
		i++;
	return (i);
}

int	skip_outcharset(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && set && !is_in_str(set, str[i]))
		i++;
	return (i);
}
