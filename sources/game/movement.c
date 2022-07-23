/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:17:14 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/23 19:38:32 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double moveSpeed = 0.1 * 5.0;
double rotSpeed = 0.1 * 3.0;

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

void	move_player_forward(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->player.x + game->direction.x * moveSpeed;
	next_y = game->player.y + game->direction.y * moveSpeed;
	if (worldMap[next_x][(int)game->player.y] == 0)
		game->player.x += game->direction.x * moveSpeed;
	if (worldMap[(int)game->player.x][(int)next_y] == 0)		
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
	t_vector direction;
	t_vector plane;
    double old_dir_x;
    double old_plane_x;

	direction = game->direction;
	plane = game->plane;
	old_dir_x = direction.x;
	old_plane_x = plane.x;
    direction.x = direction.x * cos(rotSpeed) - direction.y * sin(rotSpeed);
    direction.y = old_dir_x * sin(rotSpeed) + direction.y * cos(rotSpeed);
    plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
    plane.y = old_plane_x * sin(rotSpeed) + plane.y * cos(rotSpeed);
}

void	move_player_right(t_game *game)
{
	t_vector direction;
	t_vector plane;
    double old_dir_x;
    double old_plane_x;

	direction = game->direction;
	plane = game->plane;
	old_dir_x = direction.x;
	old_plane_x = plane.x;
    direction.x = direction.x * cos(-rotSpeed) - direction.y * sin(-rotSpeed);
    direction.y = old_dir_x * sin(-rotSpeed) + direction.y * cos(-rotSpeed);
    plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
    plane.y = old_plane_x * sin(-rotSpeed) + plane.y * cos(-rotSpeed);
}
