/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:11:49 by apappas           #+#    #+#             */
/*   Updated: 2019/06/27 11:18:41 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (char *)src;
	d = (char *)dest;
	if (d <= s)
		ft_memcpy(d, s, n);
	else
	{
		s += (n - 1);
		d += (n - 1);
		while (n > 0)
		{
			*d = *s;
			d--;
			s--;
			n--;
		}
	}
	return (dest);
}
