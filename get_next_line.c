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

static char		*getfile(g_list **stat, int fd)
{
	g_list *find;
	g_list	*new;

	if (!*stat)
		*stat = NULL;
	find = *stat;
	while (find)
	{
		if (find->fd == fd)
			return (find->content);
		find = find->next;
	}
	new = (g_list *)ft_memalloc(sizeof(g_list));
	new->content = ft_strnew(0);
	new->fd = fd;
	new->next = *stat;
	*stat = new;
	return (new->content);
}

static	int		read_file(char **temp, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		readret;

	while ((readret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[readret] = '\0';
		*temp = ft_strjoin(*temp, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		ft_strclr(buf);
	}
	if (readret == 0 && !ft_strlen(*temp))
		return (0);
	else if (readret < 0)
		return (-1);
	else
		return (1);
}

static char		*get_line(char **temp, g_list **stat, int fd)
{
	char	*ptr;
	char	*line;
	g_list	*find;

	find = *stat;
	while (*stat)
	{
		if ((*stat)->fd == fd)
			break ;
		*stat = (*stat)->next;
	}
	if ((ptr = ft_strchr(*temp, '\n')))
	{
		*ptr = '\0';
		ft_strclr((*stat)->content);
		(*stat)->content = ft_strdup((ptr + 1));
	}
	*stat = find;
	line = ft_strdup(*temp);
	ft_strclr(*temp);
	return (line);
}

static void		to_free(g_list **stat, int fd)
{
	g_list	*find;
	g_list	*temp;

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
	free(&(temp)->content);
	free(&(temp)->fd);
	free(temp);
}

int				get_next_line(const int fd, char **line)
{
	static g_list	*stat;
	char			*temp;
	char			*buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(0);
	temp = getfile(&stat, fd);
	if ((read_file(&temp, fd)) > 0)
	{
		*line = get_line(&temp, &stat, fd);
		return (1);
	}
	to_free(&stat, fd);
	return (0);
}
