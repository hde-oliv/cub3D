/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/10 17:24:26 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

static void cerror(const char *function)
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

void	error(const char *function)
{
	printf("Error\n");
	if (errno != 0)
		perror(function);
	else
		cerror(function);
	exit(1);
}
