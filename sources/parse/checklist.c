#include "cub3D.h"

void	update_checklist(int *checklist, char *elem)
{
	if (!ft_strncmp(elem, "NO", 3))
		*checklist |= 2;
	else if (!ft_strncmp(elem, "SO", 3))
		*checklist |= 4;
	else if (!ft_strncmp(elem, "EA", 3))
		*checklist |= 8;
	else if (!ft_strncmp(elem, "WE", 3))
		*checklist |= 16;
	else if (!ft_strncmp(elem, "C", 2))
		*checklist |= 32;
	else if (!ft_strncmp(elem, "F", 2))
		*checklist |= 64;
}
