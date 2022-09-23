/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:05:45 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/23 15:30:02 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_invalid_char(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (!ft_strchr("PEC01", game->map[i][j]))
                return(error("Invalid character found in map"));
            j++;
        }
        i++;
    }
    return(0);
}

int verify_rectangle(t_game *game)
{
    int i;
    int init_cols;
    int current_cols;

    i = 0;
    init_cols = game->columns /PIXELS;
    while (i < (game->rows / PIXELS))
    {
        current_cols = ft_strlen(game->map[i]);
        if (current_cols != init_cols)
        {
            error("Map should be rectangle");
            return (0);
        }
        i++;
    }
    return(i);
}

int walls_around_map(t_game *game)
{
    int i;
    int j;
    int rows;
    int cols;

    i = 0;
    j = 0;
    rows = (game->rows / PIXELS) - 1;
    cols = (game->columns / PIXELS) - 1;
    while (game->map[i][0] == '1' && game->map[i][cols] == '1' && i < rows)
        i++;
    while (game->map[0][j] == '1' && game->map[rows][i] == '1' && j <= cols)
        j++;
    if (i != rows || j - 1 != cols)
    {
        error("Map must be surrounded by walls");
        return(0);
    }
    return(1);
}

int checking_valid_path(t_game *game, int px, int py)
{
    count_available_elements(game, px, py);
    if (game->count_coins != game->available_coins)
    {
        error("Map must contain a valid path");
        return (0);
    }
    if (game->count_exits != game->available_exits)
    {
        error("Map must contain a valid path");
        return (0);
    }
    return(1);
}

int check_valid_map(t_game *game)
{
    init_vars(game);
}