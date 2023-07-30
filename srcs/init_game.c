/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:55:22 by ihama             #+#    #+#             */
/*   Updated: 2023/07/28 22:26:36 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_width_and_height(t_game *game)
{
	game->width = 0;
	game->height = 0;
	while(game->grid[game->height])
		game->height++;
	while(game->grid[0][game->width])
		game->width++;
}

t_game	*initilize_data(t_game *game)
{
	get_width_and_height(game);
	game->img_size = 32;
	game->collect = count_rupees(game);
	return (game);
}
