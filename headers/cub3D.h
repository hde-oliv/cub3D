/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/10 17:24:26 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

/////////////
// Structs //
/////////////

typedef struct s_map
{
	char	*n_sprite;
	char	*s_sprite;
	char	*e_sprite;
	char	*w_sprite;
	char	*f_color;
	char	*c_color;
	int		height;
	int		width;
	char	**rows;
	t_list	*lines;
}	t_map;

typedef struct s_game
{
	t_map	*map;
}	t_game;

//////////////////
// Parse Module //
//////////////////

// Parse
void	parse_map(t_game *game, int fd);

// Parse utils
int		is_number(char *number);
int		double_array_size(char **array);
int		is_map(char *arg);
int		strcchr(char *s, char c);

// Validate elements
int		validate_elements(t_map *map);
int		double_array_size(char **array);

// Validate map
int		validate_map(t_map *map);

// Create rows
int		find_longest_line(t_list *lines);
char	sub_space_for_plus(unsigned int i, char c);
char	*string_create(char c, int size);
void	create_rows(t_map *map, int l_line, int q_line);

// Element
int		extract_element(t_map *map, char *elem, char *line, int *checklist);
int		check_for_elements_and_store(t_map *map, char *line, int *checklist);
int		fetch_elements(t_map *map, int fd);

// Checklist
void	update_checklist(int *checklist, char *elem);

//////////////////
// Error Module //
//////////////////

void	error(const char *function);
void	invalid_map(void *ptr, char *chr);

//////////////////
// Debug Module //
//////////////////

void	print_element(char **tmp);
void	print_map(t_list *lines);
void 	print_rows(char **rows);
#endif
