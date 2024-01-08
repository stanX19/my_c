/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:33:50 by stan              #+#    #+#             */
/*   Updated: 2022/04/18 18:33:54 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_max_negative(long int nbr, char *base, int len)
{
	if (nbr >= len)
		ft_max_negative(nbr / len, base, len);
	write(1, &base[(nbr % len)], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long int	max;

	len = -1;
	while (base[len++ + 1])
		;
	if (!is_valid(base, len + 1))
		return ;
	if (nbr < 0)
	{
		max = nbr;
		write(1, "-", 1);
		if (nbr <= -2147483648)
			return (ft_max_negative(-max, base, len));
		nbr = -nbr;
	}
	if (nbr >= len)
		ft_putnbr_base(nbr / len, base);
	write(1, &base[nbr % len], 1);
}
