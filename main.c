/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:45 by eieong            #+#    #+#             */
/*   Updated: 2025/03/11 10:52:20 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	mlx_launch(t_game *game)
{
	xpm_to_image(game);
	image_to_window(game);
}

t_bool	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (false);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->width * TILE_SIZE), (game->height * TILE_SIZE), "So_long");
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		return (false);
	}
	return (true);
}*/

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"), 1);
	if (!check_filename(argv[1]))
		return (1);
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (ft_printf("Invalid file\n"), 1);
	if (!get_map(game))
		return (1);
	if (!check_walls(game, 0, 0))
		return (1);
	if (!is_map_valid(game))
		return (1);
	// if (!init_game(game))
	// 	return (1);
	// mlx_launch(game);
}
