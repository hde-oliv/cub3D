#include "cub3D.h"
#include "libft.h"

int	is_rgb_bounded(char **rgb)
{
	size_t	r;
	size_t	g;
	size_t	b;

	if (!is_number(rgb[0]))
		return (0);
	if (!is_number(rgb[1]))
		return (0);
	if (!is_number(rgb[2]))
		return (0);
	r = ft_atoll(rgb[0]);
	g = ft_atoll(rgb[1]);
	b = ft_atoll(rgb[2]);
	if (r > 255)
		return (0);
	else if (g > 255)
		return (0);
	else if (b > 255)
		return (0);
	return (1);
}

int validate_elements(t_map *map)
{
	int		fd;
	char	**rgb;

	fd = open(map->e_sprite, O_RDONLY);
	if (fd == -1)
		error("validate_elements");
	fd = open(map->w_sprite, O_RDONLY);
	if (fd == -1)
		error("validate_elements");
	fd = open(map->n_sprite, O_RDONLY);
	if (fd == -1)
		error("validate_elements");
	fd = open(map->s_sprite, O_RDONLY);
	if (fd == -1)
		error("validate_elements");
	rgb = ft_split(map->c_color, ',');
	if (double_array_size(rgb) != 3)
		error("validate_elements");
	if (!is_rgb_bounded(rgb))
		error("validate_elements");
	return (1);
}

