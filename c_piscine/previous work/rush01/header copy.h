/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:05:05 by stan              #+#    #+#             */
/*   Updated: 2022/04/17 18:05:08 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

int		g_n;

int		**allocate_array(int n);
void	write_nb(int nb);

void	print_table(int **tab, int len);
int		scan(int *arr, int n);
int		rev_scan(int *arr, int n);
int		follow_rule(int **tab, int *argv, int cor[2], int val);
int		is_valid(int **tab, int *argv, int cor[2], int val);
void	next_row(int *x, int *y);

int		solve(int **tab, int *argv, int y, int x);

int		*split_to_i(char *str);

#endif
