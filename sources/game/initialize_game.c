/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:36:33 by rike              #+#    #+#             */
/*   Updated: 2022/07/31 21:24:38 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	initialize_texture(t_game *game, t_img *sprite, char *path)
{
	sprite->img = mlx_xpm_file_to_image(game->mlx, path,
			&sprite->width, &sprite->height);
	if (!sprite->img)
		return (0);
	sprite->addr = (int *) mlx_get_data_addr(sprite->img,
			&sprite->bpp, \
			&sprite->l_len, \
			&sprite->endian);
	return (1);
}

void	initialize_images(t_game *game)
{
	game->screen->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->screen->addr = (int *) mlx_get_data_addr(game->screen->img,
			&game->screen->bpp, \
			&game->screen->l_len, \
			&game->screen->endian);
	game->screen->height = WIN_HEIGHT;
	game->screen->width = WIN_WIDTH;
	if (!initialize_texture(game, game->n_sprite, game->map->n_sprite))
		error(game, "initialize_texture");
	if (!initialize_texture(game, game->s_sprite, game->map->s_sprite))
		error(game, "initialize_texture");
	if (!initialize_texture(game, game->w_sprite, game->map->w_sprite))
		error(game, "initialize_texture");
	if (!initialize_texture(game, game->e_sprite, game->map->e_sprite))
		error(game, "initialize_texture");
}

void	initialize_colors(t_game *game)
{
	if (!parse_rgb(game->map->c_color, &game->c_color))
		error(game, "parse_rgb");
	if (!parse_rgb(game->map->f_color, &game->f_color))
		error(game, "parse_rgb");
}

void	initialize_game(t_game *game)
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
	game->move_speed = 0.4;
	game->rot_speed = 0.2;
	initialize_colors(game);
	initialize_images(game);
	convert_rows(game->map);
}
