/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:31:49 by eieong            #+#    #+#             */
/*   Updated: 2025/03/07 11:48:27 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_image(t_game *game)
{
	int	width;
	int	height;

	game->xpm.collectibles = mlx_xpm_file_to_image(game->mlx_ptr,
		"PATH", &width, &height);
	game->xpm.exit = mlx_xpm_file_to_image(game->mlx_ptr,
		"PATH", &width, &height);
	game->xpm.floor = mlx_xpm_file_to_image(game->mlx_ptr,
		"PATH", &width, &height);
	game->xpm.player = mlx_xpm_file_to_image(game->mlx_ptr,
		"PATH", &width, &height);
	game->xpm.wall = mlx_xpm_file_to_image(game->mlx_ptr,
		"PATH", &width, &height);
	if (!game->xpm.collectibles || !game->xpm.exit ||
		!game->xpm.floor || !game->xpm.player || !game->xpm.wall)
	{
		ft_printf("Error loadng image\n");
	}
}
