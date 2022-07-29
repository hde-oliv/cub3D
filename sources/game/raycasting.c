/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:56:16 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/29 16:36:37 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int	get_pixel_color(t_img *img, int x, int y, int width, int height)
{
	char	*dst;

	if (x < 0 || x > width || y < 0 || y > height)
		return (1);
	dst = (char *)img->addr + (y * img->l_len + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	raycast(t_game *game)
{
	//t_vector start_end;

	for (int x = 0; x < WIN_WIDTH; x++)
	{
		double camera_x = 2 * x / ((double)WIN_WIDTH) - 1;
		double ray_dir_x = game->direction.x + game->plane.x * camera_x;
		double ray_dir_y = game->direction.y + game->plane.y * camera_x;

		int map_x = (int)game->player.x;
		int map_y = (int)game->player.y;

		static double side_dist_x;
		static double side_dist_y;

		double delta_dist_x = (ray_dir_x == 0) ? 10000000 : fabs(1 / ray_dir_x);
		double delta_dist_y = (ray_dir_y == 0) ? 10000000 : fabs(1 / ray_dir_y);
		double perp_wall_dist;

		int step_x;
		int step_y;

		int hit = 0;
		int side;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->player.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->player.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if ((game->map->rows)[map_x][map_y] > 0)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);
		
		int line_height = (int)(WIN_HEIGHT / perp_wall_dist);

		int draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + WIN_HEIGHT / 2;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;

		//include textures
		double wallX;
		if (side == 0) 
			wallX = game->player.y + perp_wall_dist * ray_dir_y;
		else
			wallX = game->player.x + perp_wall_dist * ray_dir_x;
		wallX -= (int)wallX;
		//choose texture
		t_img *texture = game->n_sprite;

		if(side == 1 && ray_dir_y < 0)
			texture = game->w_sprite;
		else if(side == 1)
			texture = game->e_sprite;
		else if(ray_dir_x > 0)
			texture = game->s_sprite;
			
		int texX = (int)(wallX * (double)texture->width);
		if(side == 0 && ray_dir_x > 0)
			texX = texture->width - texX - 1;
		if(side == 1 && ray_dir_y < 0)
			texX = texture->width - texX - 1;
		//start_end.x = draw_start;
		//start_end.y = draw_end;
		//draw_vertical_line(game->screen, x, &start_end, 0x0000FF00);

		double step = 1.0 * texture->height / line_height;
		double texPos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			int	texY;

			texY = (int)texPos & (texture->height - 1);
			texPos += step;
			int color = 0;
			color = get_pixel_color(texture, texX, texY, texture->height, texture->width);
			put_pixel(game->screen, x, y, color);
		}
	}
}
