/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:24:22 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/28 19:54:10 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_game *game, t_img *img, int x, int y, int color)
{
	char	*dst;

	(void)game;
	dst = ((char *) img->addr) + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
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
