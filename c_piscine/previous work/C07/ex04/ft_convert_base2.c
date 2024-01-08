/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:37:52 by stan              #+#    #+#             */
/*   Updated: 2022/04/24 17:42:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	find_base(char *base);

void	ft_strcat(char *dest, char c)
{
	int	len;

	len = 0;
	while (dest[len])
		len++;
	dest[len++] = c;
	dest[len] = 0;
}

void	itoa_base(char *result, long nb, char *base, long len)
{
	if (nb >= len)
		itoa_base(result, nb / len, base, len);
	ft_strcat(result, base[nb % len]);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	value;
	long int	len_to;
	char		*result;

	result = malloc(128);
	*result = 0;
	len_to = find_base(base_to);
	if (len_to <= 1 || find_base(base_from) <= 1)
		return (0);
	value = ft_atoi_base(nbr, base_from);
	if (value < 0)
	{
		result[0] = '-';
		result[1] = 0;
		value = -value;
	}
	itoa_base(result, value, base_to, len_to);
	return (result);
}

#include <stdio.h>
int main()
{
	printf("%s", ft_convert_base("7FFFFFFF", "0123456789ABCDEF", "01"));
}