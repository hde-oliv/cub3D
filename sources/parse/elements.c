/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:10:02 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/27 22:08:39 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

static int	extract_rgb(t_map *map, t_element elem, char *line, int *checklist)
{
	char	**tmp;
	char	*tmp2;

	tmp = ft_split(line, ' ');
	free(line);
	if (tmp[2] != NULL || look_checklist(checklist, elem))
	{
		ft_dfree(tmp);
		return (0);
	}
	if (tmp == NULL)
		return (1);
	tmp2 = ft_strdup(tmp[1]);
	ft_dfree(tmp);
	if (tmp2 == NULL)
		return (1);
	if (elem == C)
		map->c_color = tmp2;
	else if (elem == F)
		map->f_color = tmp2;
	return (update_checklist(checklist, elem));
}

static int	extract_element(t_map *map, t_element elem, \
							char *line, int *checklist)
{
	char	**tmp;
	char	*tmp2;

	tmp = ft_split(line, ' ');
	free(line);
	if (tmp[2] != NULL || look_checklist(checklist, elem))
	{
		ft_dfree(tmp);
		return (0);
	}
	if (tmp == NULL)
		return (1);
	tmp2 = ft_strdup(tmp[1]);
	ft_dfree(tmp);
	if (tmp2 == NULL)
		return (1);
	if (elem == NO)
		map->n_sprite = tmp2;
	else if (elem == SO)
		map->s_sprite = tmp2;
	else if (elem == EA)
		map->e_sprite = tmp2;
	else if (elem == WE)
		map->w_sprite = tmp2;
	return (update_checklist(checklist, elem));
}

static int	check_for_elements_and_store(t_map *map, char *line, int *checklist)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (extract_element(map, NO, line, checklist));
	else if (!ft_strncmp(line, "SO ", 3))
		return (extract_element(map, SO, line, checklist));
	else if (!ft_strncmp(line, "EA ", 3))
		return (extract_element(map, EA, line, checklist));
	else if (!ft_strncmp(line, "WE ", 3))
		return (extract_element(map, WE, line, checklist));
	else if (!ft_strncmp(line, "C ", 2))
		return (extract_rgb(map, C, line, checklist));
	else if (!ft_strncmp(line, "F ", 2))
		return (extract_rgb(map, F, line, checklist));
	else if (!ft_strncmp(line, " ", ft_strlen(line)) || ft_strlen(line) == 0)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	fetch_elements(t_map *map, int fd)
{
	char	*line;
	int		check;

	check = 0;
	while ((check != 126 || check & 1) && get_next_line(fd, &line) == 1)
	{
		if (line == NULL)
			return (1);
		if (!check_for_elements_and_store(map, ft_strtrim(line, " "), &check) \
			&& check != 126)
		{
			free(line);
			clear_gnl(fd);
			return (0);
		}
		free(line);
	}
	return (1);
}
