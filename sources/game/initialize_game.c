/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:36:33 by rike              #+#    #+#             */
/*   Updated: 2022/07/22 20:49:09 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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


void initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	game->screen = malloc(sizeof(t_img));
	game->n_sprite = malloc(sizeof(t_img));
	game->s_sprite = malloc(sizeof(t_img));
	game->e_sprite = malloc(sizeof(t_img));
	game->w_sprite = malloc(sizeof(t_img));
	game->player.x = 22;
	game->player.y = 12;
	game->direction.x = -1;
	game->direction.y = 0;
	game->plane.x = 0;
	game->plane.y = 0.66;
	initialize_images(game);
}
