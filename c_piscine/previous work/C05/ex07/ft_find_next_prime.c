/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:44:01 by stan              #+#    #+#             */
/*   Updated: 2022/04/23 16:31:04 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb > 2147483628)
		return (0);
	if (nb < 1)
		nb = 1;
	nb += 1;
	if (nb <= 1)
		return (ft_find_next_prime(nb));
	i = 1;
	while (i++ < nb / 2)
	{
		if (nb % i == 0)
			return (ft_find_next_prime(nb));
	}
	return (nb);
}
