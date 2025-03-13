/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:55 by eieong            #+#    #+#             */
/*   Updated: 2025/03/13 15:32:32 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	can_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectibles_left != 0)
			return (false);
		game->move_count++;
		ft_printf("\nGG, you won with %d moves!\n", game->move_count);
		clean_game(game);
	}
	if (game->map[y][x] == 'C' || game->map[y][x] == '0')
	{
		if (game->map[y][x] == 'C')
			game->collectibles_left--;
		game->move_count++;
		game->map[y][x] = 'P';
		game->pos.x = x;
		game->pos.y = y;
	}
	return (true);
}

void	go_up(t_game *game)
{
	int	x;
	int	y;

	x = game->pos.x;
	y = game->pos.y;
	y--;
	if (game->map[y][x] == '1')
		return ;
	if (!can_move(game, x, y))
		return ;
	game->map[y + 1][x] = '0';
	ft_printf("You made %d moves.\n", game->move_count);
}

void	go_down(t_game *game)
{
	int	x;
	int	y;

	x = game->pos.x;
	y = game->pos.y;
	y++;
	if (game->map[y][x] == '1')
		return ;
	if (!can_move(game, x, y))
		return ;
	game->map[y - 1][x] = '0';
	ft_printf("You made %d moves.\n", game->move_count);
}

void	go_left(t_game *game)
{
	int	x;
	int	y;

	x = game->pos.x;
	y = game->pos.y;
	x--;
	if (game->map[y][x] == '1')
		return ;
	if (!can_move(game, x, y))
		return ;
	game->map[y][x + 1] = '0';
	ft_printf("You made %d moves.\n", game->move_count);
}

void	go_right(t_game *game)
{
	int	x;
	int	y;

	x = game->pos.x;
	y = game->pos.y;
	x++;
	if (game->map[y][x] == '1')
		return ;
	if (!can_move(game, x, y))
		return ;
	game->map[y][x - 1] = '0';
	ft_printf("You made %d moves.\n", game->move_count);
}
