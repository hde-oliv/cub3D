/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:39:07 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/08/01 19:22:12 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	end_game(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen->img);
	mlx_destroy_image(game->mlx, game->n_sprite->img);
	mlx_destroy_image(game->mlx, game->w_sprite->img);
	mlx_destroy_image(game->mlx, game->s_sprite->img);
	mlx_destroy_image(game->mlx, game->e_sprite->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->screen);
	free(game->n_sprite);
	free(game->s_sprite);
	free(game->w_sprite);
	free(game->e_sprite);
	free(game->mlx);
	free_everything(game);
	exit(0);
}
