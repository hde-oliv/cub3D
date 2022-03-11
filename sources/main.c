/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:10:18 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	t_map	map;
	int		map_fd;

	if (argc != 2)
		error("main");
	if (!is_map(argv[1]))
		error("is_map");
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		error("open");
	game.map = &map;
	parse_map(&game, map_fd);
	return (0);
}
