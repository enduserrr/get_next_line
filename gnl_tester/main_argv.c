#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *line;
	int fd;
	
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s file1 file2 ...\n", argv[0]);
		return (1);
		}
	for (int i = 1; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			continue; // Skip to the next file
			}
		printf("FILE: %s\n", argv[i]);
		while (1)
		{
			line = get_next_line(fd);
			if (line)
			printf("%s", line);
				else
			{
				printf("\nEOL: %s\n", argv[i]);
				break;
				}
			free(line);
		}
		close(fd);
	}
	if (system("leaks a.out > /dev/null"))
		system("leaks a.out");
	return (0);
}
