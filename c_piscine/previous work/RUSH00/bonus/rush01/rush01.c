/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:27:03 by stan              #+#    #+#             */
/*   Updated: 2022/04/10 11:32:40 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i, int j, int x, int y);

void	rush01(int x, int y)
{
	int	i;
	int	j;

	if (x < 1 || y < 1)
	{
		write(1, "jokes on you we are prepared for this", 37);
		return ;
	}
	j = 1;
	i = 2;
	write(1, "/", 1);
	while (j <= y)
	{
		while (i <= x)
			ft_putchar(i++, j, x, y);
		write(1, "\n", 1);
		i = 1;
		j++;
	}
}
