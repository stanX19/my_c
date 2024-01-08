/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:52:28 by stan              #+#    #+#             */
/*   Updated: 2022/04/19 13:52:30 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (i);
}

int	find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	val;
	int	charge;
	int	len;

	charge = 1;
	val = 0;
	i = 0;
	len = find_base(base);
	while (str[i])
	{
		if (find(base, str[i]) != -1)
			val = val * len + find(base, str[i]);
		else if (find(base, str[i - 1]) != -1)
			break ;
		else if (str[i] == '-')
			charge *= -1;
		else if (str[i] != '+')
			charge = 1;
		i++;
	}
	return (val * charge);
}
