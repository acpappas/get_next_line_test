/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:16:42 by apappas           #+#    #+#             */
/*   Updated: 2019/06/27 11:19:47 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;

	sa = (const unsigned char *)s1;
	sb = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*sa != *sb)
			return (*sa - *sb);
		sa++;
		sb++;
		n--;
	}
	return (0);
}
