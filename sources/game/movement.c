/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:17:14 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/28 20:29:07 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double		moveSpeed = 0.1 * 5.0;
double		rotSpeed = 0.1 * 3.0;
extern int	worldMap[24][24];

void	move_player_forward(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->player.x + game->direction.x * moveSpeed;
	next_y = game->player.y + game->direction.y * moveSpeed;
	if ((game->map->rows)[next_x][(int)game->player.y] == 0)
		game->player.x += game->direction.x * moveSpeed;
	if ((game->map->rows)[(int)game->player.x][(int)next_y] == 0)
		game->player.y += game->direction.y * moveSpeed;
	return ;
}

void	move_player_backward(t_game *game)
{
	game->player.x -= game->direction.x * moveSpeed;
	game->player.y -= game->direction.y * moveSpeed;
	return ;
}

void	move_player_left(t_game *game)
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
			* cos(rotSpeed) - direction.y * sin(rotSpeed);
	game->direction.y = old_dir_x \
			* sin(rotSpeed) + direction.y * cos(rotSpeed);
	game->plane.x = plane.x * cos(rotSpeed) \
			- plane.y * sin(rotSpeed);
	game->plane.y = old_plane_x * sin(rotSpeed) \
			+ plane.y * cos(rotSpeed);
}

void	move_player_right(t_game *game)
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
		* cos(-rotSpeed) - direction.y * sin(-rotSpeed);
	game->direction.y = old_dir_x * sin(-rotSpeed) \
		+ direction.y * cos(-rotSpeed);
	game->plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
	game->plane.y = old_plane_x * sin(-rotSpeed) + plane.y * cos(-rotSpeed);
}
