/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:37:48 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 16:35:03 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char delim)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] != delim && (idx == 0 || str[idx - 1] == delim))
		{
			++count;
		}
		++idx;
	}
	return (count);
}

char	**ft_split(char const *str, char delim)
{
	char	**ret;
	int		start_idx;
	int		idx;
	int		ret_idx;

	if (!str)
		return (0);
	ret = malloc(sizeof(char *) * (word_count(str, delim) + 1));
	if (!ret)
		return (0);
	idx = 0;
	ret_idx = 0;
	while (str[idx])
	{
		if (str[idx] != delim && (idx == 0 || str[idx - 1] == delim))
			start_idx = idx;
		else if (str[idx] == delim && (idx != 0 && str[idx - 1] != delim))
			ret[ret_idx++] = ft_substr(str, start_idx, idx - start_idx);
		idx++;
	}
	if (idx != 0 && str[idx - 1] != delim)
		ret[ret_idx++] = ft_substr(str, start_idx, idx - start_idx);
	ret[ret_idx] = 0;
	return (ret);
}
