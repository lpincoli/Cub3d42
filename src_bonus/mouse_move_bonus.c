/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:07:07 by ocastell          #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_vector(double *x, double *y, double angle)
{
	double	old_x;
	double	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(angle) - old_y * sin(angle);
	*y = old_x * sin(angle) + old_y * cos(angle);
}

void	ft_draw_mouse(t_game *game)
{
	char		*tmpbhop;

	ft_draw_ray_3d(game);
	ft_draw_map(*game);
	ft_draw_player(*game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "FPS: ");
	tmpbhop = ft_itoa(1.0 / game->time.frame_time);
	mlx_string_put(game->mlx, game->win, 60, 10, 0xFFFFFF, tmpbhop);
	free(tmpbhop);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_mouse_x = -1;
	int			dx;
	double		rotation_angle;

	(void)y;
	if (last_mouse_x != -1)
	{
		dx = x - last_mouse_x;
		if (dx > 15 || dx < -15)
		{
			rotation_angle = dx * game->rot_speed / 14;
			rotate_vector(&game->dirx, &game->diry, rotation_angle);
			rotate_vector(&game->planex, &game->planey, rotation_angle);
		}
		else
			return (0);
	}
	last_mouse_x = x;
	ft_draw_mouse(game);
	return (0);
}
