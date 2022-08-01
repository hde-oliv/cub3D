/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_side.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:39:07 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/31 21:50:54 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	get_player_side(t_map *map)
{
	int		i;
	int		j;
	char	**rows;

	i = 0;
	j = 0;
	rows = map->rows;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			if (ft_strchr("NWSE", rows[i][j]))
				return (rows[i][j]);
			j++;
		}
		i++;
	}
	return ('N');
}

void	set_initial_side(t_game *game, double radians)
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
		* cos(radians) - direction.y * sin(-radians);
	game->direction.y = old_dir_x * sin(-radians) \
		+ direction.y * cos(-radians);
	game->plane.x = plane.x * cos(-radians) \
		- plane.y * sin(-radians);
	game->plane.y = old_plane_x * sin(-radians) \
		+ plane.y * cos(-radians);
}

double	get_side_radians(t_game *game)
{
	char	player;

	player = get_player_side(game->map);
	if (player == 'N')
		return (0);
	else if (player == 'S')
		return (M_PI);
	else if (player == 'E')
		return (M_PI / 2);
	else if (player == 'W')
		return ((M_PI * 3) / 2);
	return (0);
}
