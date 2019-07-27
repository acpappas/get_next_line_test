/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:56:02 by apappas           #+#    #+#             */
/*   Updated: 2019/06/24 08:29:35 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split(char const *s, char c, char **splstr, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(s + 1) != '\0' && i < count)
	{
		while (*s == c && *(s + 1) != '\0')
			s++;
		*(splstr + i) = (char *)malloc(sizeof(char) * (ft_wlength(s, c) + 1));
		while (*s != c && *s)
		{
			*(*(splstr + i) + j) = *s;
			s++;
			j++;
		}
		*(*(splstr + i) + j) = '\0';
		i++;
		j = 0;
	}
	*(splstr + i) = 0;
	return (splstr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**splstr;
	int		count;

	count = 0;
	if (!s)
		return (NULL);
	count = ft_wcount(s, c);
	splstr = ((char **)malloc(sizeof(char *) * (count + 1)));
	if (splstr == NULL)
		return (NULL);
	splstr = ft_split(s, c, splstr, count);
	return (splstr);
}
