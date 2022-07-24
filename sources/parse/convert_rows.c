/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:17:02 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/23 21:10:55 by hde-oliv         ###   ########.fr       */
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
				rows[i][j] = rows[i][j]- 48;
			else
				rows[i][j] = 0;
			j++;
		}
		i++;
	}
}
