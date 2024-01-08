/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi <ssi@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:57:04 by ssi               #+#    #+#             */
/*   Updated: 2022/04/10 17:52:18 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i, int j, int x, int y);

void	rush02(int x, int y)
{
	int	i;
	int	j;

	if (x < 1 || y < 1)
	{
		write(1, "malu aper bossku", 16);
		return ;
	}
	j = 1;
	i = 1;
	while (j <= y)
	{
		while (i <= x)
			ft_putchar(i++, j, x, y);
		write(1, "\n", 1);
		i = 1;
		j++ ;
	}
}
