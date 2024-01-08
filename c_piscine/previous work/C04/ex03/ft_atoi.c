/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:28:27 by stan              #+#    #+#             */
/*   Updated: 2022/04/19 13:36:23 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	val;
	int	charge;

	i = 0;
	val = 0;
	charge = 1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = val * 10 + str[i] - '0';
		else if (str[i - 1] >= '0' && str[i - 1] <= '9')
			break ;
		else if (str[i] == '-')
			charge *= -1;
		else if (str[i] != '+')
			charge = 1;
		i++;
	}
	return (val * charge);
}
