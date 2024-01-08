#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"
int	g_n;

int	**allocate_array(int n)
{
	int	**p;
	int	*p2;
	int	i;

	p = malloc(sizeof(int *) * n);
	i = 0;
	while (i < n)
	{
		p2 = malloc(sizeof(int) * n);
		p[i] = p2;
		i++;
	}
	return (p);
}	

void	write_nb(int nb)
{
	char	c;

	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb > 9)
		write_nb(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	print_table(int **tab, int len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < len)
	{
		while (n < len)
		{
			write_nb(tab[i][n++]);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
		n = 0;
		i++;
	}
}

int	scan(int *arr, int n)
{
	int	i;
	int	val;
	int	max;

	i = 0;
	val = 0;
	max = 0;
	if (arr[i] == n)
		return (1);
	while (i < n)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			val += 1;
		}
		i++;
	}
	return (val);
}

int	rev_scan(int *arr, int n)
{
	int	i;
	int	val;
	int	max;

	i = n - 1;
	val = 0;
	max = 0;
	if (arr[i] == n)
		if (arr[i] == n)
			return (1);
	while (i >= 0)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			val += 1;
		}
		i--;
	}
	return (val);
}
//int x = cor[0];
//int y = cor[1];
//bot = argv[(2*g_n)
//left = argv[(2 * g_n) + cor[1]];
//right = argv[(3 * g_n) + cor[1]];

int	follow_rule(int **tab, int *argv, int cor[2], int val)
{
	int	i;
	int	*column;

	column = malloc(g_n * 4);
	i = -1;
	tab[cor[1]][cor[0]] = val;
	while (i++ < g_n - 1)
		column[i] = tab[i][cor[0]];
	if (cor[0] == g_n - 1 && (scan(tab[cor[1]], g_n) != argv[(2 * g_n) + cor[1]]
			|| rev_scan(tab[cor[1]], g_n) != argv[(3 * g_n) + cor[1]]))
	{
		tab[cor[1]][cor[0]] = 0;
		return (0);
	}
	if (cor[1] == g_n - 1 && (scan(column, g_n) != argv[cor[0]]
			|| rev_scan(column, g_n) != argv[cor[0] + g_n]))
	{
		tab[cor[1]][cor[0]] = (0);
		return (0);
	}
	return (1);
}

int	is_valid(int **tab, int *argv, int cor[2], int val)
{
	int	i;
	int	y;

	y = cor[1];
	i = 0;
	while (i < g_n)
	{
		if (tab[y][i++] == val)
			return (0);
	}
	i = 0;
	while (i < g_n)
	{
		if (tab[i++][cor[0]] == val)
			return (0);
	}
	i = 0;
	if (!follow_rule(tab, argv, cor, val))
		return (0);
	return (1);
}

void	next_row(int *x, int *y)
{
	*x = 0;
	*y = *y + 1;
}

int	solve(int **tab, int *argv, int y, int x)
{
	int	val;
	int	cor[2];

	if ((y == g_n - 1) && (x == g_n))
		return (1);
	if (x == g_n)
		next_row(&x, &y);
	if (tab[y][x] > 0)
		return (solve(tab, argv, y, x + 1));
	val = 1;
	while (val <= g_n)
	{
		cor[0] = x;
		cor[1] = y;
		if (is_valid(tab, argv, cor, val))
		{
			tab[cor[1]][cor[0]] = val;
			if (solve(tab, argv, cor[1], cor[0]))
				return (1);
		}
		tab[cor[1]][cor[0]] = 0;
		val++;
	}
	return (0);
}

int	*split_to_i(char *str)
{
	int	*result;
	int	i;
	int	len;

	i = 0;
	len = 0;
	result = malloc(100 * 4);
	while (str[i])
	{
		if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == ' ')
			&& str[i] <= '9' && str[i] >= '0')
			result[len++] = str[i] - '0';
		else if (str[i] <= '9' && str[i] >= '0')
			result[len - 1] = ((result[len - 1] * 10 + str[i]) - '0');
		i++;
	}
	return (result);
}

int	main(int argc, char **arg)
{
	int	*argv;
	int	len;
	int	**tab;

	if (argc != 2)
	{
		write(1, "Error, more than one arguement given\n", 37);
		return (0);
	}
	argv = split_to_i(arg[1]);
	len = 0;
	while (argv[len++ + 1])
	{
	}
	if (len % 4 != 0)
		write(1, "invlid input, check for missing space or number\n", 48);
	g_n = len / 4;
	tab = allocate_array(g_n);
	if (solve(tab, argv, 0, 0))
	{
		print_table(tab, g_n);
	}
	else
		write(1, "No solution\n", 12);
	free(tab);
}
