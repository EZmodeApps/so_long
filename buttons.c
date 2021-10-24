/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:47:18 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:47:18 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	W_is_pressed(t_main *mapData)
{
	if (mapData->map[mapData->player->y - 1][mapData->player->x] != '1')
	{
		if (mapData->map[mapData->player->y - 1][mapData->player->x] == 'C')
		{
			mapData->map[mapData->player->y - 1][mapData->player->x] = '0';
			mapData->collectibles--;
		}
		if (mapData->collectibles == 0
			&& mapData->map[mapData->player->y - 1][mapData->player->x] == 'E')
		{
			mlx_clear_window(mapData->mlx, mapData->mlx_win);
			mlx_destroy_window(mapData->mlx, mapData->mlx_win);
			structFree(mapData);
			exit(SUCCESS);
		}
		mapData->player->y -= 1;
		mapData->moves++;
	}
}

void	S_is_pressed(t_main *mapData)
{
	if (mapData->map[mapData->player->y + 1][mapData->player->x] != '1')
	{
		if (mapData->map[mapData->player->y + 1][mapData->player->x] == 'C')
		{
			mapData->map[mapData->player->y + 1][mapData->player->x] = '0';
			mapData->collectibles--;
		}
		if (mapData->collectibles == 0
			&& mapData->map[mapData->player->y + 1][mapData->player->x] == 'E')
		{
			mlx_clear_window(mapData->mlx, mapData->mlx_win);
			mlx_destroy_window(mapData->mlx, mapData->mlx_win);
			structFree(mapData);
			exit(SUCCESS);
		}
		mapData->player->y += 1;
		mapData->moves++;
	}
}

void	D_is_pressed(t_main *mapData)
{
	if (mapData->map[mapData->player->y][mapData->player->x + 1] != '1')
	{
		if (mapData->map[mapData->player->y][mapData->player->x + 1] == 'C')
		{
			mapData->map[mapData->player->y][mapData->player->x + 1] = '0';
			mapData->collectibles--;
		}
		if (mapData->collectibles == 0
			&& mapData->map[mapData->player->y][mapData->player->x + 1] == 'E')
		{
			mlx_clear_window(mapData->mlx, mapData->mlx_win);
			mlx_destroy_window(mapData->mlx, mapData->mlx_win);
			structFree(mapData);
			exit(SUCCESS);
		}
		mapData->player->x += 1;
		mapData->moves++;
	}
}

void	A_is_pressed(t_main *mapData)
{
	if (mapData->map[mapData->player->y][mapData->player->x - 1] != '1')
	{
		if (mapData->map[mapData->player->y][mapData->player->x - 1] == 'C')
		{
			mapData->map[mapData->player->y][mapData->player->x - 1] = '0';
			mapData->collectibles--;
		}
		if (mapData->collectibles == 0
			&& mapData->map[mapData->player->y][mapData->player->x - 1] == 'E')
		{
			mlx_clear_window(mapData->mlx, mapData->mlx_win);
			mlx_destroy_window(mapData->mlx, mapData->mlx_win);
			structFree(mapData);
			exit(SUCCESS);
		}
		mapData->player->x -= 1;
		mapData->moves++;
	}
}

