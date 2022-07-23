/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/23 18:02:37 by hde-oliv         ###   ########.fr       */
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
// Defines //
/////////////

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define X_BUTTON_EV 17
# define NO_MASK 0L
# define KEY_PRESS_EV 2
# define KEY_PRESS_MASK 1L
# define FOCUS_EV 9
# define FOCUS_MASK 2097152
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

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
	int		bpp;
	int		l_len;
	int		endian;
}	t_img;

typedef struct s_game
{
	t_map		*map;
	t_img		*img;
	void		*mlx;
	void		*win;
	t_img		*screen;
	t_img		*n_sprite;
	t_img		*s_sprite;
	t_img		*e_sprite;
	t_img		*w_sprite;
	t_vector	player;
	t_vector	direction;
	t_vector	plane;
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

/////////////////
// Game Module //
/////////////////

// Initialize
void	initialize_game(t_game *game);

// Run
void	run_game(t_game *game);

// Utils
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_vertical_line(t_img *img, int x, t_vector *start_end, int color);

// Raycasting
void	raycast(t_game *game);

// End
int		close_window(void *p);

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

#endif
