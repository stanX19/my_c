/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:39:30 by joshua            #+#    #+#             */
/*   Updated: 2022/04/19 18:23:40 by schaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *tofind);
int		ft_strncmp(char *a, char *b, unsigned int n);
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

char	*ft_strstr(char *str, char *tofind)
{
	int	i;
	int	j;
	int	n;

	if (*tofind == '\0')
		return (str);
	n = ft_strlen(str);
	j = ft_strlen(tofind);
	i = 0;
	while ((*str != '\0') && ((n - i) >= j))
	{
		if (ft_strncmp(str + i, tofind, j) == 0)
			return (str + i);
		i++;
	}		
	return (NULL);
}

int	ft_strncmp(char *a, char *b, unsigned int n)
{
	while ((n > 0) && (*a != '\0') || (*b != '\0'))
	{
		if (*a < *b)
			return (-1);
		else if (*a > *b)
			return (1);
		a++;
		b++;
		n--;
	}
	return (0);
}
