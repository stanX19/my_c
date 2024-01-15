/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:30:30 by shatan            #+#    #+#             */
/*   Updated: 2024/01/14 14:27:36 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOP "/*\\"
#define MID "* *"
#define BOT "\\*/"

void	ft_putchar(char c);

void	print_line(char start, char middle, char end, int width)
{
	int	i;

	ft_putchar(start);
	i = 1;
	while (i <= width - 2)
	{
		ft_putchar(middle);
		i++;
	}
	if (width > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	print_line(TOP[0], TOP[1], TOP[2], x);
	i = 1;
	while (i <= y - 2)
	{
		print_line(MID[0], MID[1], MID[2], x);
		i++;
	}
	if (y > 1)
		print_line(BOT[0], BOT[1], BOT[2], x);
}
