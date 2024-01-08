#include <unistd.h>

void	ft_putchar(int i, int j, int x, int y)
{
	if (i == 1)
	{
		if ((j == 1) || (j == y))
			write (1, "A", 1);
		else
			write (1, "B", 1);
	}
	else if (i == x)
	{
		if ((j == 1) || (j == y))
			write (1, "C", 1);
		else
			write (1, "B", 1);
	}
	else
	{
		if ((j == 1) || (j == y))
			write (1, "B", 1);
		else
			write (1, " ", 1);
	}
}
