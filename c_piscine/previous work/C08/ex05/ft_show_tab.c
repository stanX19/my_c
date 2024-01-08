/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:39:22 by stan              #+#    #+#             */
/*   Updated: 2022/04/28 14:32:54 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	c = (nb % 10) + '0';
	if (nb > 10)
		ft_putnbr(nb / 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (*(par[i].str))
	{
		while (*(par[i].str))
			write(1, par[i].str++, 1);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		while (*par[i].copy)
			write(1, par[i].copy++, 1);
		write(1, "\n", 1);
		i++;
	}
}
