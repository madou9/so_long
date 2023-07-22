/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:26:25 by ihama             #+#    #+#             */
/*   Updated: 2023/07/22 15:09:53 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_content_map(char **map)
{
	int		i;
	int		p;
	int		e;
	int		c;
	char	*row;

	i = 0;
	row = map[i];
	while (map[i])
	{
		while (*row)
		{
			if (*row == 'P')
				p++;
			else if (*row == 'C')
				c++;
			else if (*row == 'E')
				e++;
			else if (ft_strchr("01PCE", *row) == NULL)
				display_error("Map does not contain valid Characters", true);
			row++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		display_error("content of the map is not valid", true);
}

void	check_map_rectangle(char **map)
{
	size_t	first_row_len;
	size_t	i;

	i = 0;
	first_row_len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != first_row_len)
			display_error("damm your map is not rectangle", true);
		i++;
	}
}

void	check_empty_map(char **map)
{
	if (map[0] == NULL)
		display_error("dammm your map is empty", true);
}

void	display_error(const char *error_msg, bool exit_program)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (exit_program)
		exit(EXIT_FAILURE);
}
