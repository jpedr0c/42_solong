/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:16:18 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/23 17:20:07 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		error("Incorrect arguments\n");
		error("Usage: ./so_long maps/<map>.ber");
	}
	game.map = generate_map(&game, argv[1]);
	if (!game.map)
		return (0);
	if (!check_valid_map(&game))
	{
		free_map(game.map);
		return (error("Provide a valid map"));
	}
	config_game(&game);
	construct_map(&game);
	mlx_hook(game.window, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.window, 17, 1L << 2, close_game, &game);
	mlx_loop_hook(game.mlx, &construct_map, &game);
	mlx_loop(game.mlx);
	return (0);
}
