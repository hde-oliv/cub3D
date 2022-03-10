#include "cub3D.h"

int	extract_element(t_map *map, char *elem, char *line, int *checklist)
{
	char	**tmp;
	char	*tmp2;

	tmp = ft_split(line, ' ');
	if (tmp == NULL)
		error("malloc");
	print_element(tmp);
	tmp2 = ft_strdup(tmp[1]);
	if (tmp2 == NULL)
		error("malloc");
	if (!ft_strncmp(elem, "NO", 3))
		map->n_sprite = tmp2;
	else if (!ft_strncmp(elem, "SO", 3))
		map->s_sprite = tmp2;
	else if (!ft_strncmp(elem, "EA", 3))
		map->e_sprite = tmp2;
	else if (!ft_strncmp(elem, "WE", 3))
		map->w_sprite = tmp2;
	else if (!ft_strncmp(elem, "C", 2))
		map->c_color = tmp2;
	else if (!ft_strncmp(elem, "F", 2))
		map->f_color = tmp2;
	update_checklist(checklist, elem);
	return (1);
}

int	check_for_elements_and_store(t_map *map, char *line, int *checklist)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (extract_element(map, "NO", line, checklist));
	else if (!ft_strncmp(line, "SO ", 3))
		return (extract_element(map, "SO", line, checklist));
	else if (!ft_strncmp(line, "EA ", 3))
		return (extract_element(map, "EA", line, checklist));
	else if (!ft_strncmp(line, "WE ", 3))
		return (extract_element(map, "WE", line, checklist));
	else if (!ft_strncmp(line, "C ", 2))
		return (extract_element(map, "C", line, checklist));
	else if (!ft_strncmp(line, "F ", 2))
		return (extract_element(map, "F", line, checklist));
	else if (!ft_strncmp(line, " ", ft_strlen(line)))
		return (1);
	else if (ft_strlen(line) == 0)
		return (1);
	return (0);
}

int		fetch_elements(t_map *map, int fd)
{
	char	*line;
	int		checklist;

	checklist = 0;
	while (checklist != 126 && get_next_line(fd, &line) == 1)
	{
		if (!line)
			error("malloc");
		line = ft_strtrim(line, " ");
		if (check_for_elements_and_store(map, line, &checklist))
			continue;
		else
		{
			if (checklist != 126)
				return (0) ;
		}
	}
	return (1);
}
