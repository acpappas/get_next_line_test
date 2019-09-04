#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	int		ret1;
	int		ret2;
	int		i = 1;
	
	while (i <2)
	{	
	if (argc == 1)
		fd1 = 0;
	else if (argc == 2)
		fd1 = open(argv[1], O_RDONLY);
	else if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
	}
	else
		return (2);
	while ((ret2 = get_next_line(fd2, &line2) == 1))
			{
				
				ft_putendl(line2);
				free(line2);
			}
	while ((ret1 = get_next_line(fd1, &line1) == 1))
		{
			ft_putendl(line1);
			free(line1);
		}		
		if (argc == 2)
		close(fd1);
		if (argc == 3)
		{
			close(fd1);
			close(fd2);
		}
		i++;
	}
	return (0);
}