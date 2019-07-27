/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:42:52 by apappas           #+#    #+#             */
/*   Updated: 2019/07/04 16:55:42 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_strccpy(const char *src, char *dest, char delim)
{
	if (!*src || delim)
		return ;
	while (*src != delim)
		*dest++ = *src++;
}

