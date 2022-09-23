/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:50:09 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/23 14:05:00 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void  *get_image(t_game *game, char *path)
{
  int x;
  int y;
  void *img;

  img = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
  if (img == NULL)
  {
    error("Image not found");
    exit(1);
  }
  return(img);
}

int config_game(t_game *game)
{
  game->mlx = mlx_init();
  game->window = mlx_new_window(game->mlx, game->columns, game->rows, "SO_LONG");
  game->player = get_image(game, PLAYER_RIGHT);
  game->floor = get_image(game, FLOOR);
  game->wall = get_image(game, WALL);
  game->coin = get_image(game, COIN);
  game->exit = get_image(game, EXIT_CLOSED);
  return(0);
}

void	put_image(int x, int y, t_game *game, void *img)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

void	change_player_image(t_game *game, char *new_image)
{
	mlx_destroy_image(game->mlx, game->player);
	game->player = get_image(game, new_image);
}