/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:55:22 by ihama             #+#    #+#             */
/*   Updated: 2023/08/02 16:42:20 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_width_and_height(t_game *game)
{
	game->width = 0;
	game->height = 0;
	while (game->grid[game->height])
		game->height++;
	while (game->grid[0][game->width])
		game->width++;
}

t_game	*initilize_data(t_game *game)
{
	get_width_and_height(game);
	game->img_size = 32;
	game->collect = count_rupees(game);
	game->collect_cpy = game->collect;
	return (game);
}

void	render_map(t_game *data)
{
	int		x;
	int		y;
	int		ax;
	int		ay;

	y = 0;
	ay = 0;
	while (y < data->height)
	{
		x = 0;
		ax = 0;
		while (x < data->width)
		{
			image_select(data, data->grid[y][x], ay, ax);
			x++;
			ax += data->img_size;
		}
		y++;
		ay += data->img_size;
	}
}
