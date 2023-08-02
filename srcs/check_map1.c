/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:55:38 by ihama             #+#    #+#             */
/*   Updated: 2023/08/02 17:39:39 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_ber(char *map_file)
{
	char	*file_extension;
	int		i;
	int		map_file_length;

	i = 0;
	file_extension = ".ber";
	map_file_length = ft_strlen(map_file);
	if (map_file_length < 4)
		error_message("Error: Invalid file name");
	map_file += map_file_length - 4;
	while (map_file[i])
	{
		if (map_file[i] != file_extension[i])
			error_message("Error: Not a .ber file");
		i++;
	}
}

int	check_rectangle_map(char *map)
{
	char	**map_sketch;
	size_t	reference;
	int		i;
	int		j;

	map_sketch = ft_split(map, '\n');
	i = count_line(map_sketch);
	reference = ft_strlen(map_sketch[0]);
	j = 0;
	while (j < i)
	{
		if (ft_strlen(map_sketch[j]) != reference)
		{
			free_map(map_sketch);
			error_message("Error :check rectangle map");
			return (TRUE);
		}
		j++;
	}
	free_map(map_sketch);
	return (0);
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = count_line(game->grid) - 1;
	len = ft_strlen(game->grid[0]);
	while (i < len)
	{
		if (game->grid[0][i] != '1' || game->grid[j][i] != '1')
			error_message("Top or bottom border is not valid.");
		i++;
	}
	j = -1;
	while (++j < count_line(game->grid) - 1)
	{
		if (game->grid[j][0] != '1' || game->grid[j][len - 1] != '1')
			error_message("Left or right border is not valid.");
	}
}
