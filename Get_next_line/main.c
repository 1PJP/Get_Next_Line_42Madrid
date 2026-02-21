#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		return 0;
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
