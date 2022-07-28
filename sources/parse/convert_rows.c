/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:17:02 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/28 20:30:16 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	convert_rows(t_map *map)
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
			if (!ft_strchr("NWSE", rows[i][j]))
				rows[i][j] = rows[i][j] - 48;
			else
				rows[i][j] = 0;
			j++;
		}
		i++;
	}
}
