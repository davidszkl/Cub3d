#include "cub3d.h"
#include "utils.h"

void	ft_showtab(char **tab)
{
	int	n;

	n = 0;
	if (!tab)
		return ;
	while (tab[n])
	{
		write(1, tab[n], ft_strlen(tab[n]));
		n++;
	}
	write(1, "\n", 1);
}