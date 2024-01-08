/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:53:33 by stan              #+#    #+#             */
/*   Updated: 2022/04/17 17:53:40 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

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
			if (solve(tab, argv, y, x + 1))
				return (1);
		}
		tab[cor[1]][cor[0]] = 0;
		val++;
	}
	return (0);
}
