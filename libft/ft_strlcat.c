/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 08:08:16 by apappas           #+#    #+#             */
/*   Updated: 2019/06/27 11:27:37 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (dest[i] && len < size)
	{
		i++;
		len++;
	}
	while (src[j] && len + 1 < size)
	{
		dest[len] = src[j];
		j++;
		len++;
	}
	if (len < size)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}
