/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:10:02 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:10:03 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	update_checklist(int *checklist, t_element elem)
{
	int	n_to_update;

	n_to_update = 0;
	if (elem == NO)
		n_to_update = 2;
	else if (elem == SO)
		n_to_update = 4;
	else if (elem == EA)
		n_to_update = 8;
	else if (elem == WE)
		n_to_update = 16;
	else if (elem == C)
		n_to_update = 32;
	else if (elem == F)
		n_to_update = 64;
	if (*checklist & n_to_update)
		*checklist |= 1;
	else
		*checklist |= n_to_update;
}

static int	extract_rgb(t_map *map, t_element elem, char *line, int *checklist)
{
	char	**tmp;
	char	*tmp2;

	tmp = ft_split(line, ' ');
	if (tmp == NULL)
		error("malloc");
	tmp2 = ft_strdup(tmp[1]);
	if (tmp2 == NULL)
		error("malloc");
	if (elem == C)
		map->c_color = tmp2;
	else if (elem == F)
		map->f_color = tmp2;
	update_checklist(checklist, elem);
	return (1);
}

static int	extract_element(t_map *map, t_element elem, char *line, int *checklist)
{
	char	**tmp;
	char	*tmp2;

	tmp = ft_split(line, ' ');
	if (tmp[2] != NULL)
		return (0);
	if (tmp == NULL)
		error("malloc");
	tmp2 = ft_strdup(tmp[1]);
	if (tmp2 == NULL)
		error("malloc");
	if (elem == NO)
		map->n_sprite = tmp2;
	else if (elem == SO)
		map->s_sprite = tmp2;
	else if (elem == EA)
		map->e_sprite = tmp2;
	else if (elem == WE)
		map->w_sprite = tmp2;
	update_checklist(checklist, elem);
	return (1);
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
	else if (!ft_strncmp(line, " ", ft_strlen(line)))
		return (1);
	else if (ft_strlen(line) == 0)
		return (1);
	return (0);
}

int	fetch_elements(t_map *map, int fd)
{
	char	*line;
	int		checklist;

	checklist = 0;
	while ((checklist != 126 || checklist & 1) && get_next_line(fd, &line) == 1)
	{
		if (!line)
			error("malloc");
		line = ft_strtrim(line, " ");
		if (check_for_elements_and_store(map, line, &checklist))
			continue ;
		else
		{
			if (checklist != 126)
				return (0);
		}
	}
	return (1);
}
