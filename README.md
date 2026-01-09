#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	i = 1;
	int	fd = open("test_file.txt", O_RDONLY);
	char 	*line;
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		printf("NUMBER OF LINE BREAKS: %d\n", i++);
		free(line);
	}
	printf("END OF FILE (line = get_next_line(fd) == NULL\n");
	close(fd);
	return (0);
}
