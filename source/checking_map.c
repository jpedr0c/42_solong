/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:28:44 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/23 15:02:58 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void init_vars(t_game *game)
{
    game->finish_game = 0;
    game->count_players = 0;
    game->count_exits = 0;
    game->count_steps = 0;
    game->count_coins = 0;
    game->available_coins = 0;
    game->available_exits = 0;
}

void count_elements_in_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(game->map[i][j] == 'C')
                game->count_coins++;
            if(game->map[i][j] == 'E')
                game->count_exits++;
            if(game->map[i][j] == 'P')
            {
                game->player_x = i;
                game->player_y = j;
                game->count_players++;
            }
            j++;
        }
        i++;
    }
}

int rule_num_of_elements(t_game *game)
{
    if(game->count_players != 1 || game->count_exits != 1
        || game->count_coins < 1)
    {
        error("Needed exactly: 1 player, 1 exit and at least 1 coin");
        return (0);
    }
    return (1);
}

void count_available_elements(t_game *game, int px, int py)
{
    if (game->map_copy[px][py] == '1')
        return;
    if (game->map_copy[px][py] == 'E')
        game->available_exits++;
    if(game->map_copy[px][py] == 'C')
        game->available_coins++;
    game->map_copy[px][py] = '1';
    count_available_elements(game, px + 1, py);
    count_available_elements(game, px - 1, py);
    count_available_elements(game, px, py + 1);
    count_available_elements(game, px, py - 1);
}