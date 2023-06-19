/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:05:08 by ocastell          #+#    #+#             */
/*   Updated: 2023/06/19 18:51:57 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_mappa(char c)
{
	if (c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == 'D')
		return (1);
	else
		return (0);
}

void	check_sup_border(t_game *data)
{
	int	j;

	j = 0;
	while (data->map[0][j])
	{
		if (check_mappa(data->map[0][j]))
			ft_giga_error("Map not Valid", data);
		j++;
	}
	j = 0;
	while (data->map[1][j])
	{
		if (check_mappa(data->map[1][j]))
		{
			if ((data->map[0][j] == ' ')
			|| (data->map[0][j] == '\n')
			|| (data->map[0][j] == '\0'))
				ft_giga_error("Map not Valid", data);
		}
		j++;
	}
}

void	check_inf_border(t_game *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (check_mappa(data->map[i][j]))
			{
				if ((data->map[i - 1][j] == ' ')
				|| (data->map[i - 1][j] == '\n')
				|| (data->map[i - 1][j] == '\0'))
					ft_giga_error("Map not Valid", data);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_left_border(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (check_mappa(data->map[i][j]))
			{
				if ((data->map[i][j - 1] == ' ')
				|| (data->map[i][j - 1] == '\n')
				|| (data->map[i][j - 1] == '\0'))
					ft_giga_error("Map not Valid", data);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_right_border(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (check_mappa(data->map[i][j]))
			{
				if ((data->map[i][j + 1] == ' ')
				|| (data->map[i][j + 1] == '\n')
				|| (data->map[i][j + 1] == '\0'))
					ft_giga_error("Map not Valid", data);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
