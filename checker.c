/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:48:06 by dlinde            #+#    #+#             */
/*   Updated: 2019/08/15 17:00:41 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

void	s(int *a, int *b, char *str)
{
	int tmp;

	if ((ft_strcmp(str, "sa") || ft_strcmp(str,"ss")) && a[0] && a[1])
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	else if ((ft_strcmp(str, "sb") || ft_strcmp(str, "ss")) && b[0] && b[2])
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
}

int	p(int *a, int *b, char *str, int x, int n)
{
	int i;
	int z;

	if (ft_strcmp(str, "pb") && x != 0)
	{
		i = n - x;
		z = 0;
		while (i >= 0)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[0] = b[0];
		while (z < x - 1)
		{
			b[z] = b[z + 1];
			z++;
		}
		x--;
	}
	if (ft_strcmp(str, "pa") && n - x != 0)
	{
		i = x;
		z = 0;
		while (i >= 0)
		{
			b[i + 1] = b[i];
			i--;
		}
		b[0] = a[0];
		while (z < n - x)
		{
			a[z] = a[z + 1];
			z++;
		}
		x++;
	}
	return (x);
}

void	rr(int *a, int *b, char *str, int x, int n)
{
	int tmp;
	int	i;

	if ((ft_strcmp(str, "rra") || ft_strcmp(str,"rrr")) && n - x != 0)
	{
		i = n - x - 1;
		tmp = a[i];
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = tmp;
	}
	if ((ft_strcmp(str, "rrb") || ft_strcmp(str, "rrr")) && x != 0)
	{
		i = x - 1;
		tmp = b[i];
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = tmp;
	}
}

void	r(int *a, int *b, char *str, int x, int n)
{
	int tmp;
	int	i;

	if ((ft_strcmp(str, "ra") || ft_strcmp(str,"rr")) && n - x != 0)
	{
		i = 0;
		tmp = a[i];
		while (i < n - x - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[i] = tmp;
	}
	if ((ft_strcmp(str, "rb") || ft_strcmp(str, "rr")) && x != 0)
	{
		i = 0;
		tmp = b[i];
		while (i < x - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[i] = tmp;
	}
}

int		main(int ac, char **av)
{
	int 		list[ac - 1];
	int			b[ac - 1];
	int 		fd;
	int			x;
	int			n;
	int			i;
	char		*line;

	n = 0;
	x = 0;
	if (ac != 1)
	{
		while (n <= ac - 2)
		{
			if ((list[n] = ft_atoi(av[n + 1])))
				n++;
			else
			{
				ft_putendl("ERROR");
				exit(0);
			}
		}
		fd = open("com", O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			if (line[0] == 's')
				s(list, b, line);
			else if (line[0] == 'p')
				x = p(list, b, line, x, n);
			else if (line[0] == 'r' && line[1] == 'r' && line[2] != '\0')
				rr(list, b, line, x, n);
			else
				r(list, b, line, x, n);
			ft_putendl(line);
			free(line);
		}
		i = 0;
		while (i <= ac - 2)
		{
			ft_putnbr(list[i]);
			ft_putchar('	');
			ft_putnbr(b[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
