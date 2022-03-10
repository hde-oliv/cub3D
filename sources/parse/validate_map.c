#include "cub3D.h"
#include "libft.h"

int	validate_map(t_map *map)
{
	int	l_line;
	int	q_line;

	l_line = find_longest_line(map->lines);
	q_line = ft_lstsize(map->lines);
	create_rows(map, l_line, q_line);
	print_rows(map->rows);
	return (1);
}
