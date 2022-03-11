/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:10:11 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:10:12 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

static int	count_commas(char *rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rgb[i])
	{
		if (rgb[i] == ',')
			j++;
		i++;
	}
	return (j);
}

static int	is_rgb_bounded(char **rgb)
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

static int	validate_rgb(t_map *map)
{
	char	**rgb;

	if (count_commas(map->c_color) != 2)
		return (0);
	rgb = ft_split(map->c_color, ',');
	if (double_array_size(rgb) != 3)
		return (0);
	if (!is_rgb_bounded(rgb))
		return (0);
	if (count_commas(map->f_color) != 2)
		return (0);
	rgb = ft_split(map->f_color, ',');
	if (double_array_size(rgb) != 3)
		return (0);
	if (!is_rgb_bounded(rgb))
		return (0);
	return (1);
}

int	validate_elements(t_map *map)
{
	int		fd;

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
	if (!validate_rgb(map))
		error("validate_elements");
	return (1);
}
