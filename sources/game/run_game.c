/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:38:17 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/23 19:49:56 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	run_game(t_game *game)
{
	set_view(game);
	set_hooks(game);
}

void	set_view(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
}

void	clear_view(t_game *game)
{
	int			i;
	t_vector	start_end;

	i = WIN_WIDTH;
	start_end.x = 0;
	start_end.y = WIN_HEIGHT;
	while (i != -1)
	{
		draw_vertical_line(game->screen, i, &start_end, 0x00000000);
		i--;
	}
}
