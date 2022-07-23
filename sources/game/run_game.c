/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:38:17 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/23 18:09:47 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	run_game(t_game *game)
{
	set_view(game);
	run_hooks(game);
}

void	set_view(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
}
