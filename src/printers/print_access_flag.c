/*
** print_access_flag.c for  in /home/moutou_m/c/PSU_2016_strace/src/printers
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Wed Apr 12 10:50:49 2017 moutoum
** Last update Wed Apr 12 10:51:17 2017 moutoum
*/

#include <unistd.h>
#include <stdio.h>
#include "strace.h"

static const t_flag flag_tab[] = {
    FLAG(X_OK),
    FLAG(R_OK),
    FLAG(W_OK),
    FLAG(F_OK),
    FLAG(-1)};

void print_access_flag(int *_nb)
{
  int flag;
  int i;

  flag = *_nb;
  i = 0;
  while (flag_tab[i].flag != -1)
    {
      if ((flag & flag_tab[i].flag) == flag_tab[i].flag)
	{
	  printf("%s", flag_tab[i].to_str);
	  break;
	}
      i++;
    }
}
