/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:54:31 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/03/11 22:54:32 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	look_checklist(int *checklist, t_element elem)
{
	int	n;

	n = 0;
	if (elem == NO)
		n = 2;
	else if (elem == SO)
		n = 4;
	else if (elem == EA)
		n = 8;
	else if (elem == WE)
		n = 16;
	else if (elem == C)
		n = 32;
	else if (elem == F)
		n = 64;
	if (*checklist & n)
		return (1);
	return (0);
}

int	update_checklist(int *checklist, t_element elem)
{
	int	n_to_update;

	n_to_update = 0;
	if (elem == NO)
		n_to_update = 2;
	else if (elem == SO)
		n_to_update = 4;
	else if (elem == EA)
		n_to_update = 8;
	else if (elem == WE)
		n_to_update = 16;
	else if (elem == C)
		n_to_update = 32;
	else if (elem == F)
		n_to_update = 64;
	if (*checklist & n_to_update)
		*checklist |= 1;
	else
		*checklist |= n_to_update;
	return (1);
}
