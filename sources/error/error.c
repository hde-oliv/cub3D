/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:10:21 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

static void	cerror(const char *function)
{
	if (!ft_strncmp(function, "main", 5))
		printf("main: Invalid number of arguments\n");
	else if (!ft_strncmp(function, "is_map", 7))
		printf("is_map: Invalid map\n");
	else if (!ft_strncmp(function, "fetch_elements", 15))
		printf("fetch_elements: Missing or invalid map element\n");
	else if (!ft_strncmp(function, "fetch_map", 9))
		printf("fetch_map: Missing map\n");
	else if (!ft_strncmp(function, "validate_elements", 17))
		printf("validate_elements: Invalid color\n");
}

void	clear_gnl(int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
		free(line);
	free(line);
}

void	free_everything(t_game *game)
{
	free(game->map->c_color);
	free(game->map->f_color);
	free(game->map->e_sprite);
	free(game->map->n_sprite);
	free(game->map->w_sprite);
	free(game->map->s_sprite);
	ft_dfree(game->map->rows);
	ft_lstclear(&game->map->lines, &free);
}

void	error(t_game *game, const char *function)
{
	printf("Error\n");
	if (errno != 0)
		perror(function);
	else
		cerror(function);
	free_everything(game);
	exit(1);
}

