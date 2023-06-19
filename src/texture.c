/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:22:53 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_load_image(t_game *data, const char *fn)
{
	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx, (char *)fn,
			&data->img.img_width, &data->img.img_height);
	if (!data->img.img_ptr)
	{
		printf("Error loading XPM image: %s\n", fn);
		return (0);
	}
	data->img.img_data = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.size_line, &data->img.endian);
	if (!data->img.img_data)
	{
		printf("Error getting image data for %s\n", fn);
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		return (0);
	}
	return (1);
}

void	load_xpm_to_tex(t_game *data, uint32_t *tex, const char *fn)
{
	int			y;
	int			x;
	int			offset;
	uint32_t	pixel_color;

	y = 0;
	x = 0;
	if (!ft_load_image(data, fn))
		return ;
	while (y < data->ray.tex_height)
	{
		while (x < data->ray.tex_width)
		{
			offset = y * data->img.size_line + x * 4;
			pixel_color = *((uint32_t *)(data->img.img_data + offset));
			tex[y * data->ray.tex_width + x] = pixel_color;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(data->mlx, data->img.img_ptr);
}

int	get_str_to_int(char *str)
{
	int		i;
	int		color;
	char	**rgb;

	i = 0;
	color = 0;
	rgb = ft_split(str, ',');
	while (rgb[i])
	{
		color = color * 256 + ft_atoi(rgb[i]);
		i++;
	}
	while (i--)
		free (rgb[i]);
	free (rgb);
	return (color);
}

void	load_color_to_texture(t_game *data, uint32_t *texture, char *color)
{
	int	pixel_color;
	int	y;
	int	x;

	y = 0;
	x = 0;
	pixel_color = get_str_to_int(color);
	while (y < data->ray.tex_height)
	{
		while (x < data->ray.tex_width)
		{
			texture[y * data->ray.tex_width + x] = pixel_color;
			x++;
		}
		x = 0;
		y++;
	}
}
