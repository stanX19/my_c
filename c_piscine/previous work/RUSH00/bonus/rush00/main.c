/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:23:36 by shatan            #+#    #+#             */
/*   Updated: 2024/01/14 15:39:07 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		ft_atoi(const char *str);
void	ft_putstr(const char *str);
int		run_with_argv(const char **argv);
void	print_usage(const char *message, const char *program_name);

int	main(int argc, const char **argv)
{
	if (argc == 1)
	{
		rush(5, 3);
		return (0);
	}
	if (argc < 3)
	{
		print_usage("Error: too few arguments\n", argv[0]);
		return (1);
	}
	if (argc > 3)
	{
		print_usage("Error: too many arguments\n", argv[0]);
		return (1);
	}
	return (run_with_argv(argv));
}

int	run_with_argv(const char **argv)
{
	int	x;
	int	y;

	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (x < 1 || y < 1)
	{
		ft_putstr("Error: Invalid size: (");
		ft_putstr(argv[1]);
		ft_putstr(", ");
		ft_putstr(argv[2]);
		print_usage(")\n", argv[0]);
		return (1);
	}
	rush(x, y);
	return (0);
}

void	print_usage(const char *message, const char *program_name)
{
	ft_putstr(message);
	ft_putstr("\nUsage: ");
	ft_putstr(program_name);
	ft_putstr(" <width> <height>\n");
	ft_putstr("Generate a pattern of characters with the ");
	ft_putstr("specified widthand height.\n");
	ft_putstr("\n");
	ft_putstr("Arguments:\n");
	ft_putstr("  <width>   Positive integer representing ");
	ft_putstr("the width of the pattern.\n");
	ft_putstr("  <height>  Positive integer representing the ");
	ft_putstr("height of the pattern.\n");
	ft_putstr("\n");
	ft_putstr("Example:\n");
	ft_putstr("  ");
	ft_putstr(program_name);
	ft_putstr(" 5 3\n");
	ft_putstr("\n");
	ft_putstr("Note:\n");
	ft_putstr("  - Width and height must be positive integers.\n");
	ft_putstr("  - Width and height must fit in a 32-bit signed int\n");
	ft_putstr("  - The pattern will be generated based on the ");
	ft_putstr("provided width and height.\n\n");
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i++] - '0');
		if (nb > 0x7FFFFFFFL + (sign == -1))
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	return ((int)nb * sign);
}
