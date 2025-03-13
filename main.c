/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:45 by eieong            #+#    #+#             */
/*   Updated: 2025/03/13 15:32:25 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_game *game)
{
	if (key == 65307)
		clean_game(game);
	else
	{
		if (key == 119 || key == 65362)
			go_up(game);
		if (key == 115 || key == 65364)
			go_down(game);
		if (key == 97 || key == 65361)
			go_left(game);
		if (key == 100 || key == 65363)
			go_right(game);
		img_to_window(game);
		return (0);
	}
	return (0);
}

void	mlx_launch(t_game *game)
{
	xpm_to_image(game);
	img_to_window(game);
	mlx_key_hook(game->win_ptr, key_pressed, game);
	mlx_hook(game->win_ptr, 17, StructureNotifyMask, clean_game, game);
	mlx_loop(game->mlx_ptr);
}

t_bool	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (false);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->width * TILE_SIZE), (game->height * TILE_SIZE), "So_long");
	if (!game->win_ptr)
		return (free(game->mlx_ptr), false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (err_msg(1), 1);
	if (!check_filename(argv[1]))
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (perror("Error"), 1);
	ft_memset(game, 0, sizeof(t_game));
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (perror("Error"), clean_game(game), 1);
	if (!get_map(game))
		return (clean_game(game), 1);
	if (!check_walls(game, 0, -1))
		return (clean_game(game), 1);
	if (!is_map_valid(game))
		return (clean_game(game), 1);
	if (!init_game(game))
		return (clean_game(game), 1);
	mlx_launch(game);
	clean_game(game);
	return (0);
}
