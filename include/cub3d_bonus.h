/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:24:23 by michele           #+#    #+#             */
/*   Updated: 2023/06/19 18:52:35 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>
# include<time.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define SCREENWIDTH 1080
# define SCREENHEIGHT 720
# define KEY_ESC  65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_SPACE 32
# define FRAC_BITS 16
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define NUM_TEXTURES 7
# define TILE_SIZE 64

typedef struct s_door
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	open;
	int	timer;
}	t_door;

typedef struct s_coord
{
	int					x;
	int					y;

}	t_coord;

typedef struct s_vector
{
	double				x;
	double				y;
}	t_vect;

typedef struct s_time
{
	double				old_time;
	double				time;
	double				frame_time;
}	t_time;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		bpp;
	int		size_line;
	char	*img_data;
	void	*img_ptr;
}	t_img;

typedef struct s_victor{
	float	x;
	float	y;
}	t_victor;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			y;
	int			x;
	int			p;
	float		raydirx0;
	float		raydiry0;
	float		raydirx1;
	float		raydiry1;
	float		posz;
	float		rowdistance;
	float		floorstepx;
	float		floorstepy;
	float		floorx;
	float		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
	int			floortexture;
	int			ceilingtexture;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
	uint32_t	color;
	uint32_t	**buffer;
	uint32_t	**texture;
	int			mgala;
	int			tex_width;
	int			tex_height;
	int			num_textures;

}	t_raycast;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				map_w;
	int				map_h;
	float			pa;
	double			ra;
	t_img			img;
	t_img			minimap;
	void			*img_ptr;
	char			**instr;
	char			**map;
	t_vect			pos;
	t_vect			dir;
	t_vect			plane;
	t_vect			hr;
	t_vect			vr;
	t_vect			mhr;
	t_vect			mvr;
	t_raycast		ray;
	t_victor		intersection;
	t_door			door;
	double			door_dist;
	float			dish;
	float			disv;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	t_time			time;
	float			angle;
	int				color;
	double			move_speed;
	double			rot_speed;
	int				num_player;
	int				mouse_x;
	int				mouse_y;
}	t_game;
void	ft_check_tex(t_game *data);
void	ft_giga_error(char *str, t_game *data);
int		mouse_move(int x, int y, t_game *game);
void	key_a(t_game *data);
void	key_d(t_game *data);
double	distance_to_door(t_game *data);
void	ft_door(t_game *data, int keycode);
void	ft_init_door(t_game *data);
void	ft_free_array(char **array);
void	ft_check_updown(t_game *data);
void	ft_ray_dir(t_game *data);
void	ft_check_sxdx(t_game *data);
void	ft_fish_eye(t_game *data);
void	ft_draw_sky_floor(t_game *data);
void	ft_draw_pixel_column(t_game *data);
void	ft_draw_screen(t_game *data);
void	ft_height_wall(t_game *data);
void	ft_free_buffer(uint32_t **buffer, int n);
void	ft_init_buff_texture(t_game *data);
void	draw_column_init(t_game *data);
void	init_draw_sky_floor(t_game *data);
void	ft_init_ray(t_game *data);
void	load_color_to_texture(t_game *data, uint32_t *texture, char *color);
void	load_xpm_to_tex(t_game *data, uint32_t *texture, const char *filename);
void	ft_error(char *str);
void	check_right_border(t_game *data);
void	check_left_border(t_game *data);
void	check_inf_border(t_game *data);
void	check_sup_border(t_game *data);
void	ft_draw_map(t_game data);
void	ft_draw_player(t_game data);
void	ft_draw_ray_3d(t_game *data);
void	ft_draw_round_player(t_game data);
int		ft_is_player(t_game *data, int x, int y);
void	ft_find_pl(t_game *data);
int		load_img_orientation(t_game *data);
char	*ft_get_map(char *path_ber);
void	ft_check_map_border(t_game *data);
int		key_input(int keycode, t_game *data);
void	ft_divide_map(t_game *data, char **tmp);
int		ft_close(t_game *init);
void	ft_print_map(char **map);
void	ft_free_map(char **map);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
