/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:42:08 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:42:08 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapDataInit2(t_main *mapData)
{
	mapData->collectibles = 0;
	mapData->num_of_players = 0;
	mapData->exit = 0;
	mapData->moves = 0;
	mapData->picWall = mlx_xpm_file_to_image(mapData->mlx, WALL, \
		&mapData->pic_width, &mapData->pic_height);
	mapData->picFloor = mlx_xpm_file_to_image(mapData->mlx, FLOOR, \
		&mapData->pic_width, &mapData->pic_height);
	mapData->picExit = mlx_xpm_file_to_image(mapData->mlx, EXIT, \
		&mapData->pic_width, &mapData->pic_height);
	mapData->picCollectible = mlx_xpm_file_to_image(mapData->mlx, COLLECTIBLE, \
		&mapData->pic_width, &mapData->pic_height);
}
t_main	*mapDataInit(void)
{
	t_main	*mapData;

	mapData = malloc(sizeof(t_main));
	if (!mapData)
		exit (ERROR);
	mapData->map = NULL;
	mapData->mlx = mlx_init();
	mapData->mlx_win = NULL;
	mapData->player = (t_player *)malloc(sizeof(t_player));
	if (!mapData->player)
	{
		free(mapData->mlx);
		free(mapData);
		exit (ERROR);
	}
	mapData->player->x = 0;
	mapData->player->y = 0;
	mapData->size_x = 0;
	mapData->size_y = 0;
	mapDataInit2(mapData);
	return (mapData);
}

void	freeMap(t_main *mapData)
{
	int	i;

	i = 0;
	while (i < mapData->size_y)
	{
		free(mapData->map[i]);
		i++;
	}
	free(mapData->map);
}

void	structFree(t_main *mapData)
{
	freeMap(mapData);
	free(mapData->mlx);
	mapData->mlx_win = NULL;
	mapData->size_x = 0;
	mapData->size_y = 0;
	mapData->collectibles = 0;
	mapData->num_of_players = 0;
	mapData->exit = 0;
	mapData->moves = 0;
	mapData->player->x = 0;
	mapData->player->y = 0;
	mapData->picWall = NULL;
	mapData->picFloor = NULL;
	mapData->picExit = NULL;
	mapData->picCollectible = NULL;
	mapData->pic_width = 0;
	mapData->pic_height = 0;
	free(mapData->player);
	free(mapData);
}

void	fillMapData(t_main *mapData, char *map)
{
	mapData->size_y = getMapHeight(map);
	mapData->size_x = getMapWidth(map);
	mapData->map = (char **)malloc(sizeof(char *) * (mapData->size_y + 1));
	if (!mapData->map)
	{
		structFree(mapData);
		exit(ERROR);
	}
	ft_bzero(mapData->map, (sizeof(char *) * (mapData->size_y + 1)));
}
