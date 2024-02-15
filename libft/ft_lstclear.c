/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:49:25 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 22:27:20 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*curr;

	if (!lst)
		return ;
	curr = *lst;
	while (curr != 0)
	{
		tmp = curr;
		curr = curr->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}
