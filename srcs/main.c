/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:12:26 by ihama             #+#    #+#             */
/*   Updated: 2023/07/28 22:31:11 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	valide_mlx_game(t_game *game)
{
	printf("1\n");
	initilize_data(game);
	game->mlx = mlx_init(game->width * game->img_size,
			game->height * game->img_size, "so_long", false);
	if (!(game->mlx))
		error();
	get_texture(game);
	get_image(game);
	resize_image(game);
	render_map(game);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->textu);
	free(game->imag);
	return (EXIT_SUCCESS);
}
