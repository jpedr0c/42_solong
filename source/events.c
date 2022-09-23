/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:52:39 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/23 14:25:35 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void collected_coins(t_game *game)
{
    game->count_coins--;
    game->collected++;
    ft_printf("\e[1;93mCoins:\e[0m\e[1;97m %d💰\e[0m\n", game->collected);
    if (game->count_coins == 0)
    {
        mlx_destroy_image(game->mlx, game->exit);
	    game->exit = get_image(game, EXIT_OPEN);
    }
}

int player_can_move(t_game *game, int x, int y)
{
    if (game->map[x][y] == '1')
        return(0);
    if (game->map[x][y] == 'E' && game->count_coins != 0)
        return(0);
    return(1);
}

void	move_player(t_game *game, int new_x_pos, int new_y_pos)
{
	int	prev_x_pos;
	int	prev_y_pos;

	prev_x_pos = game->player_x;
	prev_y_pos = game->player_y;
	if (!player_can_move(game, new_x_pos, new_y_pos))
		return ;
	if (game->map[new_x_pos][new_y_pos] == 'C')
		collected_coins(game);
	if (game->map[new_x_pos][new_y_pos] == 'E')
		game->finish_game = 1;
	game->player_x = new_x_pos;
	game->player_y = new_y_pos;
	game->map[prev_x_pos][prev_y_pos] = '0';
	if (!game->finish_game)
		game->map[new_x_pos][new_y_pos] = 'P';
	print_steps(game);
	if (game->finish_game)
		message_finish_game();
}

void	move(int keycode, t_game *game)
{
	if (game->finish_game)
		return ;
	if (keycode == KEY_UP)
		move_player(game, game->player_x - 1, game->player_y);
	if (keycode == KEY_DOWN)
		move_player(game, game->player_x + 1, game->player_y);
	if (keycode == KEY_LEFT)
	{
		change_player_image(game, PLAYER_LEFT);
		move_player(game, game->player_x, game->player_y - 1);
	}
	if (keycode == KEY_RIGHT)
	{
		change_player_image(game, PLAYER_RIGHT);
		move_player(game, game->player_x, game->player_y + 1);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (close_game(game));
	move(keycode, game);
	return (0);
}