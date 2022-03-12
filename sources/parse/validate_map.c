/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:10:14 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:10:15 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	validate_boundaries(char **rows, int rows_size, int row_size)
{
	int	i;

	i = 0;
	if (!check_for_plus_and_wall(rows[0]))
		return (0);
	if (!check_for_plus_and_wall(rows[rows_size - 1]))
		return (0);
	while (i < rows_size)
	{
		if (rows[i][0] != '+' && rows[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows_size)
	{
		if (rows[i][row_size - 1] != '+' && rows[i][row_size - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	validate_player(char **rows)
{
	int	found;
	int	i;
	int	j;

	i = 0;
	j = 0;
	found = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			if (ft_strchr("NWSE", rows[i][j]))
				found++;
			j++;
		}
		i++;
	}
	return (found == 1);
}

static int	validate_unknown_elements(t_list *lines)
{
	int	j;

	while (lines)
	{
		j = 0;
		while (((char *)(lines->content))[j])
		{
			if (!ft_strchr("10 NWSE", ((char *)(lines->content))[j]))
				return (0);
			j++;
		}
		lines = lines->next;
	}
	return (1);
}

static int	validate_plus_sign(char **rows)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			if (rows[i][j] == '+')
			{
				if (check_for_walls(rows, i, j, double_array_size(rows)))
					return (0);
				if (check_for_internal_holes(rows, i, j, \
											double_array_size(rows)))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	int	l_line;
	int	q_line;

	if (map->lines == NULL)
		return (0);
	l_line = find_longest_line(map->lines);
	q_line = ft_lstsize(map->lines);
	if (l_line < 3 || q_line < 3)
		return (0);
	if (!validate_unknown_elements(map->lines))
		return (0);
	create_rows(map, l_line, q_line);
	if (!validate_plus_sign(map->rows))
		return (0);
	if (!validate_boundaries(map->rows, double_array_size(map->rows), l_line))
		return (0);
	if (!validate_player(map->rows))
		return (0);
	return (1);
}
