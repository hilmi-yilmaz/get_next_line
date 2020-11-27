#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	int buff[BUFFER_SIZE];
	int result;

	fd = open("text_eof.txt", O_RDONLY);
	result = read(fd, buff, BUFFER_SIZE);
	printf("result = %d\n", result);
	result = read(fd, buff, BUFFER_SIZE);
	printf("result = %d\n", result);
	return (0);
}
