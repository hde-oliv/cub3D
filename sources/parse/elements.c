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
#include "libft.h"

static int	look_checklist(int *checklist, t_element elem)
{
	int	n;

	n = 0;
	if (elem == NO)
		n = 2;
	else if (elem == SO)
		n = 4;
	else if (elem == EA)
		n = 8;
	else if (elem == WE)
		n = 16;
	else if (elem == C)
		n = 32;
	else if (elem == F)
		n = 64;
	if (*checklist & n)
		return (1);
	return (0);
}

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
	update_checklist(checklist, elem);
	return (1);
}

// Invalid RGB 39
// Invalid EA 009
// Invalid NO 008
// Invalid NO 021
// Invalid SO 021
// Invalid WE 021
static int	extract_element(t_map *map, t_element elem, char *line, int *checklist)
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
