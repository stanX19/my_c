/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:39:30 by joshua            #+#    #+#             */
/*   Updated: 2022/04/15 11:26:24 by schaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);

int	ft_strlen(char *str)
{
	char	*temp;
	int		len;

	len = 0;
	temp = str;
	while (*temp != '\0')
	{
		temp++;
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = ft_strlen(dest);
	while (*src != '\0')
	{
		*(dest + i) = *src;
		src++;
		i++;
	}		
	*(dest + i) = '\0';
	return (dest);
}
