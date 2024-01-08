/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:39:30 by joshua            #+#    #+#             */
/*   Updated: 2022/04/15 12:19:55 by schaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int n);
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

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	int	i;

	i = ft_strlen(dest);
	while ((*src != '\0') && (n > 0))
	{
		*(dest + i) = *src;
		src++;
		i++;
		n--;
	}		
	*(dest + i) = '\0';
	return (dest);
}
