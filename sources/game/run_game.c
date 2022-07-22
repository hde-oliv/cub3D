/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:38:17 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/22 20:23:31 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	run_hooks(t_game *game)
{
	mlx_hook(game->win, WIN_BUTTON_X, 0, &close_window, game);
	mlx_loop(game->mlx);
}

void	run_game(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
	run_hooks(game);
}


// void key_handler(int key)
// {
// 	if (key == 'A') {
// 		clear_window();
// 		// Change values
// 		raycaster(game);
// 	}
// }


