/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:51:26 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/28 20:29:49 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	end_game(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_everything(game);
	game->mlx = NULL;
	exit(0);
}
