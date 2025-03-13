/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:34:12 by eieong            #+#    #+#             */
/*   Updated: 2025/03/13 15:32:21 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(int err)
{
	ft_printf("Error\n");
	if (err == 1)
		ft_printf("Wrong number of arguments\n");
	if (err == 2)
		ft_printf("Invalid file name\n");
	if (err == 3)
		ft_printf("Wrong file extension\n");
	if (err == 4)
		ft_printf("Map empty\n");
	if (err == 5)
		ft_printf("Invalid map\n");
	if (err == 6)
		ft_printf("Map must be surrouded by walls\n");
	if (err == 7)
		ft_printf("Map must be a rectangle\n");
	if (err == 8)
		ft_printf("Can't reach C or E\n");
	if (err == 9)
		ft_printf("Can't load image\n");
}

int	clean_game(t_game *game)
{
	if (game->xpm.wall)
		mlx_destroy_image(game->mlx_ptr, game->xpm.wall);
	if (game->xpm.floor)
		mlx_destroy_image(game->mlx_ptr, game->xpm.floor);
	if (game->xpm.player)
		mlx_destroy_image(game->mlx_ptr, game->xpm.player);
	if (game->xpm.collectibles)
		mlx_destroy_image(game->mlx_ptr, game->xpm.collectibles);
	if (game->xpm.exit)
		mlx_destroy_image(game->mlx_ptr, game->xpm.exit);
	if (game->map != NULL)
		ft_freetab(game->map);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->fd != -1)
		close(game->fd);
	free(game);
	exit(0);
	return (0);
}
