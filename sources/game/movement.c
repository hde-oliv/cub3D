/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:17:14 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/08/01 19:10:00 by hde-oliv         ###   ########.fr       */
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

void	move_player_right(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->player.x - game->direction.y * game->move_speed;
	next_y = game->player.y + game->direction.x * game->move_speed;
	if ((game->map->rows)[next_x][(int)game->player.y] == 0)
		game->player.x -= game->direction.y * game->move_speed;
	if ((game->map->rows)[(int)game->player.x][next_y] == 0)
		game->player.y += game->direction.x * game->move_speed;
}

void	move_player_left(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->player.x + game->direction.y * game->move_speed;
	next_y = game->player.y - game->direction.x * game->move_speed;
	if ((game->map->rows)[next_x][(int)game->player.y] == 0)
		game->player.x += game->direction.y * game->move_speed;
	if ((game->map->rows)[(int)game->player.x][next_y] == 0)
		game->player.y -= game->direction.x * game->move_speed;
}
