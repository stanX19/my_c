#include <unistd.h>

void	ft_putchar(int i, int j, int x, int y);

void	rush03(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j <= y)
	{
		while (i <= x)
			ft_putchar(i++, j, x, y);
		write (1, "\n", 1);
		i = 1;
		j ++;
	}
}
