/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:39:24 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_player(t_game *data, int x, int y)
{
	if (data->map[y][x] == 'N')
		return (1);
	else if (data->map[y][x] == 'S')
		return (1);
	else if (data->map[y][x] == 'E')
		return (1);
	else if (data->map[y][x] == 'W')
		return (1);
	return (0);
}

void	ft_draw_player(t_game data)
{
	int	i;
	int	j;
	int	tile_map;

	tile_map = TILE_SIZE / 8;
	i = 0;
	while (i < tile_map / 2 + 1)
	{
		j = 0;
		while (j < tile_map / 2 + 1)
		{
			my_mlx_pixel_put(&data.img, data.pos.x
				* tile_map + i - tile_map / 4 + 800, data.pos.y
				* tile_map + j - tile_map / 4, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	ft_init_west(t_game *data)
{
	data->dirx = -1;
	data->diry = 0;
	data->planex = 0;
	data->planey = -0.66;
}

void	ft_init_orientation(t_game *data)
{
	if (data->map[(int)data->pos.y][(int)data->pos.x] == 'N')
	{
		data->dirx = 0;
		data->diry = -1;
		data->planex = 0.66;
		data->planey = 0;
	}
	else if (data->map[(int)data->pos.y][(int)data->pos.x] == 'S')
	{
		data->dirx = 0;
		data->diry = 1;
		data->planex = -0.66;
		data->planey = 0;
	}
	else if (data->map[(int)data->pos.y][(int)data->pos.x] == 'E')
	{
		data->dirx = 1;
		data->diry = 0;
		data->planex = 0;
		data->planey = 0.66;
	}
	else if (data->map[(int)data->pos.y][(int)data->pos.x] == 'W')
		ft_init_west(data);
}

void	ft_find_pl(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	data->num_player = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->pos.x = j;
				data->pos.y = i;
				data->num_player++;
			}
			j++;
		}
		i++;
	}
	if (data->num_player != 1)
		ft_giga_error("Error\nWrong number of players", data);
	ft_init_orientation(data);
	ft_check_tex(data);
}
