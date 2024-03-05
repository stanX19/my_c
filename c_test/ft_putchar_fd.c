#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char* s, int fd)
{
	while (*s)
		ft_putchar_fd(*(s++), fd);
}

int main(int argc, char**argv) {
	int i = 1;
	//unlink("test.txt"); to delete
	//O_APPEND to append
	//O_TRUNC to trunctuate to len 0
	//O_CREAT to create when not exists
	int fd = open("test.txt", O_TRUNC | O_RDWR);
	if (fd == -1)
		write(1, "...nope it didnt work\n", 22);
	while (i < argc) {
		ft_putstr_fd(argv[i++], fd);
		ft_putchar_fd('\n', fd);
	}
	close(fd);
}