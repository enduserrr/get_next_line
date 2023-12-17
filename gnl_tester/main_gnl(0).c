#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *line;

	printf("Enter text (press Ctrl+D to end):\n");
	while ((line = get_next_line(STDIN_FILENO)) != NULL)
	{
		printf("Line read: %s\n", line);
		free(line);
	}
	printf("End of input\n");
	return (0);
}
