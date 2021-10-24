/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_and_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:52:30 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:52:30 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawMap(t_main *mapData)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (mapData->map[j])
	{
		i = 0;
		x = 0;
		while (mapData->map[j][i])
		{
			if (mapData->map[j][i] == 'P' || mapData->map[j][i] == '0')
				x = drawFloor(mapData, x, y);
			if (mapData->map[j][i] == '1')
				x = drawWall(mapData, x, y);
			if (mapData->map[j][i] == 'E')
				x = drawExit(mapData, x, y);
			if (mapData->map[j][i] == 'C')
				x = drawCollectibles(mapData, x, y);
			i++;
		}
		j++;
		y += 32;
	}
}

void	drawPlayer(t_main *mapData)
{
	void	*picPlayer;

	picPlayer = mlx_xpm_file_to_image(mapData->mlx, PLAYER, \
		&mapData->pic_width, &mapData->pic_height);
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, picPlayer, \
							mapData->player->x * 32, mapData->player->y * 32);
}
