#include "cub3D.h"

int	check_for_walls(char **rows, int i, int j, int rows_size)
{
	if (rows[i][j + 1] != '\0' && rows[i][j + 1] != '+' \
		&& rows[i][j + 1] != '1')
		return (1);
	if (j != 0 && rows[i][j - 1] != '+' && rows[i][j - 1] != '1')
		return (1);
	if (i != 0 && rows[i - 1][j] != '+' && rows[i - 1][j] != '1')
		return (1);
	if (i != (rows_size - 1) && rows[i + 1][j] != '+' && rows[i + 1][j] != '1')
		return (1);
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

int	check_for_internal_holes(char **rows, int i, int j, int rows_size)
{
	int	count;

	count = create_count(rows, i, j, rows_size);
	if (count != 0 && count != 2 && count != 4 && count != 8 && count != 16)
	{
		if (count & 2 && count & 8 && rows[i - 1][j + 1] != '1')
			return (1);
		if (count & 4 && count & 8 && rows[i - 1][j - 1] != '1')
			return (1);
		if (count & 2 && count & 16 && rows[i + 1][j + 1] != '1')
			return (1);
		if (count & 4 && count & 16 && rows[i + 1][j - 1] != '1')
			return (1);
	}
	return (0);
}

int	check_for_plus_and_wall(char *row)
{
	while (*row)
	{
		if (*row != '+' && *row != '1')
			return (0);
		row++;
	}
	return (1);
}
