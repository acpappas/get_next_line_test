/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:52:44 by apappas           #+#    #+#             */
/*   Updated: 2019/06/27 12:35:51 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find_res(int n, size_t i)
{
	char	*res;
	int		neg;

	neg = 0;
	res = (ft_strnew(i));
	if (!res)
		return (0);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (i)
	{
		res[--i] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	size_t	i;

	i = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	res = ft_find_res(n, i);
	return (res);
}
