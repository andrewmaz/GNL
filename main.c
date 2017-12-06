/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:11:14 by amazurok          #+#    #+#             */
/*   Updated: 2017/12/06 19:28:16 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "get_next_line.h"

int        main(int argc, char **argv)
{
    int        fd0;
    int        fd1;
    //int        fd2;
    char    *line;

    if (argc == 1)
        fd0 = 0;
    fd1 = open(argv[1], O_RDONLY);
    //fd2 = open(argv[2], O_RDONLY);
    
    while (get_next_line(fd1, &line) == 1)
    {
        ft_putendl(line);
        free(line);
    }
    
    /*get_next_line(fd1, &line);
    printf("main line 1 %s\n", line);
    ft_strclr(line);
    free(line);
    get_next_line(fd1, &line);
    printf("main line 1 %s\n", line);
    get_next_line(fd2, &line);
    printf("main line 2 %s\n", line);
    get_next_line(fd1, &line);
    printf("main line 1 %s\n", line);
    get_next_line(fd2, &line);
    printf("main line 2 %s\n", line);*/
    //printf("2- %d\n", get_next_line(-1, &line));
    if (argc == 2)
        close(fd1);
}
