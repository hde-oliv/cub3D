/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:36:33 by rike              #+#    #+#             */
/*   Updated: 2022/07/26 23:32:59 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void initialize_sprites(t_game *game);
int initialize_tex(t_game *game, t_img *sprite, char *path);


void	initialize_images(t_game *game)
{
	game->screen->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->screen->addr = mlx_get_data_addr(game->screen->img, 
											&game->screen->bpp, \
											&game->screen->l_len, \
											&game->screen->endian);
	// TODO: initialize textures	
}

// TODO: check for malloc errors

void initialize_sprites(t_game *game)
{
	int error;

	//ft_memset(img, 0, sizeof(t_img) * 4):
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
	int h;
	int w;

	sprite->img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!sprite->img)
		return(1);
	sprite->addr = mlx_get_data_addr(sprite->img, 
											&sprite->bpp, \
											&sprite->l_len, \
											&sprite->endian);
	printf("%d\n", sprite->bpp);
	printf("%d %d\n", w, h);
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
	initialize_images(game);
	initialize_sprites(game);
	convert_rows(game->map);
}
