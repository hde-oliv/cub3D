/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 16:57:35 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

int	fetch_map(t_map *map, int fd)
{
	char	*line;
	t_list	*lines;
	int		skip;

	skip = 1;
	lines = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (skip && (ft_strlen(line) == 0 || !ft_strncmp(line, " ", ft_strlen(line))))
			continue ;
		skip = 0;
		ft_lstadd_back(&lines, ft_lstnew(line));
	}
	print_map(lines);
	map->lines = lines;
	return (1);
}

void	parse_map(t_game *game, int fd)
{
	if (!fetch_elements(game->map, fd))
		error("fetch_elements");
	if (!fetch_map(game->map, fd))
		error("fetch_map");

}

