/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:55:38 by ihama             #+#    #+#             */
/*   Updated: 2023/07/19 17:32:49 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_empty_line(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' || map[i + 1] == '\n')
			display_error("Error empty line", true);
		i++;
	}
}

bool	check_ber(char *file)
{
	size_t	i;

	i = 0;
	while (file[i])
		i++;
	while (i)
	{
		if (file[i] == '.' && file[i + 1] == 'b' && \
			file[i + 2] == 'e' && file[i + 3] == 'r')
			return (true);
		i--;
	}
	return (false);
}
