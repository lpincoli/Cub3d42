/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:48:56 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_wall_hit(t_game *data)
{
	while (data->ray.hit == 0)
	{
		ft_check_sxdx(data);
		ft_check_updown(data);
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
		else if (data->map[data->ray.mapy][data->ray.mapx] == 'D')
		{
			if (data->door.open == 0)
				data->ray.hit = 2;
		}
		if (data->ray.hit == 2)
			data->ray.mgala = 6;
		else if (data->ray.hit == 3)
		{
			if (data->door.timer >= 0)
			{
				printf("timer = %d\n", data->door.timer);
				data->door.timer -= 1;
				data->ray.mgala = 7;
			}
		}
	}
}

void	ft_draw_screen(t_game *data)
{
	data->ray.x = 0;
	while (data->ray.x < SCREENWIDTH)
	{
		draw_column_init(data);
		ft_ray_dir(data);
		ft_wall_hit(data);
		ft_fish_eye(data);
		ft_height_wall(data);
		if (data->ray.side == 0 && data->ray.raydirx > 0)
			data->ray.texx = data->ray.tex_width - data->ray.texx - 1;
		if (data->ray.side == 1 && data->ray.raydiry < 0)
			data->ray.texx = data->ray.tex_width - data->ray.texx - 1;
		data->ray.step = 1.0 * data->ray.tex_height / data->ray.lineheight;
		data->ray.texpos = (data->ray.drawstart - SCREENHEIGHT / 2
				+ data->ray.lineheight / 2) * data->ray.step;
		data->intersection.x = data->ray.mapx;
		data->intersection.y = data->ray.mapy;
		data->ray.y = data->ray.drawstart;
		ft_draw_pixel_column(data);
		data->ray.x++;
	}
}

void	ft_timer(t_game *data)
{
	data->time.old_time = data->time.time;
	data->time.time = clock();
	data->time.frame_time = (data->time.time / 1000
			- data->time.old_time / 1000) / 1000.0;
	data->move_speed = data->time.frame_time * 5.0;
	data->rot_speed = data->time.frame_time * 3.0;
}

void	ft_draw_ray_3d(t_game *data)
{	
	ft_init_ray(data);
	ft_init_buff_texture(data);
	load_xpm_to_tex(data, data->ray.texture[0],
		data->instr[0]);
	load_xpm_to_tex(data, data->ray.texture[1],
		data->instr[1]);
	load_xpm_to_tex(data, data->ray.texture[2],
		data->instr[2]);
	load_xpm_to_tex(data, data->ray.texture[3],
		data->instr[3]);
	load_color_to_texture(data, data->ray.texture[4],
		data->instr[4]);
	load_color_to_texture(data, data->ray.texture[5],
		data->instr[5]);
	load_xpm_to_tex(data, data->ray.texture[6], "./textures/door.xpm");
	ft_draw_sky_floor(data);
	ft_draw_screen(data);
	ft_timer(data);
	ft_free_buffer(data->ray.buffer, SCREENHEIGHT);
	ft_free_buffer(data->ray.texture, data->ray.num_textures);
}
