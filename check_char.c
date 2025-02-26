/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:03:06 by eieong            #+#    #+#             */
/*   Updated: 2025/02/26 17:48:36 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*only 1E, 1P and mini 1C (&'1'/'0') and nothing else = OK*/

/*E accessible from P ? flood fill algo*/
/*C accessible from P ?*/
/*flood fill algo : recursive
ft_fill */

void	char_count(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->c_count++;
	else if (game->map[y][x] == 'E')
		game->e_count++;
	else if (game->map[y][x] == 'P')
	{
		game->p_count++;
		game->x_pos = x;
		game->y_pos = y;
	}
	else if (game->map[y][x] != '0' && game->map[y][x] != '1')
		perror("Unauthorized char");
}

void	check_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			char_count(game, x, y);
			x++;
		}
		y++;
	}
	if (game->c_count < 1)
		perror("At least 1 collectible needed");
	if (game->e_count != 1)
		perror("Wrong number of exit");
	if (game->p_count != 1)
		perror("Wrong number of player");
}
