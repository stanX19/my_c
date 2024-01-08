/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:58:09 by stan              #+#    #+#             */
/*   Updated: 2022/04/19 16:58:11 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int fibonacci(int n)
{
    static int hash[1000];
    if (n <= 1)
        return 1;
    if (hash[n])
        return hash[n];
    hash[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return hash[n];
}
