/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:55:38 by ihama             #+#    #+#             */
/*   Updated: 2023/07/31 15:17:44 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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

void	error_message(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
