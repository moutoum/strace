/*
** print_mmap_flag.c for  in /home/moutou_m/c/PSU_2016_strace/src/printers
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Wed Apr 12 10:51:54 2017 moutoum
** Last update Wed Apr 12 10:51:55 2017 moutoum
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include "strace.h"

static const t_flag flag_tab_prot[] = {
    FLAG(PROT_READ),
    FLAG(PROT_WRITE),
    FLAG(PROT_EXEC),
    FLAG(-1)};

static const t_flag flag_tab_map[] = {
    FLAG(MAP_SHARED),
    FLAG(MAP_PRIVATE),
    FLAG(MAP_32BIT),
    FLAG(MAP_FIXED),
    FLAG(MAP_ANONYMOUS),
    FLAG(MAP_DENYWRITE),
    FLAG(MAP_EXECUTABLE),
    FLAG(MAP_GROWSDOWN),
    FLAG(MAP_HUGETLB),
    FLAG(MAP_LOCKED),
    FLAG(MAP_NONBLOCK),
    FLAG(MAP_NORESERVE),
    FLAG(MAP_POPULATE),
    FLAG(MAP_STACK),
    FLAG(-1)};

void print_mmap_prot(int *_nb)
{
	int flag;
	int i;
	int is_first;

	flag = *_nb;
	i = 0;
	is_first = 1;
	while (flag_tab_prot[i].flag != -1)
	{
		if ((flag & flag_tab_prot[i].flag) == flag_tab_prot[i].flag)
		{
			if (!is_first)
				printf("|");
			printf("%s", flag_tab_prot[i].to_str);
			is_first = 0;
		}
		i++;
	}
}

void print_mmap_map(int *_nb)
{
	int flag;
	int i;
	int is_first;

	flag = *_nb;
	i = 0;
	is_first = 1;
	while (flag_tab_map[i].flag != -1)
	{
		if ((flag & flag_tab_map[i].flag) == flag_tab_map[i].flag)
		{
			if (!is_first)
				printf("|");
			printf("%s", flag_tab_map[i].to_str);
			is_first = 0;
		}
		i++;
	}
}
