/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/21 21:51:47 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

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

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	int		init;
	t_map	*map;
	t_img	*img;
	void	*mlx;
	void	*win;
	t_img	*screen;
	t_img	*n_sprite;
	t_img	*s_sprite;
	t_img	*e_sprite;
	t_img	*w_sprite;
}	t_game;

typedef enum e_element
{
	NO,
	SO,
	EA,
	WE,
	C,
	F
}	t_element;

# define KEYPRESS 2
# define KEYRELEASE 3
# define ESC 0x00ff1b
# define WIN_BUTTON_X 17

//////////////////
// Parse Module //
//////////////////

// Parse
void	parse_map(t_game *game, int fd);

// Parse utils
int		is_number(char *number);
int		double_array_size(char **array);
int		is_map(char *arg);

// Validate elements
int		validate_elements(t_map *map);

// Validate map
int		validate_map(t_map *map);

// Validate map utils
int		check_for_walls(char **rows, int i, int j, int rows_size);
int		create_count(char **rows, int i, int j, int rows_size);
int		check_for_internal_holes(char **rows, int i, int j, int rows_size);
int		check_for_plus_and_wall(char *row);

// Create rows
int		find_longest_line(t_list *lines);
char	sub_space_for_plus(unsigned int i, char c);
char	*string_create(char c, int size);
void	create_rows(t_map *map, int l_line, int q_line);

// Elements
int		fetch_elements(t_map *map, int fd);

// Checklist
int		look_checklist(int *checklist, t_element elem);
int		update_checklist(int *checklist, t_element elem);

//////////////////
// Error Module //
//////////////////

// Error
void	error(t_game *game, const char *function);
void	clear_gnl(int fd);
void	free_everything(t_game *game);

//////////////////
// Debug Module //
//////////////////

// Debug
void	print_element(char **tmp);
void	print_map(t_list *lines);
void	print_rows(char **rows);

//close map

#endif
