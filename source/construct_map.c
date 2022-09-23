/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:50:50 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/23 17:12:23 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	valid_file_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".ber", 4) != 0)
	{
		error("Invalid file extension. Accepted extension is .ber");
		return (0);
	}
	return (1);
}

void	set_characters(t_game *game, int x, int y)
{
	if (game->map[x][y] == '1')
		put_image(y * PIXELS, x * PIXELS, game, game->wall);
	if (game->map[x][y] == '0')
		put_image(y * PIXELS, x * PIXELS, game, game->floor);
	if (game->map[x][y] == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		put_image(y * PIXELS, x * PIXELS, game, game->player);
	}
	if (game->map[x][y] == 'E')
		put_image(y * PIXELS, x * PIXELS, game, game->exit);
	if (game->map[x][y] == 'C')
		put_image(y * PIXELS, x * PIXELS, game, game->coin);
}

int	construct_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			set_characters(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
