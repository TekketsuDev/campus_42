#include "get_next_line.h"
#define BUFFER_SIZE = 4
char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	char *buffer[BUFFER_SIZE];

	while(1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE + 1;
		if (!bytes_read)
			return (NULL);
		
	}
}

int main()
{
	int fd;
	char *line;

	int fd = open("example.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
    return 1;
}
