/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:35:29 by ihama             #+#    #+#             */
/*   Updated: 2023/07/28 21:04:07 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_image(t_game *game)
{
	game->imag = ft_calloc(1, sizeof(t_images));
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->player = mlx_texture_to_image(game->mlx, game->textu->player);
	game->imag->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	game->imag->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->player);
	mlx_delete_texture(game->textu->collec);
	mlx_delete_texture(game->textu->exit);
	mlx_delete_texture(game->textu->exit_2);
}

void	get_texture(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures));
	game->textu->wall = mlx_load_png("../resources/background.png");
	game->textu->floor = mlx_load_png("../textures/floor.png");
	game->textu->player = mlx_load_png("../textures/Mago.png");
	game->textu->collec = mlx_load_png("../textures/spark21.png");
	game->textu->exit = mlx_load_png("../textures/salida.png");
	game->textu->exit_2 = mlx_load_png("../textures/salida2.png");
}

void	image_select(t_game *data, size_t y, size_t x)
{
	size_t	img_size;

	img_size = 32;
	if (data->grid[y][x] == '1')
		printf("data->image_select = %d\n", data->height);
		if (mlx_image_to_window(data->mlx, data->imag->floor,
				x * 32, y * 32) < 0)
			error_message("Failed to put image to window");
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->imag->collec,
				x * 32 + img_size / 2, y * 32 + img_size / 2) < 0)
			error_message("Failed to put image to window");
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->imag->player,
				x * 32, y * 32) < 0)
			error_message("Failed to put image to window");
	if (data->grid[y][x] == 'E')
		if ((mlx_image_to_window(data->mlx, data->imag->exit,
				x * 32, y * 32) < 0) &&
			mlx_image_to_window(data->mlx, data->imag->exit_2,
				x * 32, y * 32))
			error_message("Failed to put image to window");
}

void	render_map(t_game *data)
{
	int		x;
	int		y;
	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		printf("data->height = %d\n", data->height);
		while (x < data->width)
		{
			image_select(data, y, x);
			printf("data->height = %d\n", data->height);
			x++;
		}
		y++;
	}
}

// void	put_img_floor(t_game *game, t_images *image)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (game->mapcopy[x])
// 	{
// 		printf("put_img_floor\n");
// 		y = 0;
// 		while (game->mapcopy[x][y])
// 		{
// 			mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
// 			if (game->mapcopy[x][y] == '1')
// 				mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
// 			else if (game->mapcopy[x][y] == 'E')
// 			{
// 				mlx_image_to_window(game->mlx, image->exit, x * 32, y * 32);
// 				mlx_image_to_window(game->mlx, image->exit_2, x * 32, y * 32);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	put_img_map(t_game *game, t_images *image)
// {
// 	int	x;
// 	int	y;

// 	put_img_floor(game, image);
// 	y = 0;
// 	while (game->mapcopy[y])
// 	{
// 		printf("put_img_map\n");
// 		x = 0;
// 		while (game->mapcopy[y][x])
// 		{
// 			if (game->mapcopy[y][x] == 'C')
// 				mlx_image_to_window(game->mlx, image->collec, x * 32, y * 32);
// 			if (game->mapcopy[y][x] == 'P')
// 				mlx_image_to_window(game->mlx, image->player, x * 32, y * 32);
// 			x++;
// 		}
// 		y++;
// 	}
// }
