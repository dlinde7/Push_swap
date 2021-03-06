/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:44:24 by dlinde            #+#    #+#             */
/*   Updated: 2019/05/23 11:47:04 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (s1[n] != '\0')
		n++;
	while (s2[i] != '\0')
	{
		s1[n] = s2[i];
		n++;
		i++;
	}
	s1[n] = '\0';
	return (s1);
}
