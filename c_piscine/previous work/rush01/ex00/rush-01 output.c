/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:54:10 by stan              #+#    #+#             */
/*   Updated: 2022/04/17 17:54:11 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

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
