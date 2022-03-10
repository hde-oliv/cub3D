/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 17:26:00 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3D.h"

void	err(const char *err_func)
{
	printf("Error\n");
	perror(err_func);
	exit(1);
}

int	main(int argc, char *argv[])
{
	int		map_fd;

	if (argc != 2)
		err("main");
	/* if (!is_map(argv[1])) */
	/* 	err("is_map"); */
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		err("open");
	/* game.map = parse_map(map_fd); */
	/* create_game(&game); */
	/* run_game(&game); */
	/* mlx_loop(game.mlx); */
	return (0);
}
