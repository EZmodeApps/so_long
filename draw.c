/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:49:17 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:49:17 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drawFloor(t_main *mapData, int x, int y)
{
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, \
		mapData->picFloor, x, y);
	x += 32;
	return (x);
}

int	drawWall(t_main *mapData, int x, int y)
{
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, \
		mapData->picFloor, x, y);
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, \
		mapData->picWall, x, y);
	x += 32;
	return (x);
}

int	drawExit(t_main *mapData, int x, int y)
{
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, \
		mapData->picFloor, x, y);
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, \
		mapData->picExit, x, y);
	x += 32;
	return (x);
}

int	drawCollectibles(t_main *mapData, int x, int y)
{
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, \
		mapData->picFloor, x, y);
	mlx_put_image_to_window(mapData->mlx, mapData->mlx_win, \
		mapData->picCollectible, x, y);
	x += 32;
	return (x);
}
