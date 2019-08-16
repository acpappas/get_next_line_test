/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apappas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 10:39:38 by apappas           #+#    #+#             */
/*   Updated: 2019/07/30 14:27:17 by apappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		to_free(t_listg **stat, int fd)
{
	t_listg	*find;
	t_listg	*temp;

	find = *stat;
	if (*stat == NULL)
		return ;
	while (find->next->fd != fd)
	{
		if (find->next == NULL)
			return ;
		find = find->next;
	}
	temp = find->next;
	find->next = find->next->next;
	free(temp->content);
	temp = NULL;
}

static char		*getfile(t_listg **stat, int fd)
{
	t_listg *find;
	t_listg	*new;

	find = *stat;
	while (find)
	{
		if (find->fd == fd)
			return (find->content);
		find = find->next;
	}
	if (!*stat)
		*stat = NULL;
	new = (t_listg *)ft_memalloc(sizeof(t_listg));
	new->content = ft_strnew(0);
	new->fd = fd;
	new->next = *stat;
	*stat = new;
	return (new->content);
}

static char		*get_line(char **temp, t_listg **stat, int fd)
{
	char	*ptr;
	char	*line = NULL;
	t_listg	*find;

	line = ft_strnew(0);
	find = *stat;
	(*stat)->content = getfile(stat, fd);
	if ((ptr = ft_strchr(*temp, '\n')))
	{
		*ptr = '\0';
		line = ft_strcpy(line, *temp);
		(*stat)->content = ft_strcpy((*stat)->content, (ptr + 1));
		*stat = find;
		ft_strclr(*temp);
		return (line);	
	}
	*stat = find;
	line = ft_strcpy(line, *temp);
	ft_strclr(*temp);
	ft_strclr((*stat)->content);
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	static t_listg	*stat;
	char			*temp;
	char			buf[BUFF_SIZE + 1];
	int				readret;

	if (fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (!(temp = ft_strdup(getfile(&stat, fd))))
		return (-1);
	while ((readret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[readret] = '\0';
		if (!(temp = ft_strjoin(temp, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (readret < 0)
	{
		to_free(&stat, fd);
		return (-1);
	}
	if (readret < BUFF_SIZE && !ft_strlen(temp))
	{
		ft_strclr(temp);
		return (0);
	}
	*line = get_line(&temp, &stat, fd);
	return (1);
}
