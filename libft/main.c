#include "libft.h"
#include "get_next_line_bonus.h"
#include "ft_printf.h"
#include <fcntl.h>

int	main()
{
	int	fd;
	char	*line;

	ft_printf("Test GNL :\n");
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	ft_printf("End of program.\n");
	return (0);
}
