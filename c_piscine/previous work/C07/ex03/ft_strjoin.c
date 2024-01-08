/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:51:42 by stan              #+#    #+#             */
/*   Updated: 2022/04/24 14:54:35 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_arr_len(int size, char **strs)
{
	int	len;
	int	i;
	int	n;

	len = 0;
	i = 0;
	n = 0;
	while (n < size)
	{
		while (strs[n][i++])
			len++;
		i = 0;
		n++;
	}
	return (len);
}

void	ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	while (dest[len])
	{
		len++;
	}
	i = 0;
	while (src[i])
		dest[len++] = src[i++];
	dest[len] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		n;
	int		len;

	len = 0;
	while (sep[len])
		len++;
	len = len * (size) + str_arr_len(size, strs) + 1;
	result = malloc(len);
	*result = 0;
	if (size == 0)
		return (result);
	n = 0;
	while (n < size - 1)
	{
		ft_strcat(result, strs[n++]);
		ft_strcat(result, sep);
	}
	ft_strcat(result, strs[n]);
	result[len - 1] = 0;
	return (result);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	char	*c = ", ";
	argv++;
	char 	*join = ft_strjoin(argc - 1, argv, c);

	printf("%p\n", join);
	printf("%s\n", join);
	free(join);
	//system("leaks a.out");ß
	return 0;
}