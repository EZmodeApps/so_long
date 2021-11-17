/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caniseed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:32:46 by caniseed          #+#    #+#             */
/*   Updated: 2021/10/24 20:22:31 by caniseed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locatePlayer(t_main *mapData)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapData->map[i])
	{
		while (mapData->map[i][j])
		{
			if (mapData->map[i][j] == 'P')
			{
				mapData->player->x = j;
				mapData->player->y = i;
				mapData->num_of_players++;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int	key_hook(int keycode, t_main *mapData)
{
	if (keycode == ESC)
	{
		mlx_clear_window(mapData->mlx, mapData->mlx_win);
		mlx_destroy_window(mapData->mlx, mapData->mlx_win);
		structFree(mapData);
		exit(SUCCESS);
	}
	if (keycode == W)
		W_is_pressed(mapData);
	if (keycode == S)
		S_is_pressed(mapData);
	if (keycode == D)
		D_is_pressed(mapData);
	if (keycode == A)
		A_is_pressed(mapData);
	printf("Your score is: %d.\n", mapData->moves);
	return (0);
}

int	ft_exit(t_main *mapData)
{
    structFree(mapData);
    exit (SUCCESS);
}

int	render_next_frame(t_main *mapData)
{
	drawMap(mapData);
	drawPlayer(mapData);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	*mapData;

	handleErrors(argc, argv[1]);
	mapData = mapDataInit();
	fillMapData(mapData, argv[1]);
	getMap(mapData, argv[1]);
	checkMap(mapData);
	mapData->mlx_win = mlx_new_window(mapData->mlx, \
		mapData->size_x * 32, mapData->size_y * 32, "so_long");
	mlx_key_hook(mapData->mlx_win, key_hook, mapData);
	mlx_loop_hook(mapData->mlx, render_next_frame, mapData);
	mlx_hook(mapData->mlx_win, 17, 5, ft_exit, mapData);
	mlx_loop(mapData->mlx);
	return (SUCCESS);
}
