/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:32:14 by amazurok          #+#    #+#             */
/*   Updated: 2017/12/02 18:07:36 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str, int size)
{
	char *nstr;

	if (!(nstr = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	if (!(nstr = ft_strnew(size)))
		return (NULL);
	ft_memcpy(nstr, str, --size);
	if (str)
		free(str);
	return (nstr);
}

char *ft_stradd_end(char *f, char *end, int size)
{
	int i;
	int j;
	char *str;

	j = 0;
	i = 0;
	if(!f)
	{
		str = ft_strnew(size);
	}
	else
	{
		str = ft_strnew(size + ft_strlen(f));
		while (f[i])
			str[i] = f[i++];
		while (j < size)
			str[i++] = end[j++];
	}
	return (str);
}

int get_next_line(const int fd, char **line)
{
	static t_list *qwe;
	int ret;
	char buf[BUFF_SIZE + 1];
	int i;

	i = 1;
	qwe = ft_lstadd_end(*);
	while(ret = read(fd, buf, BUFF_SIZE))
	{
		qwe->content = ft_stradd_end(qwe->content, buf, ret))

	}
}
