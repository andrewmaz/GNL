/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:32:14 by amazurok          #+#    #+#             */
/*   Updated: 2017/12/07 18:21:37 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_realloc(char *str, int size)
{
	char *nstr;

	if (!(nstr = ft_strnew(size + 1)))
		return (NULL);
	if (str)
	{
		ft_memcpy(nstr, str, size);
		free(str);
	}
	return (nstr);
}

t_list *ft_newlst(int fd)
{
	t_list *lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	lst->content_size = fd;
	lst->content = NULL;
	lst->next = NULL;
	return (lst);
}

t_list *ft_add2list(t_list **list, size_t fd)
{
	t_list *lst;

	lst = *list;
	if (!(*list))
	{
		*list = ft_newlst(fd);
		return (*list);
	}
	while (lst->next && lst->content_size != fd)
		lst = lst->next;
	if (lst->content_size == fd)
		return (lst);
	else
	{
		lst->next = ft_newlst(fd);
		return (lst->next);
	}
}

char *ft_newline(char *str)
{
	int i;
	char *res;

	i = 0;
	while(str[i] && str[i - 1] != '\n')
		i++;
	res = ft_strnew(ft_strlen(str + i));
	res = ft_strcpy(res, str + i);
	ft_strdel(&str);
	return (res);
}

int ft_add2line(t_list *lst, char **line)
{
	int i;
	int len;

	i = 0;
	if (*line)
		len = ft_strlen(*line);
	else
		len = 0;
	while (lst->content && ((char*)lst->content)[i] && ((char*)lst->content)[i] != '\n')
		i++;
	if (i > 0)
	{
		*line = ft_realloc(*line, len + i);
		*line = ft_strcat(*line, ft_strsub(lst->content, 0, i));
	}
	if (lst->content && ((char*)lst->content)[i] == '\n')
	{
		if (!*line)
			*line = ft_strnew(0);
		lst->content = ft_newline(lst->content);
		return (1);
	}
	else
	{
		free(lst->content);
		lst->content = NULL;
		return (0);
	}
}

int get_next_line(const int fd, char **line)
{
	static t_list *head;
	int ret;
	char buf[BUFF_SIZE + 1];
	int size;
	t_list *qwe;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	size = 0;
	*line = NULL;
	qwe = ft_add2list(&head, (size_t)fd);
	if (ft_add2line(qwe, line))
		return (1);
	while((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		size += ret;
		qwe->content = ft_realloc(qwe->content, size);
		qwe->content = ft_strcat(((char*)qwe->content), buf);
		if (ft_add2line(qwe, line))
			return (1);
	}
	if (*line && line[0])
		return (1);
	else
		return (0);
}
