/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocardos <jocardos@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:26:38 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/22 22:26:36 by jocardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int multiple_newline(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] == '\n' && str[i + 1] == '\n')
      return(error("Map is wrong. Fix to use it"));
    i++;
  }
  return(0);
}

char *read_file(int fd)
{
  char *map;
  char *reader;

  map = ft_strdup("");
  if (!map)
    return(NULL);
  while (42)
  {
    reader = get_next_line(fd);
    if (!reader)
      break;
    map = ft_strjoin(map, reader);
    free(reader); 
  }
  close(fd);
  if (!*map)
  {
    error("Map is empty");
    free(map);
    return(NULL);
  }
  return(map);
}

void  set_limits_for_map(t_game *game)
{
  size_t i;

  i = 0;
  while (game->map[i])
    i++;
  game->rows = i * PIXELS;
  game->columns = (ft_strlen(game->map[0])) * PIXELS;
}

char	**fill_map(t_game *game, char *map)
{
	char	**map_array;
	char	**map_array_copy;

	map_array = ft_split(map, '\n');
	map_array_copy = ft_split(map, '\n');
	game->map = map_array;
	game->map_copy = map_array_copy;
	return (map_array);
}

char **generate_map(t_game *game, char *path)
{
  int fd;
  char *map;
  char **tmp;
  
  if (!valid_file_extension(path))
    return (NULL);
  fd = open(path, O_RDONLY);
  if (fd == -1)
  {
    error("File not found");
    return (NULL);
  }
  map = read_file(fd);
  if (!map)
    return(NULL);
  if (multiple_newline(map))
  {
    free(map);
    return(NULL);
  }
  tmp = fill_map(game, map);
  free(map);
  set_limits_for_map(game);
  return(tmp);
  
}