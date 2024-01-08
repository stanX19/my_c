/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01 main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:55:35 by stan              #+#    #+#             */
/*   Updated: 2022/04/17 17:55:37 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

int	main(int argc, char **arg)
{
	int	*argv;
	int	len;
	int	**tab;

	if (argc != 2)
	{
		write(1, "Error, more than one arguement given\n", 37);
		system("leaks rush-01");
		return (0);
	}
	argv = split_to_i(arg[1]);
	len = 0;
	while (argv[len++] != -1)
	;
	if (len % 4 != 0)
		write(1, "invlid input, check for missing space or number\n", 48);
	g_n = len / 4;
	tab = allocate_array(g_n);
	if (solve(tab, argv, 0, 0))
	{
		print_table(tab, g_n);
	}
	else
		write(1, "No solution\n", 12);
	len = 0;
	while (len < g_n)
		free(tab[len++]);
	free(tab);
	system("leaks rush-01");
	return (0);
}
