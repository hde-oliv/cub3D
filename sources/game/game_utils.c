/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:24:22 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/27 22:55:41 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_game *game, t_img *img, int x, int y, int color)
{
	char	*dst;

	
	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = mlx_get_color_value(game->mlx, color);
}

void	draw_vertical_line(t_game *game, t_img *img, int x, t_vector *start_end, int color)
{
	int	i;

	i = start_end->x;
	while (i < (int)start_end->y)
	{
		put_pixel(game, img, x, i, color);
		i++;
	}
}
