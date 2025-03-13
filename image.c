/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:31:49 by eieong            #+#    #+#             */
/*   Updated: 2025/03/13 15:32:24 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->xpm.wall, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->xpm.floor, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->xpm.exit, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->xpm.player, x * TILE_SIZE, y * TILE_SIZE);
		game->pos.x = x;
		game->pos.y = y;
	}
	if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->xpm.collectibles, x * TILE_SIZE, y * TILE_SIZE);
		game->collectibles_left++;
	}
}

void	img_to_window(t_game *game)
{
	int	x;
	int	y;

	game->collectibles_left = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x])
		{
			put_img_to_window(game, x, y);
			x++;
		}
		y++;
	}
	// display_move_count(game);
}

void	xpm_to_image(t_game *game)
{
	int	width;
	int	height;

	game->xpm.collectibles = mlx_xpm_file_to_image(game->mlx_ptr,
			"ikea/collectibles.xpm", &width, &height);
	game->xpm.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"ikea/exit.xpm", &width, &height);
	game->xpm.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"ikea/floor.xpm", &width, &height);
	game->xpm.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"ikea/player.xpm", &width, &height);
	game->xpm.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"ikea/wall_0.xpm", &width, &height);
	if (!game->xpm.collectibles || !game->xpm.exit || !game->xpm.floor
		|| !game->xpm.player || !game->xpm.wall)
		err_msg(9);
}
