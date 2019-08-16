#include "get_next_line.h"

int	main(void)
{
	int 	fd;
	char 	*line;

	fd = 0;
	while(get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	close(fd);
	return(0);

}