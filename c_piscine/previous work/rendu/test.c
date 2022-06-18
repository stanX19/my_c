#include <unistd.h>

void	ft_putchar(char c)
{
	c = c + 48;
	write(1, &c, 1);
}

int	main(void)
{
	int nb;

	nb = 1;
	while (nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			if (nb > 10)
			{
				ft_putchar(nb / 10);
				ft_putchar(nb % 10);
			}
			else
				ft_putchar(nb);
		}
		nb++;
		write(1, "\n", 1);
	}
}
