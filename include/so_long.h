/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:20:41 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/22 22:39:04 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/include/libft.h"
# include "../libraries/libft/include/ft_printf.h"
# include "../libraries/libft/include/get_next_line.h"
# include "../libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define WALL "./images/WALL.xpm"
# define FLOOR "./images/FLOOR.xpm"
# define COIN "./images/COIN.xpm"
# define EXIT_OPEN "./images/EXIT_OPEN.xpm"
# define EXIT_CLOSED "./images/EXIT_CLOSED.xpm"
# define PLAYER_RIGHT "./images/PLAYER_R.xpm"
# define PLAYER_LEFT "./images/PLAYER_L.xpm"

# define PIXELS 63

// For Linux
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_ESC 65307
# define KEY_RESTART 15

// For MAC
// # define KEY_UP 13
// # define KEY_DOWN 1
// # define KEY_LEFT 0
// # define KEY_RIGHT 2
// # define KEY_ESC 53
// # define KEY_RESTART 15

// typedef struct s_player
// {
// 	int			x_pos;
// 	int			y_pos;
// }				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*player;
	void		*floor;
	void		*wall;
	void		*coin;
	void		*exit;
	char		**map;
	char		**map_copy;
	int			count_steps;
	int			count_coins;
	// int			reachable_collectibles_count;
	int			count_players;
	int			count_exits;
	// int			reachable_exits_count;
	int			finish_game;
	int			columns;
	int			rows;
	int			player_x;
	int			player_y;
	// t_player	person;
}				t_game;

// SO_LONG
int main(int argc, char **argv);

// UTILS
int error(char *error);
void message_finish_game(void);
void print_steps(t_game *game);
void free_map(char **map);
int close_game(t_game *game);

// CONFIGURATION
void  *get_image(t_game *game, char *path);
int config_game(t_game *game);
void	put_image(int x, int y, t_game *game, void *img);
void	change_exit_image(t_game *game, char *new_image);

//CONSTRUCT MAP
int valid_file_extension(char *path);
void set_characters(t_game *game, int x, int y);
int construct_map(t_game *game);

//GENERATE MAP
int multiple_newline(char *str);
char *read_file(int fd);
void  set_limits_for_map(t_game *game);
char **generate_map(t_game *game, char *path);

#endif