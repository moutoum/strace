/*
** print_open_flag.c for  in /home/moutou_m/c/PSU_2016_strace/src/printers
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Wed Apr 12 10:52:03 2017 moutoum
** Last update Wed Apr 12 10:52:04 2017 moutoum
*/

#include <fcntl.h>
#include <stdio.h>
#include "strace.h"

static const t_flag flag_tab[] = {
    FLAG(O_RDONLY),
    FLAG(O_WRONLY),
    FLAG(O_RDWR),
    FLAG(O_APPEND),
    FLAG(O_ASYNC),
    FLAG(O_CLOEXEC),
    FLAG(O_CREAT),
    FLAG(O_DIRECTORY),
    FLAG(O_DSYNC),
    FLAG(O_EXCL),
    FLAG(O_NOCTTY),
    FLAG(O_NOFOLLOW),
    FLAG(O_NONBLOCK),
    FLAG(O_NDELAY),
    FLAG(O_SYNC),
    FLAG(O_TRUNC),
    FLAG(-1)};

void print_open_flag(int *_nb)
{
	int flag;
	int i;
	int is_first;

	flag = *_nb;
	i = 0;
	is_first = 1;
	while (flag_tab[i].flag != -1)
	{
		if ((flag & flag_tab[i].flag) == flag_tab[i].flag)
		{
			if (!is_first)
				printf("|");
			printf("%s", flag_tab[i].to_str);
			is_first = 0;
		}
		i++;
	}
}
