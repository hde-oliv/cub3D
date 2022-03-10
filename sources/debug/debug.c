#include "cub3D.h"

void	print_element(char **tmp)
{
	printf("--- ELEMENT ---\n" "TYPE: %s\n" "VALUE: %s\n" "---------------\n", tmp[0], tmp[1]);
}

void	print_map(t_list *lines)
{
	printf("MAP ----------\n\n");
	while (lines)
	{
		printf("%s\n", (char *) lines->content);
		lines = lines->next;
	}
	printf("\n--------------\n");
}

void 	print_rows(char **rows)
{
	int	i;

	i = 0;
	printf("ROWS ----------\n\n");
	while (rows[i])
	{
		printf("%s\n", rows[i++]);
	}
	printf("\n---------------\n");
}
