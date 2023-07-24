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
		temp->coins--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_x = 1;
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

	temp.winsize->height = game->winsize->height;
	temp.winsize->width = game->winsize->width;
	temp.coins = game->coins;
	temp.winsize->x = game->winsize->x;
	temp.winsize->y = game->winsize->y;
	temp.exit_x = 0;
	temp.grid = (char **)malloc(sizeof(char *) * temp.winsize->height);
	if (!temp.grid)
		display_error("Memory allocation failed", true);
	i = 0;
	while (i < temp.winsize->height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	flood_fill(&temp, temp.winsize->y, temp.winsize->x);
	if (!(temp.exit_x == 1 && temp.coins == 0))
		display_error("No valid path available", true);
	free_grid(temp.grid, temp.winsize->height);
}
