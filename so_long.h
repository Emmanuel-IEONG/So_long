/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:30 by eieong            #+#    #+#             */
/*   Updated: 2025/03/11 15:05:36 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"
# include "libft/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
// # include <mlx.h>

# define TILE_SIZE 64

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_game
{
	char	**map;

	int		fd;
	int		width;
	int		height;
	t_pos	pos;
	int		collectibles_left;
	int		move_count;
	int		c_count;
	int		e_count;
	int		p_count;
	// t_xpm	xpm;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_game;

/*typedef struct s_xpm
{
	void	*collectibles;
	void	*exit;
	void	*floor;
	void	*player;
	void	*wall;
}			t_xpm;*/


t_bool	get_map(t_game *game);
t_bool	line_to_map(t_game *game, char *line);
t_bool	check_walls(t_game *game, int x, int y);
t_bool	check_filename(char *name);

t_bool	is_map_valid(t_game *game);
t_bool	check_char(t_game *game);
t_bool	char_count(t_game *game, int x, int y);
char	**dup_map(t_game *game);
void	flood_fill(char **map, t_pos pos, t_game *game);

void	clean_game(t_game *game);

void	ft_print_tab(char **tab);

#endif
