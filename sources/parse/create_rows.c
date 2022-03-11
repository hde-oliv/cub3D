/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:09:58 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 15:09:59 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_longest_line(t_list *lines)
{
	int	i;
	int	j;

	i = ft_strlen(lines->content);
	j = 0;
	while (lines)
	{
		j = ft_strlen(lines->content);
		if (j > i)
			i = j;
		lines = lines->next;
	}
	return (i);
}

char	sub_space_for_plus(unsigned int i, char c)
{
	(void)i;
	if (c == ' ')
		return ('+');
	return (c);
}

char	*string_create(char c, int size)
{
	char	*str;

	str = malloc(size + 1);
	str[size] = '\0';
	while (size != -1)
		str[--size] = c;
	return (str);
}

void	create_rows(t_map *map, int l_line, int q_line)
{
	char	*str;
	int		i;
	int		diff;
	t_list	*tmp;

	map->rows = (char **) ft_calloc(q_line + 1, sizeof(char *));
	map->rows[q_line] = NULL;
	tmp = map->lines;
	i = 0;
	while (i < q_line)
	{
		str = ft_strmapi(tmp->content, &sub_space_for_plus);
		diff = l_line - ft_strlen(str);
		if (diff)
			str = ft_strjoin(str, string_create('+', diff));
		map->rows[i++] = str;
		tmp = tmp->next;
	}
}
