/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:33 by stan              #+#    #+#             */
/*   Updated: 2022/04/27 20:34:41 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdub(char *src)
{
	char	*ptr;
	int		len;

	len = 0;
	while (src[len++])
		;
	ptr = malloc(len + 1);
	*ptr = 0;
	len = 0;
	while (src[len])
	{
		ptr[len] = src[len];
		len++;
	}
	ptr[len] = 0;
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str	*stock_arr;

	if (ac < 1)
		return ((void *)0);
	stock_arr = malloc((ac + 1) * sizeof(t_stock_str));
	i = 0;
	while (i < ac)
	{
		len = 0;
		while (av[i][len++])
			;
		stock_arr[i].size = len - 1;
		stock_arr[i].str = av[i];
		stock_arr[i].copy = ft_strdub(av[i]);
		i++;
	}
	stock_arr[i].str = "";
	return (stock_arr);
}
