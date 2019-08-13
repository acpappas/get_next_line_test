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

static char		*getfile(t_listg **stat, int fd)
{
	t_listg *find;
	t_listg	*new;

	if (!*stat)
		*stat = NULL;
	find = *stat;
	while (find)
	{
		if (find->fd == fd)
			return (find->content);
		find = find->next;
	}
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
		(*stat)->content = ft_strcpy((*stat)->content, (ptr + 1));
	}
	*stat = find;
	line = ft_strcpy(line, *temp);
	ft_strclr(*temp);
	return (line);
}

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
	free(&(temp)->content);
	/*free(&(temp)->fd);*/
	free(temp);
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
	if (!(temp = getfile(&stat, fd)))
		return (-1);
	while ((readret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[readret] = '\0';
		if (! (temp = ft_strjoin(temp, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
		ft_strclr(buf);
	}
	if (readret < 0)
	{
		to_free(&stat, fd);
		return (-1);
	}
	if (readret > 0 || ft_strlen(temp) > 0)
	{
		*line = get_line(&temp, &stat, fd);
		return (1);
	}
	
	return (0);
}
