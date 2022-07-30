/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/30 16:37:48 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	double_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_number(char *number)
{
	int	size;
	int	i;

	size = ft_strlen(number);
	i = 1;
	if (number[0] != '-' && !ft_isdigit(number[0]))
		return (0);
	while (i < size)
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_map(char *arg)
{
	char	*dot_location;

	dot_location = ft_strrchr(arg, '.');
	if (dot_location)
		return (!ft_strncmp(dot_location, ".cub", 4));
	return (0);
}

int	parse_rgb(char *rgb, int *color)
{
	char	**rgb_splited;

	rgb_splited = ft_split(rgb, ',');
	if (!rgb_splited)
		return (0);
	*color = 0;
	*color = 0xFF << 24 | ft_atoi(rgb_splited[0]) << 16
		| ft_atoi(rgb_splited[1]) << 8 | ft_atoi(rgb_splited[2]);
	ft_dfree(rgb_splited);
	return (1);
}
