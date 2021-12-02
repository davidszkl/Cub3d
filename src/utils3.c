#include "utils.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (1);
	write(fd, s, ft_strlen(s));
	return (1);
}