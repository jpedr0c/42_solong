/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:11:14 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/23 17:12:09 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error(char *error)
{
	ft_printf("\e[31mError: %s\e[0m\n", error);
	return (1);
}

void	message_finish_game(void)
{
	ft_printf("\n\t\e[42;1;37mYOU WIN 🏆\e[0m\n");
	ft_printf("\n\e[1;97mPress ESC or click in X button to close game.\e[0m\n\n");
}

void	print_steps(t_game *game)
{
	game->count_steps++;
	ft_printf("\e[3;95mSteps:\e[0m\e[1;96m %d\e[0m\n", game->count_steps);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	free_map(game->map);
	free_map(game->map_copy);
	exit(0);
	return (0);
}
