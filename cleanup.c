/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:34:12 by eieong            #+#    #+#             */
/*   Updated: 2025/03/06 12:46:37 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*free mlx, map, close fd*/
void	clean_game(t_game *game)
{
	if (game->map != NULL)
		ft_freetab(game->map);
	if (game->fd != -1)
		close(game->fd);
	free(game);
}
