/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:49:35 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_height_wall(t_game *data)
{
	data->ray.lineheight = (int)(SCREENHEIGHT / data->ray.perpwalldist);
	data->ray.drawstart = -data->ray.lineheight / 2 + SCREENHEIGHT / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->ray.lineheight / 2 + SCREENHEIGHT / 2;
	if (data->ray.drawend >= SCREENHEIGHT)
		data->ray.drawend = SCREENHEIGHT - 1;
	if (data->ray.side == 0)
		data->ray.wallx = data->ray.posy + data->ray.perpwalldist
			* data->ray.raydiry;
	else
		data->ray.wallx = data->ray.posx + data->ray.perpwalldist
			* data->ray.raydirx;
	data->ray.wallx -= floor((data->ray.wallx));
	data->ray.texx = (int)(data->ray.wallx * (double)(data->ray.tex_width));
}

void	ft_fish_eye(t_game *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.sidedistx
				- data->ray.deltadistx);
	else
		data->ray.perpwalldist = (data->ray.sidedisty
				- data->ray.deltadisty);
}

void	ft_ray_dir(t_game *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->ray.posx
				- data->ray.mapx) * data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->ray.posx)
			* data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->ray.posy - data->ray.mapy)
			* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->ray.posy)
			* data->ray.deltadisty;
	}
}

void	ft_check_sxdx(t_game *data)
{
	if (data->ray.sidedistx < data->ray.sidedisty)
	{
		data->ray.sidedistx += data->ray.deltadistx;
		data->ray.mapx += data->ray.stepx;
		data->ray.side = 0;
	}
	else
	{
		data->ray.sidedisty += data->ray.deltadisty;
		data->ray.mapy += data->ray.stepy;
		data->ray.side = 1;
	}
}

void	ft_check_updown(t_game *data)
{
	if (data->ray.side == 1)
	{
		if (data->ray.stepy == 1)
			data->ray.mgala = 0;
		else
			data->ray.mgala = 1;
	}
	else if (data->ray.side == 0)
	{
		if (data->ray.stepx == 1)
			data->ray.mgala = 2;
		else
			data->ray.mgala = 3;
	}
}
