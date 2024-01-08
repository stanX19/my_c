/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:44:47 by stan              #+#    #+#             */
/*   Updated: 2022/04/20 15:45:30 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_solved = 0;

int	is_valid(char *columns, char val, int len)
{
	int	i;

	i = 0;
	while (columns[i])
	{
		if (columns[i] == val)
			return (0);
		if ((len - i) == (val - columns[i]) || (len - i) == -(val - columns[i]))
			return (0);
		i++;
	}
	return (1);
}

int	solve(char *columns)
{
	int	len;
	int	i;

	len = -1;
	while (columns[len++ + 1])
		;
	if (len == 10)
	{
		write(1, columns, 10);
		write(1, "\n", 1);
		g_solved += 1;
		return (0);
	}
	i = '0';
	while (i <= '9')
	{
		if (is_valid(columns, i, len))
		{
			columns[len] = i;
			solve(columns);
		}
		columns[len] = 0;
		i++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	char	col[10];
	int		i;

	i = 0;
	while (i < 10)
		col[i++] = 0;
	solve(col);
	return (g_solved);
}
