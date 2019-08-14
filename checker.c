/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:48:06 by dlinde            #+#    #+#             */
/*   Updated: 2019/08/14 11:44:41 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int 	list[ac - 1];
	int 	fd;
	int		n;
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
			ft_putendl(line);
			free(line);
		}
	}
}
