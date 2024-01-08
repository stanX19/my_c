/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:30:53 by stan              #+#    #+#             */
/*   Updated: 2022/04/23 20:09:16 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long	len;
	int		*arr;
	long	i;

	if (max < min)
		return ((void *)0);
	len = max - min;
	arr = malloc(len * 4 + 4);
	i = 0;
	while (i < len)
		arr[i++] = min++;
	return (arr);
}
