/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:15:44 by ihama             #+#    #+#             */
/*   Updated: 2023/07/24 14:08:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	flood_fill(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->collect--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (flood_fill(temp, y + 1, x))
		return (1);
	if (flood_fill(temp, y - 1, x))
		return (1);
	if (flood_fill(temp, y, x + 1))
		return (1);
	if (flood_fill(temp, y, x - 1))
		return (1);
	return (0);
}

void	check_path(t_game *game)
{
	t_game	temp;
	size_t	i;

	temp.height = game->height;
	temp.width = game->width;
	temp.collect = game->collect;
	temp.link_x = game->link_x;
	temp.link_y = game->link_y;
	temp.exit = 0;
	temp.grid = (char **)malloc(sizeof(char *) * temp.height);
	if (!temp.grid)
		display_error("Memory allocation failed", true);
	i = 0;
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	flood_fill(&temp, temp.link_y, temp.link_x);
	if (!(temp.exit == 1 && temp.collect == 0))
		display_error("No valid path available", true);
	free_grid(temp.grid, temp.height);
}
