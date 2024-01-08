/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaw <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:42:06 by schaw             #+#    #+#             */
/*   Updated: 2022/04/19 15:47:28 by schaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size);
int				ft_strlen(char *str);

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	dlen;
	char			*d;
	char			*s;

	d = dst;
	s = src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}	
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

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
