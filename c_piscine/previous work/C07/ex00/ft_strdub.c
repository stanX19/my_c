/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:19:54 by stan              #+#    #+#             */
/*   Updated: 2022/04/20 18:19:55 by stan             ###   ########.fr       */
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
	len = 0;
	while (src[len])
	{
		ptr[len] = src[len];
		len++;
	}
	ptr[len] = 0;
	return (ptr);
}
