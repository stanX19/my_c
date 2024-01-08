/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:54:58 by stan              #+#    #+#             */
/*   Updated: 2022/04/18 14:23:33 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

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
	int	result;

	column = malloc(g_n * 4);
	i = -1;
	result = 1;
	tab[cor[1]][cor[0]] = val;
	while (i++ < g_n - 1)
		column[i] = tab[i][cor[0]];
	if (cor[0] == g_n - 1 && (scan(tab[cor[1]], g_n) != argv[(2 * g_n) + cor[1]]
			|| rev_scan(tab[cor[1]], g_n) != argv[(3 * g_n) + cor[1]]))
		result = 0;
	if (cor[1] == g_n - 1 && (scan(column, g_n) != argv[cor[0]]
			|| rev_scan(column, g_n) != argv[cor[0] + g_n]))
		result = 0;
	free(column);
	tab[cor[1]][cor[0]] = (0);
	return (result);
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
