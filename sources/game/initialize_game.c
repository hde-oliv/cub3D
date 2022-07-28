/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:36:33 by rike              #+#    #+#             */
/*   Updated: 2022/07/27 22:49:56 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void initialize_sprites(t_game *game);
int initialize_tex(t_game *game, t_img *sprite, char *path);
static int parse_rgb(char *rgb, int *color);
void initialize_colors(t_game *game);

void	initialize_images(t_game *game)
{
	game->screen->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->screen->addr = mlx_get_data_addr(game->screen->img, 
											&game->screen->bpp, \
											&game->screen->l_len, \
											&game->screen->endian);
	printf("%d\n", game->screen->endian);
	game->screen->height = WIN_HEIGHT;
	game->screen->width = WIN_WIDTH;
}

// TODO: check for malloc errors

void initialize_sprites(t_game *game)
{
	int error;

	error = 0;
	error = error || initialize_tex(game, game->n_sprite, game->map->n_sprite);
	error = error || initialize_tex(game, game->s_sprite, game->map->s_sprite);
	error = error || initialize_tex(game, game->w_sprite, game->map->w_sprite);
	error = error || initialize_tex(game, game->e_sprite, game->map->e_sprite);
	if (error)
	{
		ft_putendl_fd("No texture was found", 0);
		exit(0);
	}
}

int initialize_tex(t_game *game, t_img *sprite, char *path)
{
	
	sprite->img = mlx_xpm_file_to_image(game->mlx, path, &sprite->width, &sprite->height);
	if (!sprite->img)
		return(1);
	sprite->addr = mlx_get_data_addr(sprite->img, 
											&sprite->bpp, \
											&sprite->l_len, \
											&sprite->endian);
	return (0);
}

void initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	game->screen = malloc(sizeof(t_img));
	game->n_sprite = malloc(sizeof(t_img));
	game->s_sprite = malloc(sizeof(t_img));
	game->e_sprite = malloc(sizeof(t_img));
	game->w_sprite = malloc(sizeof(t_img));
	game->player.x = game->map->player_x;
	game->player.y = game->map->player_y;
	game->direction.x = -1;
	game->direction.y = 0;
	game->plane.x = 0;
	game->plane.y = 0.66;
	initialize_colors(game);
	initialize_images(game);
	initialize_sprites(game);
	convert_rows(game->map);
}

void initialize_colors(t_game *game)
{
	parse_rgb(game->map->c_color, &game->c_color);
	parse_rgb(game->map->f_color, &game->f_color);
}

static int parse_rgb(char *rgb, int *color)
{
	int		i;
	int		sub_color;
	char	**rgb_splited;

	rgb_splited	= ft_split(rgb, ','); //0,255,154
	if (!rgb_splited)
		return(1);
	i = 3;
	*color = 0;
	while(i > 0)
	{
		sub_color = ft_atoi(rgb_splited[3 - i]);
		if (sub_color > 255 || sub_color < 0)
		{
			ft_dfree(rgb_splited);
			return (1);
		}
		*color += pow(sub_color, i + 1);
		i--;
	}
	ft_dfree(rgb_splited);
	return(0);
}
