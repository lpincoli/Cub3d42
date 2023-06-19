/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:58:06 by mgirardi          #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	key_w(t_game *data)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = (int)data->pos.y;
	b = (int)(data->pos.x + data->dirx * data->move_speed);
	if (((int)(data->pos.y + data->diry * data->move_speed)) >= 14)
		c = 13;
	else
		c = (int)(data->pos.y + data->diry * data->move_speed);
	d = (int)(data->pos.x);
	if (data->map[a][b] == '0' || data->map[a][b] == 'N'
		|| data->map[a][b] == 'S' || data->map[a][b] == 'E'
			|| data->map[a][b] == 'W' || (data->map[a][b] == 'D'
			&& data->door.open == 1))
		data->pos.x += data->dirx * data->move_speed;
	if (data->map[c][d] == '0' || data->map[c][d] == 'N'
		|| data->map[c][d] == 'S' || data->map[c][d] == 'E'
			|| data->map[c][d] == 'W' || (data->map[c][d] == 'D'
				&& data->door.open == 1))
		data->pos.y += data->diry * data->move_speed;
}

void	key_s(t_game *data)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = (int)data->pos.y;
	b = (int)(data->pos.x - data->dirx * data->move_speed);
	if (((int)(data->pos.y - data->diry * data->move_speed)) >= 14)
		c = 13;
	else
		c = (int)(data->pos.y - data->diry * data->move_speed);
	d = (int)(data->pos.x);
	if (data->map[a][b] == '0' || data->map[a][b] == 'N'
		|| data->map[a][b] == 'S' || data->map[a][b] == 'E'
			|| data->map[a][b] == 'W' || (data->map[a][b] == 'D'
				&& data->door.open == 1))
		data->pos.x -= data->dirx * data->move_speed;
	if (data->map[c][d] == '0' || data->map[c][d] == 'N'
		|| data->map[c][d] == 'S' || data->map[c][d] == 'E'
			|| data->map[c][d] == 'W' || (data->map[c][d] == 'D'
				&& data->door.open == 1))
		data->pos.y -= data->diry * data->move_speed;
}

void	key_d(t_game *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	data->dirx = data->dirx * cos(data->rot_speed)
		- data->diry * sin(data->rot_speed);
	data->diry = olddirx * sin(data->rot_speed)
		+ data->diry * cos(data->rot_speed);
	oldplanex = data->planex;
	data->planex = data->planex * cos(data->rot_speed)
		- data->planey * sin(data->rot_speed);
	data->planey = oldplanex * sin(data->rot_speed)
		+ data->planey * cos(data->rot_speed);
}

void	key_a(t_game *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	data->dirx = data->dirx * cos(-data->rot_speed)
		- data->diry * sin(-data->rot_speed);
	data->diry = olddirx * sin(-data->rot_speed)
		+ data->diry * cos(-data->rot_speed);
	oldplanex = data->planex;
	data->planex = data->planex * cos(-data->rot_speed)
		- data->planey * sin(-data->rot_speed);
	data->planey = oldplanex * sin(-data->rot_speed)
		+ data->planey * cos(-data->rot_speed);
}

int	key_input(int keycode, t_game *data)
{
	char	*tmpbhop;

	ft_door(data, keycode);
	if (keycode == KEY_ESC)
		ft_close(data);
	if (keycode == KEY_W)
		key_w(data);
	else if (keycode == KEY_S)
		key_s(data);
	else if (keycode == KEY_D || keycode == 65363)
		key_d(data);
	else if (keycode == KEY_A || keycode == 65361)
		key_a(data);
	ft_draw_ray_3d(data);
	ft_draw_map(*data);
	ft_draw_player(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "FPS: ");
	tmpbhop = ft_itoa(1.0 / data->time.frame_time);
	mlx_string_put(data->mlx, data->win, 60, 10, 0xFFFFFF, tmpbhop);
	free(tmpbhop);
	return (0);
}
