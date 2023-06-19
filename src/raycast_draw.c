/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:18:40 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_sky_floor_data(t_game *data)
{
	data->ray.cellx = (int)(data->ray.floorx);
	data->ray.celly = (int)(data->ray.floory);
	data->ray.tx = (int)(data->ray.tex_width * (data->ray.floorx
				- data->ray.cellx)) & (data->ray.tex_width - 1);
	data->ray.ty = (int)(data->ray.tex_height * (data->ray.floory
				- data->ray.celly)) & (data->ray.tex_height - 1);
	data->ray.floorx += data->ray.floorstepx;
	data->ray.floory += data->ray.floorstepy;
	data->ray.floortexture = 4;
	data->ray.ceilingtexture = 5;
	data->ray.color = data->ray.texture[data->ray.floortexture]
	[data->ray.tex_width * data->ray.ty + data->ray.tx];
}

void	ft_draw_sky_floor(t_game *data)
{
	data->ray.y = 0;
	data->ray.x = 0;
	while (data->ray.y < SCREENHEIGHT)
	{
		init_draw_sky_floor(data);
		while (data->ray.x < SCREENWIDTH)
		{
			ft_sky_floor_data(data);
			my_mlx_pixel_put(&data->img, data->ray.x, data->ray.y,
				data->ray.color);
			data->ray.color = data->ray.texture[data->ray.ceilingtexture]
			[data->ray.tex_width * data->ray.ty + data->ray.tx];
			my_mlx_pixel_put(&data->img, data->ray.x, SCREENHEIGHT
				- data->ray.y - 1, data->ray.color);
			++data->ray.x;
		}
		data->ray.x = 0;
		data->ray.y++;
	}
}

void	ft_draw_pixel_column(t_game *data)
{
	while (data->ray.y < data->ray.drawend)
	{
		data->ray.texy = (int)data->ray.texpos & (data->ray.tex_height - 1);
		data->ray.texpos += data->ray.step;
		data->ray.color = data->ray.texture[data->ray.mgala]
		[data->ray.tex_height * data->ray.texy + data->ray.texx];
		if (data->ray.side == 1)
			data->ray.color = (data->ray.color >> 1) & 8355711;
		data->ray.buffer[data->ray.y][data->ray.x] = data->ray.color;
		my_mlx_pixel_put(&data->img, data->ray.x,
			data->ray.y, data->ray.color);
		data->ray.y++;
	}
}
