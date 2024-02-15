/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:58:14 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 13:16:49 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	idx = 0;
	while (idx + needle_len <= len && haystack[idx])
	{
		if (ft_strncmp(haystack + idx, needle, needle_len) == 0)
			return ((char *)haystack + idx);
		++idx;
	}
	return (0);
}
