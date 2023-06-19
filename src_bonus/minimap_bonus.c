/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:42:21 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_tile(int x, int y, int color, t_game data)
{
	int	i;
	int	j;
	int	tile_map;

	tile_map = TILE_SIZE / 8;
	i = 0;
	while (i < tile_map)
	{
		j = 0;
		while (j < tile_map)
		{
			my_mlx_pixel_put(&data.img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_hide_door(t_game data, int i, int j)
{
	int	tile_map;

	tile_map = TILE_SIZE / 8;
	if (data.door.open == 0)
		ft_draw_tile(j * tile_map + 800, i
			* tile_map, 0xFF0000, data);
	else
		ft_draw_tile(j * tile_map + 800, i
			* tile_map, 0x00FFFFFF, data);
}

void	ft_draw_map(t_game data)
{
	int	i;
	int	j;
	int	tile_map;

	tile_map = TILE_SIZE / 8;
	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '0' || data.map[i][j] == 'N'
				|| data.map[i][j] == 'S' || data.map[i][j] == 'E'
					|| data.map[i][j] == 'W')
				ft_draw_tile(j * tile_map + 800, i
					* tile_map, 0x00FFFFFF, data);
			else if (data.map[i][j] == 'D')
				ft_hide_door(data, i, j);
			j++;
		}
		i++;
	}
}
