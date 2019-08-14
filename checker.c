/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:48:06 by dlinde            #+#    #+#             */
/*   Updated: 2019/08/14 12:23:57 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	*s(int *a, int *b, char *str)
{
	int tmp;

	if ((ft_strcmp(str, "sa") || ft_strcmp(str,"ss")) && a[0] && a[1])
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	if ((ft_strcmp(str, "sb") || ft_strcmp(str, "ss")) && b[0] && b[2])
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
	return (a);
}

int	main(int ac, char **av)
{
	int 	list[ac - 1];
	int		b[ac - 1];
	int 	fd;
	int		n;
	int		i;
	char	*line;

	n = 0;
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
			s(list, b, line);
			ft_putendl(line);
			free(line);
		}
		i = 0;
		while (i <= ac - 2)
		{
			ft_putnbr(list[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
