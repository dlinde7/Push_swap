/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:48:06 by dlinde            #+#    #+#             */
/*   Updated: 2019/08/16 12:46:51 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

void	s(int *a, int *b, char *str)
{
	int tmp;

	if ((ft_strequ(str, "sa") || ft_strequ(str, "ss")) && a[0] && a[1])
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	if ((ft_strequ(str, "sb") || ft_strequ(str, "ss")) && b[0] && b[2])
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

	if (ft_strequ(str, "pa") && x != 0)
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
	if (ft_strequ(str, "pb") && n - x != 0)
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

	if ((ft_strequ(str, "rra") || ft_strequ(str, "rrr")) && n - x != 0)
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
	if ((ft_strequ(str, "rrb") || ft_strequ(str, "rrr")) && x != 0)
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

	if ((ft_strequ(str, "ra") || ft_strequ(str, "rr")) && n - x != 0)
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
	if ((ft_strequ(str, "rb") || ft_strequ(str, "rr")) && x != 0)
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

int		checker(int *a, int x, int n)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		while (i < n)
		{
			if (a[i] < a[i + 1])
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int 		list[ac - 1];
	int			b[ac - 1];
	int 		fd;
	int			n;
	char		*line;

	n = 0;
	if (ac != 1)
	{
		while (n <= ac - 2)
		{
			if ((list[n] = ft_atoi(av[n + 1])) || ft_strequ(av[n + 1], "0"))
				n++;
			else
			{
				ft_putendl("Error");
				exit(0);
			}
		}
		fd = open("com", O_RDONLY);
		n = 0;
		while (get_next_line(fd, &line) == 1)
		{
			if (line[0] == 's')
				s(list, b, line);
			else if (line[0] == 'p')
				n = p(list, b, line, n, ac - 1);
			else if (line[0] == 'r' && line[1] == 'r' && line[2] != '\0')
				rr(list, b, line, n, ac - 1);
			else
				r(list, b, line, n, ac - 1);
			ft_putendl(line);
			free(line);
		}
		if (checker(list, n, ac - 2))
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
}
