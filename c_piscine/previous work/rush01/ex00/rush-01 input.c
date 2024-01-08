/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:53:25 by stan              #+#    #+#             */
/*   Updated: 2022/04/17 17:53:26 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

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

int	*split_to_i(char *str)
{
	int	*result;
	int	i;
	int	len;

	i = 0;
	len = 0;
	result = malloc(101 * 4);
	while (str[i])
	{
		if ((i == 0 || str[i - 1] == ' ' || str[i - 1] == ' ')
			&& str[i] <= '9' && str[i] >= '0')
			result[len++] = str[i] - '0';
		else if (str[i] <= '9' && str[i] >= '0')
			result[len - 1] = ((result[len - 1] * 10 + str[i]) - '0');
		i++;
	}
	result[len] = -1;
	return (result);
}
