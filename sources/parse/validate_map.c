#include "cub3D.h"
#include "libft.h"

int	check_for_walls(char **rows, int i, int j, int rows_size)
{
	if (rows[i][j + 1] != '\0' && rows[i][j + 1] != '+' && rows[i][j + 1] != '1')
	{
		printf("Open on right of %d,%d\n", i, j);
		return (1);
	}
	if (j != 0)
	{
		if (rows[i][j - 1] != '+' && rows[i][j - 1] != '1')
		{
			printf("Open on left of %d,%d\n", i, j);
			return (1);
		}
	}
	if (i != 0)
	{
		if (rows[i - 1][j] != '+' && rows[i - 1][j] != '1')
		{
			printf("Open on top of %d,%d\n", i, j);
			return (1);
		}
	}
	if (i != (rows_size - 1))
	{
		if (rows[i + 1][j] != '+' && rows[i + 1][j] != '1')
		{
			printf("Open on bottom of %d,%d\n", i, j);
			return (1);
		}
	}
	return (0);
}

int	create_count(char **rows, int i, int j, int rows_size)
{
	int	count;

	count = 0;
	if (rows[i][j + 1] == '1')
		count |= 2;
	if (j != 0 && rows[i][j - 1] == '1')
		count |= 4;
	if (i != 0 && rows[i - 1][j] == '1')
		count |= 8;
	if (i != (rows_size - 1) && rows[i + 1][j] == '1')
		count |= 16;
	return (count);
}

// 2 => East
// 4 => West
// 8 => North
// 16 => South
int	check_for_internal_holes(char **rows, int i, int j, int rows_size)
{
	int	count;

	count = create_count(rows, i, j, rows_size);
	printf("Called for %d,%d\n", i, j);
	if (count != 0 && count != 2 && count != 4 && count != 8 && count != 16)
	{
		if (count & 2 && count & 8)
			if (rows[i - 1][j + 1] != '1')
				return (1);
		if (count & 4 && count & 8)
			if (rows[i - 1][j - 1] != '1')
				return (1);
		if (count & 2 && count & 16)
			if (rows[i + 1][j + 1] != '1')
				return (1);
		if (count & 4 && count & 16)
			if (rows[i + 1][j - 1] != '1')
				return (1);
	}
	return (0);
}

int	validate_plus_sign(char **rows)
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
				/* if (check_for_internal_holes(rows, i, j, double_array_size(rows))) */
				/* 	return (0); */
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

	l_line = find_longest_line(map->lines);
	q_line = ft_lstsize(map->lines);
	create_rows(map, l_line, q_line);
	print_rows(map->rows);
	if (!validate_plus_sign(map->rows))
		error("validate_map");
	return (1);
}
