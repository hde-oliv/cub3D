/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/27 22:01:11 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

static void	cerror(const char *function)
{
	if (!ft_strncmp(function, "main", 5))
		printf("%s: Invalid number of arguments\n", function);
	else if (!ft_strncmp(function, "is_map", 7))
		printf("%s: Invalid map\n", function);
	else if (!ft_strncmp(function, "fetch_elements", 15))
		printf("%s: Missing or invalid map element\n", function);
	else if (!ft_strncmp(function, "fetch_map", 9))
		printf("%s: Missing map\n", function);
	else if (!ft_strncmp(function, "validate_elements", 17))
		printf("%s: Invalid color\n", function);
	else
		printf("%s: Unknown error\n", function);
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
