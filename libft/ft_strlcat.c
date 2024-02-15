/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:34:03 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 20:18:08 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;

	i = 0;
	dlen = ft_strlen(dst);
	if (dstsize < dlen + 1)
		return (dstsize + ft_strlen(src));
	while (i < (dstsize - dlen - 1) && src[i])
	{
		dst[i + dlen] = src[i];
		++i;
	}
	dst[i + dlen] = '\0';
	return (dlen + ft_strlen(src));
}
