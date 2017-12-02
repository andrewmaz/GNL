/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:11:14 by amazurok          #+#    #+#             */
/*   Updated: 2017/11/24 12:50:02 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
#include <stdio.h>
#include "./libft/libft.h"

int        main(int argc, char **argv)
{
    int        fd;
    char    *line;

    if (argc == 1)
        fd = 0;
    else if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        return (2);
    /*while (get_next_line(fd, &line) == 1)
    {
        ft_putendl(line);
        free(line);
    }*/
    get_next_line(fd, &line);
    printf("%s\n", line);
    //printf("2- %d\n", get_next_line(-1, &line));
    if (argc == 2)
        close(fd);
}
