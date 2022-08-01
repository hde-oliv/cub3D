/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:28:56 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/31 21:14:30 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	select_texture(t_game *game, t_raycaster *r)
{
	r->texture = game->n_sprite;
	if (r->side == 1 && r->ray_dir.y < 0)
		r->texture = game->w_sprite;
	else if (r->side == 1)
		r->texture = game->e_sprite;
	else if (r->ray_dir.x > 0)
		r->texture = game->s_sprite;
}

static void	texture_loop(t_game *game, t_raycaster *r, int x)
{
	int	y;
	int	color;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		r->tex.y = (int)r->tex_pos & (r->texture->height - 1);
		r->tex_pos += r->tex_step;
		color = get_pixel_color(r->texture, r->tex.x, r->tex.y);
		put_pixel(game->screen, x, y, color);
		y++;
	}
}

void	put_textures(t_game *game, t_raycaster *r, int x)
{
	if (r->side == 0)
		r->wall.x = game->player.y + r->wall_dist * r->ray_dir.y;
	else
		r->wall.x = game->player.x + r->wall_dist * r->ray_dir.x;
	r->wall.x -= (int)r->wall.x;
	select_texture(game, r);
	r->tex.x = (int)(r->wall.x * (double)r->texture->width);
	if (r->side == 0 && r->ray_dir.x > 0)
		r->tex.x = r->texture->width - r->tex.x - 1;
	if (r->side == 1 && r->ray_dir.y < 0)
		r->tex.x = r->texture->width - r->tex.x - 1;
	r->tex_step = 1.0 * r->texture->height / r->line_height;
	r->tex_pos = (r->draw_start - WIN_HEIGHT / 2 + r->line_height / 2) \
				* r->tex_step;
	texture_loop(game, r, x);
}
