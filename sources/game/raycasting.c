/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:56:16 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/30 17:46:08 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_first_distance(t_game *game, t_raycaster *r, t_dvector *side_dist)
{
	if (r->ray_dir.x < 0)
	{
		r->step.x = -1;
		side_dist->x = (game->player.x - r->map.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		side_dist->x = (r->map.x + 1.0 - game->player.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0)
	{
		r->step.y = -1;
		side_dist->y = (game->player.y - r->map.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		side_dist->y = (r->map.y + 1.0 - game->player.y) * r->delta_dist.y;
	}
}

static void	cast_rays(t_game *game, t_raycaster *r, t_dvector *side_dist)
{
	set_first_distance(game, r, side_dist);
	while (r->hit == 0)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += r->delta_dist.x;
			r->map.x += r->step.x;
			r->side = 0;
		}
		else
		{
			side_dist->y += r->delta_dist.y;
			r->map.y += r->step.y;
			r->side = 1;
		}
		if ((game->map->rows)[r->map.x][r->map.y] > 0)
			r->hit = 1;
	}
}

static void	set_wall_height(t_raycaster *r, t_dvector *side_dist)
{
	if (r->side == 0)
		r->wall_dist = (side_dist->x - r->delta_dist.x);
	else
		r->wall_dist = (side_dist->y - r->delta_dist.y);
	r->line_height = (int)(WIN_HEIGHT / r->wall_dist);
	r->draw_start = -r->line_height / 2 + WIN_HEIGHT / 2;
	r->draw_end = r->line_height / 2 + WIN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end >= WIN_HEIGHT)
		r->draw_end = WIN_HEIGHT - 1;
}

void	raycast(t_game *game)
{
	int					x;
	t_raycaster			r;
	static t_dvector	side_dist;

	x = -1;
	r = (t_raycaster){};
	while (++x < WIN_WIDTH)
	{
		initialize_raycaster_values(game, &r, x);
		cast_rays(game, &r, &side_dist);
		set_wall_height(&r, &side_dist);
		put_textures(game, &r, x);
	}
}
