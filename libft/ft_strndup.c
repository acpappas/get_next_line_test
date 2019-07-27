/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:04:33 by apappas           #+#    #+#             */
/*   Updated: 2019/07/01 09:16:25 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	len;

	n += 1;
	len = ft_strlen(s1) + 1;
	if (len > n)
		len = n;
	dup = (char *)ft_memalloc(len);
	if (dup == 0)
		return (NULL);
	if (len == n)
		len = (n - 1);
	ft_memcpy(dup, s1, len);
	return (dup);
}
