/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:45 by eieong            #+#    #+#             */
/*   Updated: 2025/03/04 15:23:50 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_filename(char *name)
{
	if (ft_strlen(name) < 5)
	{
		perror("Invalid file name");
		exit(1);
	}
	name = name + (ft_strlen(name) - 4);
	if (ft_strncmp(name, ".ber", 4))
	{
		perror("Wrong file extension");
		exit(1);
	}
}
int	main(int argc, char **argv)
{
	t_game	*game;

	errno = 0;
	if (argc != 2)
	{
		perror("Wrong number of arguments");
		return (1);
	}
	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	check_filename(argv[1]);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		perror("Invalid file");
		return (1);
	}
	/*check_map.c*/
	get_map(game);
	/*valid path in map*/
	/*mlx init*/
}
