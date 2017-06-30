/*
** printers.c for  in /home/moutou_m/c/PSU_2015_strace/src
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Sun Apr  9 14:06:59 2017 moutoum
** Last update Wed Apr 12 10:49:51 2017 moutoum
*/

#include <sys/ptrace.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/user.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "strace.h"

void print_str(long long *addr, pid_t pid)
{
  char c;
  long long a;

  a = *addr;
  printf("\"");
  while ((c = (char)ptrace(PTRACE_PEEKDATA, pid, a, NULL)))
    {
      printf("%c", c);
      a++;
    }
  printf("\"");
}

void print_ptr(long long *p)
{
  *p ? printf("0x%llx", *p) : printf("NULL");
}

void print_str_write(long long *addr, pid_t pid, struct user_regs_struct *regs)
{
  char c;
  long long a;
  int i;
  static char char_tab[7] = {'a', 'b', 't', 'n', 'v', 'f', 'r'};

  a = *addr;
  i = 0;
  printf("\"");
  while (i < (int)regs->rdx)
    {
      c = (char)ptrace(PTRACE_PEEKDATA, pid, a, NULL);
      if (isprint(c))
	printf("%c", c);
      else if (c >= '\a' && c <= '\r')
	printf("\\%c", char_tab[c - '\a']);
      else
	printf("\\%o", c);
      a++;
      i++;
    }
  printf("\"");
}
