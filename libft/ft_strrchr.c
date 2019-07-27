/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 08:07:52 by apappas           #+#    #+#             */
/*   Updated: 2019/06/19 08:15:09 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*nptr;
	int		i;

	i = ft_strlen(s);
	nptr = NULL;
	while (*s)
		s++;
	while (i >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		i--;
	}
	if (*s == c)
		return ((char *)s);
	return (nptr);
}
