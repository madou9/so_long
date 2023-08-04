/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:12:26 by ihama             #+#    #+#             */
/*   Updated: 2023/08/04 16:21:48 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int32_t	start_game(t_game *game)
{
	initilize_data(game);
	game->mlx = mlx_init(game->width * game->img_size,
			game->height * game->img_size, "so_long", false);
	if (!(game->mlx))
		return (EXIT_FAILURE);
	get_texture(game);
	get_image(game);
	resize_image(game);
	fill_background(game);
	render_map(game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->textu);
	free(game->imag);
	return (EXIT_SUCCESS);
}
