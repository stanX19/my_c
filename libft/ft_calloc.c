/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:34:49 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 13:29:09 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	a = malloc(count * size);
	if (!a)
		return (0);
	ft_bzero(a, (count * size));
	return (a);
}
