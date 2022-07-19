/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:10:18 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

int w = 500;
int h = 500;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_vertical_line(t_img *img, int x, t_vector *start_end, int color)
{
	(void)color;
	printf("x=%d, start=%d, end=%d\n", x, (int)start_end->x , (int) start_end->y);
	for (int i = start_end->x; i < (int) start_end->y; i++)
		my_mlx_pixel_put(img, x, i, 0x00FF0000);
}

void game(t_img *img, t_game *game, void *mlx, void *mlx_win)
{
	static t_vector player;
	static t_vector direction;
	static t_vector plane;
	static t_vector start_end;

	player.x = 22, player.y = 12;
	direction.x = -1, direction.y = 0;
	plane.x = 0, plane.y = 0.66;
	while (1)
	{
		for (int x = 0; x < w; x++)
		{
			double camera_x = 2 * x / ((double)w) - 1;
			printf("camera_x=%f\n", camera_x);
			double ray_dir_x = direction.x + plane.x * camera_x;
			double ray_dir_y = direction.y + plane.y * camera_x;

			printf("camera_x=%f, ray_dir_x=%f, ray_dir_y=%f\n", camera_x, ray_dir_x, ray_dir_y);

			int map_x = (int)player.x;
			int map_y = (int)player.y;

			static double side_dist_x;
			static double side_dist_y;

			double delta_dist_x = (ray_dir_x == 0) ? 10000000 : fabs(1 / ray_dir_x);
			double delta_dist_y = (ray_dir_y == 0) ? 10000000 : fabs(1 / ray_dir_y);
			double perp_wall_dist;

			int step_x;
			int step_y;

			int hit = 0;
			int side;

			printf("side_dist_x=%f, delta_dist_x=%f\n", side_dist_x, delta_dist_x);
			printf("side_dist_y=%f, delta_dist_y=%f\n", side_dist_y, delta_dist_y);

			if (ray_dir_x < 0)
			{
				step_x = -1;
				printf("player_x=%f, map_x=%d, delta_dist_x=%f\n", player.x, map_x, delta_dist_x);
				side_dist_x = (player.x - map_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (map_x + 1.0 - player.x) * delta_dist_x;
			}
			if (ray_dir_y < 0)
			{
				step_y = -1;
				side_dist_y = (player.y - map_y) * delta_dist_y;
			}
			else
			{
				step_y = 1;
				side_dist_y = (map_y + 1.0 - player.y) * delta_dist_y;
			}
			printf("side_dist_x=%f, delta_dist_x=%f\n", side_dist_x, delta_dist_x);
			printf("side_dist_y=%f, delta_dist_y=%f\n", side_dist_y, delta_dist_y);

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
				if (worldMap[map_x][map_y] > 0)
					hit = 1;
				puts("Ronaldinho");
			}
			(void)game;
			if (side == 0)
				perp_wall_dist = (side_dist_x - delta_dist_x);
			else
				perp_wall_dist = (side_dist_y - delta_dist_y);
			
			printf("perp_wall_dist=%f\n", perp_wall_dist);
			int line_height = (int)(h / perp_wall_dist);
			printf("line_height=%d\n", line_height);

			int draw_start = -line_height / 2 + h / 2;
			if (draw_start < 0)
				draw_start = 0;
			int draw_end = line_height / 2 + h / 2;
			printf("draw_end=%d\n", draw_end);
			if (draw_end >= h)
				draw_end = h - 1;
			start_end.x = draw_start;
			start_end.y = draw_end;

			puts("Ratinho");
			draw_vertical_line(img, x, &start_end, 0);
			mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
		}
	}
}

void bullshit(t_game *gam)
{
	void 	*mlx;
	void 	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, w, h, "Cub3D");

	img.img = mlx_new_image(mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	game(&img, gam, mlx, mlx_win);
	mlx_loop(mlx);
}

int main(int argc, char *argv[])
{
	static t_game game;
	static t_map map;
	int map_fd;

	if (argc != 2)
		error(&game, "main");
	if (!is_map(argv[1]))
		error(&game, "is_map");
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		error(&game, "open");
	game.map = &map;
	parse_map(&game, map_fd);
	bullshit(&game);
	free_everything(&game);
	return (0);
}
