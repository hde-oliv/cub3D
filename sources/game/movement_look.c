/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 23:24:41 by snovaes           #+#    #+#             */
/*   Updated: 2022/07/31 23:24:50 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	look_player_left(t_game *game)
{
	t_dvector	direction;
	t_dvector	plane;
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
	t_dvector	direction;
	t_dvector	plane;
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
