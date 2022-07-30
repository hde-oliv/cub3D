/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:17:14 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/30 16:40:40 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player_forward(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->player.x + game->direction.x * game->move_speed;
	next_y = game->player.y + game->direction.y * game->move_speed;
	if ((game->map->rows)[next_x][(int)game->player.y] == 0)
		game->player.x += game->direction.x * game->move_speed;
	if ((game->map->rows)[(int)game->player.x][next_y] == 0)
		game->player.y += game->direction.y * game->move_speed;
}

void	move_player_backward(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->player.x - game->direction.x * game->move_speed;
	next_y = game->player.y - game->direction.y * game->move_speed;
	if ((game->map->rows)[next_x][(int)game->player.y] == 0)
		game->player.x -= game->direction.x * game->move_speed;
	if ((game->map->rows)[(int)game->player.x][next_y] == 0)
		game->player.y -= game->direction.y * game->move_speed;
}

void	look_player_left(t_game *game)
{
	t_vector	direction;
	t_vector	plane;
	double		old_dir_x;
	double		old_plane_x;

	direction = game->direction;
	plane = game->plane;
	old_dir_x = direction.x;
	old_plane_x = plane.x;
	game->direction.x = direction.x \
			* cos(game->rot_speed) - direction.y * sin(game->rot_speed);
	game->direction.y = old_dir_x \
			* sin(game->rot_speed) + direction.y * cos(game->rot_speed);
	game->plane.x = plane.x * cos(game->rot_speed) \
			- plane.y * sin(game->rot_speed);
	game->plane.y = old_plane_x * sin(game->rot_speed) \
			+ plane.y * cos(game->rot_speed);
}

void	look_player_right(t_game *game)
{
	t_vector	direction;
	t_vector	plane;
	double		old_dir_x;
	double		old_plane_x;

	direction = game->direction;
	plane = game->plane;
	old_dir_x = direction.x;
	old_plane_x = plane.x;
	game->direction.x = direction.x \
		* cos(-game->rot_speed) - direction.y * sin(-game->rot_speed);
	game->direction.y = old_dir_x * sin(-game->rot_speed) \
		+ direction.y * cos(-game->rot_speed);
	game->plane.x = plane.x * cos(-game->rot_speed) \
		- plane.y * sin(-game->rot_speed);
	game->plane.y = old_plane_x * sin(-game->rot_speed) \
		+ plane.y * cos(-game->rot_speed);
}
