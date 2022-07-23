/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:09:53 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/07/23 19:44:33 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_keys(int key, void *p)
{
	t_game		*game;

	game = (t_game *)p;
	if (key == W_KEY)
		move_player_forward(game);
	else if (key == S_KEY)
		move_player_backward(game);
	else if (key == A_KEY)
		move_player_left(game);
	else if (key == D_KEY)
		move_player_right(game);
	else if (key == ESC_KEY)
		end_game(game);
	printf("Pressed Key=%d\n", key);
	clear_view(game);
	set_view(game);
	return (0);
}

int	handle_buttons(void *p)
{
	t_game		*game;

	game = (t_game *)p;
	end_game(game);
	return (0);
}

int	handle_minimize(void *p)
{
	t_game	*game;

	game = (t_game *) p;
	set_view(game);
	return (0);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->win, KEY_PRESS_EV, KEY_PRESS_MASK, &handle_keys, game);
	mlx_hook(game->win, X_BUTTON_EV, NO_MASK, &handle_buttons, game);
	mlx_hook(game->win, FOCUS_EV, FOCUS_MASK, &handle_minimize, game);
}
