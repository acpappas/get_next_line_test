/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:26:23 by apappas           #+#    #+#             */
/*   Updated: 2019/06/27 11:31:01 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char nptr)
{
	if (nptr == '-' || nptr == '+')
		if (nptr == '-')
			return (-1);
	return (1);
}

int			ft_atoi(const char *nptr)
{
	int res;
	int i;
	int neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		neg = ft_sign(nptr[i]);
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res *= neg);
}
