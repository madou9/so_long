/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:54:49 by ihama             #+#    #+#             */
/*   Updated: 2023/07/28 13:25:48 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *game)
{
	if (game->grid[game->imag->player->instances->y / 32 -1]
		[game->imag->player->instances->x / 32] != '1')
	{
		game->imag->player->instances->y -= 32;
		game->move_count++;
	}
}


void	my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE))
		mlx_close_window(game->mlx);
}
