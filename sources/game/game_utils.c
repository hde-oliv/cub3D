/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:24:22 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/29 16:36:34 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	dst = ((char *) img->addr) + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical_line(t_img *img, int x, t_vector *start_end, int color)
{
	int	i;

	i = start_end->x;
	while (i < (int)start_end->y)
	{
		put_pixel(img, x, i, color);
		i++;
	}
}
