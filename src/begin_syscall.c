/*
** begin_syscall.c for  in /home/moutou_m/c/PSU_2016_strace/src
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Wed Apr 12 10:44:13 2017 moutoum
** Last update Wed Apr 12 10:44:42 2017 moutoum
*/

#include <strace.h>

int	begin_syscall(int sys_mod,
		      struct user_regs_struct *regs,
		      pid_t fork_pid,
		      int *syscall)
{
  int i;

  i = 0;
  while (g_syscall_tab[i].id != (t_syscall_id)-1)
    {
      if (g_syscall_tab[i].id == regs->rax)
	{
	  print_syscall(&g_syscall_tab[i], regs, fork_pid, sys_mod);
	  break;
	}
      i++;
    }
  if (g_syscall_tab[i].id != (t_syscall_id)-1)
    {
      *syscall = 1;
      if (!g_syscall_tab[i].nreturn)
	{
	  printf(")\t= ?");
	  *syscall = 0;
	}
    }
  return (i);
}
