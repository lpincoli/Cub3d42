/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:19:52 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (array[i] != NULL)
			free(array[i]);
		else
			break ;
		i++;
	}
	free(array);
}

void	ft_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y++]);
		if (map[y] == NULL)
			break ;
	}
	free(map);
	map = NULL;
}

void	ft_print_map(char **map)
{
	int		y;

	y = 0;
	while (map[y])
	{
		if (map[y] == NULL)
			break ;
		y++;
	}
}

int	ft_close(t_game *init)
{
	ft_free_map(init->map);
	ft_free_map(init->instr);
	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_image(init->mlx, init->img.img);
	mlx_destroy_display(init->mlx);
	free(init->mlx);
	exit(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
