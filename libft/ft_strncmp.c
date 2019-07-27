/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:06:36 by apappas           #+#    #+#             */
/*   Updated: 2019/06/12 08:38:14 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	if ((unsigned char)*s1 - (unsigned char)*s2 < 0)
		return (-1);
	else if ((unsigned char)*s1 - (unsigned char)*s2 > 0)
		return (1);
	else
		return (0);
}
