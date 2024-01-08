/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:04:49 by stan              #+#    #+#             */
/*   Updated: 2022/04/23 20:08:39 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	len;
	long	i;

	if (max < min)
	{
		*range = ((void *)0);
		return (0);
	}
	len = max - min;
	*range = malloc(len * 4 + 4);
	i = 0;
	while (i < len)
		(*range)[i++] = min++;
	return (len);
}
