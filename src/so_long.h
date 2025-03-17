/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:22:30 by eieong            #+#    #+#             */
/*   Updated: 2025/03/17 15:04:11 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/ft_printf.h"
# include "../mlx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>

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

typedef struct s_xpm
{
	void	*collectibles;
	void	*exit;
	void	*floor;
	void	*player;
	void	*wall;
}			t_xpm;

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
	t_xpm	xpm;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_game;

t_bool	get_map(t_game *game);
t_bool	line_to_map(t_game *game, char *line);
t_bool	check_walls(t_game *game, int x, int y);
t_bool	check_filename(char *name);
t_bool	check_map_size(t_game *game);

t_bool	is_map_valid(t_game *game);
t_bool	check_char(t_game *game);
t_bool	char_count(t_game *game, int x, int y);
char	**dup_map(t_game *game);
void	flood_fill(char **map, t_pos pos, t_game *game);

void	put_img_to_window(t_game *game, int x, int y);
void	img_to_window(t_game *game);
void	xpm_to_image(t_game *game);
// void	moves_to_window(t_game *game);

void	go_up(t_game *game);
void	go_down(t_game *game);
void	go_left(t_game *game);
void	go_right(t_game *game);
t_bool	can_move(t_game *game, int x, int y);

int		clean_game(t_game *game);
void	err_msg(int err);

#endif
