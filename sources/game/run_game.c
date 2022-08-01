/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:38:17 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/31 21:18:57 by hde-oliv         ###   ########.fr       */
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
	clear_view(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img, 0, 0);
}

void	clear_view(t_game *game)
{
	int			i;
	t_dvector	start_end;

	i = WIN_WIDTH;
	start_end.x = 0;
	start_end.y = WIN_HEIGHT;
	while (i != -1)
	{
		start_end.x = 0;
		start_end.y = WIN_HEIGHT / 2;
		draw_vertical_line(game->screen, i, &start_end, game->c_color);
		start_end.x = WIN_HEIGHT / 2;
		start_end.y = WIN_HEIGHT;
		draw_vertical_line(game->screen, i, &start_end, game->f_color);
		i--;
	}
}
