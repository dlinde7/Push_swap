/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlinde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:49:15 by dlinde            #+#    #+#             */
/*   Updated: 2019/05/23 11:50:49 by dlinde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int n;

	n = 0;
	while (s[n] != '\0')
	{
		if (s[n] == (char)c)
			return ((char *)s + n);
		n++;
	}
	if (s[n] == '\0' && (char)c == '\0')
		return ((char *)s + n);
	return (0);
}
