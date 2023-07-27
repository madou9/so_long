/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:12:26 by ihama             #+#    #+#             */
/*   Updated: 2023/07/27 20:21:40 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
	t_game	*game;
	mlx_texture_t *xpm;
	mlx_image_t *img;

	// if (argc != 2)
	// 	error_message("please put one file");
	game = initilize_data();
	game->mlx = mlx_init(WIDTH * PIXEL,
			HEIGHT * PIXEL, "so_long", false);
	if (!game->mlx)
		return (FALSE);
	xpm = mlx_load_png("./assets/zenitsu.png");
	img = mlx_texture_to_image(game->mlx, xpm);
	printf("1\n");
	mlx_image_to_window(game->mlx, img, 32, 32);
	// mlx_key_hook(game->mlx, ft_hook, game->mlx);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
