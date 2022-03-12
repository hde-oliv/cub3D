/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:10:09 by hde-oliv         ###   ########.fr       */
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
		if (skip && (ft_strlen(line) == 0 || \
					!ft_strncmp(line, " ", ft_strlen(line))))
		{
			free(line);
			continue ;
		}
		skip = 0;
		ft_lstadd_back(&lines, ft_lstnew(line));
	}
	free(line);
	map->lines = lines;
	return (1);
}

void	parse_map(t_game *game, int fd)
{
	if (!fetch_elements(game->map, fd))
		error(game, "fetch_elements");
	if (!fetch_map(game->map, fd))
		error(game, "fetch_map");
	if (!validate_elements(game->map))
		error(game, "validate_elements");
	if (!validate_map(game->map))
		error(game, "validate_map");
	close(fd);
}
