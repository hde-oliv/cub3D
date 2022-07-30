/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:24:22 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/30 17:47:40 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initialize_raycaster_values(t_game *game, t_raycaster *r, int x)
{
	r->camera.x = 2 * x / ((double)WIN_WIDTH) - 1;
	r->ray_dir.x = game->direction.x + game->plane.x * r->camera.x;
	r->ray_dir.y = game->direction.y + game->plane.y * r->camera.x;
	r->map.x = (int)game->player.x;
	r->map.y = (int)game->player.y;
	if (r->ray_dir.x == 0)
		r->delta_dist.x = 10000000;
	else
		r->delta_dist.x = (1 / r->ray_dir.x);
	if (r->ray_dir.y == 0)
		r->delta_dist.y = 10000000;
	else
		r->delta_dist.y = (1 / r->ray_dir.y);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	dst = ((char *) img->addr) + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return (1);
	dst = (char *)img->addr + (y * img->l_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_vertical_line(t_img *img, int x, t_dvector *start_end, int color)
{
	int	i;

	i = start_end->x;
	while (i < (int)start_end->y)
	{
		put_pixel(img, x, i, color);
		i++;
	}
}
