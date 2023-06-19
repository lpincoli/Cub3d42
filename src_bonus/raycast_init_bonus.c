/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:17:06 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_ray(t_game *data)
{
	data->ray.posx = data->pos.x;
	data->ray.posy = data->pos.y;
	data->ray.dirx = data->dirx;
	data->ray.diry = data->diry;
	data->ray.planex = data->planex;
	data->ray.planey = data->planey;
	data->ray.tex_width = TEX_WIDTH;
	data->ray.tex_height = TEX_HEIGHT;
	data->ray.num_textures = NUM_TEXTURES;
}

void	init_draw_sky_floor(t_game *data)
{
	data->ray.raydirx0 = data->ray.dirx - data->ray.planex;
	data->ray.raydiry0 = data->ray.diry - data->ray.planey;
	data->ray.raydirx1 = data->ray.dirx + data->ray.planex;
	data->ray.raydiry1 = data->ray.diry + data->ray.planey;
	data->ray.p = data->ray.y - SCREENHEIGHT / 2;
	data->ray.posz = 0.5 * SCREENHEIGHT;
	data->ray.rowdistance = data->ray.posz / data->ray.p;
	data->ray.floorstepx = data->ray.rowdistance
		* (data->ray.raydirx1 - data->ray.raydirx0) / SCREENWIDTH;
	data->ray.floorstepy = data->ray.rowdistance
		* (data->ray.raydiry1 - data->ray.raydiry0) / SCREENWIDTH;
	data->ray.floorx = data->ray.posx + data->ray.rowdistance
		* data->ray.raydirx0;
	data->ray.floory = data->ray.posy + data->ray.rowdistance
		* data->ray.raydiry0;
}

void	draw_column_init(t_game *data)
{
	data->ray.camerax = 2 * data->ray.x / (double)SCREENWIDTH - 1;
	data->ray.raydirx = data->ray.dirx + data->ray.planex * data->ray.camerax;
	data->ray.raydiry = data->ray.diry + data->ray.planey * data->ray.camerax;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	data->ray.deltadistx = (1 / data->ray.raydirx);
	if (data->ray.deltadistx < 0)
		data->ray.deltadistx = -data->ray.deltadistx;
	data->ray.deltadisty = (1 / data->ray.raydiry);
	if (data->ray.deltadisty < 0)
		data->ray.deltadisty = -data->ray.deltadisty;
	data->ray.hit = 0;
}

void	ft_init_buff_texture(t_game *data)
{
	int	i;

	i = 0;
	data->ray.buffer = calloc(sizeof(uint32_t *), SCREENHEIGHT);
	data->ray.texture = calloc(sizeof(uint32_t *), data->ray.num_textures);
	while (i < SCREENHEIGHT)
		data->ray.buffer[i++] = calloc(sizeof(uint32_t), SCREENWIDTH);
	i = 0;
	while (i < data->ray.num_textures)
		data->ray.texture[i++] = calloc(sizeof(uint32_t),
				(data->ray.tex_width * data->ray.tex_height));
}

void	ft_free_buffer(uint32_t **buffer, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(buffer[i++]);
	free(buffer);
}
