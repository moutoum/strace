/*
** main.c for  in /home/moutou_m/c/PSU_2015_strace/src
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Sun Apr  9 14:06:52 2017 moutoum
** Last update Wed Apr 12 10:45:47 2017 moutoum
*/

#include "strace.h"

void end_syscall(int sys_mod,
		 int i,
		 struct user_regs_struct *regs,
		 pid_t fork_pid)
{
  printf(")\t= ");
  if (!sys_mod)
    {
      if (g_syscall_tab[i].nreturn)
	print_hexa((void *)&regs->rax);
    }
  else
    {
      if (print_errno((int)regs->rax) == 0)
	{
	  if (g_syscall_tab[i].nreturn)
	    g_syscall_tab[i].returnt(&regs->rax, fork_pid, regs);
	}
    }
  printf("\n");
}

int parent_process(pid_t fork_pid, int sys_mod)
{
  int status_wait4;
  long rip;
  struct user_regs_struct regs;
  int syscall;
  int i;

  syscall = 0;
  while (wait4(fork_pid, &status_wait4, 0, NULL) && !WIFEXITED(status_wait4))
    {
      ptrace(PTRACE_GETREGS, fork_pid, NULL, &regs);
      rip = ptrace(PTRACE_PEEKTEXT, fork_pid, regs.rip, NULL);
      if ((rip & 0xffff) == 0x50f && syscall == 0)
	i = begin_syscall(sys_mod, &regs, fork_pid, &syscall);
      else if (syscall == 1)
	{
	  end_syscall(sys_mod, i, &regs, fork_pid);
	  syscall = 0;
	}
      ptrace(PTRACE_SINGLESTEP, fork_pid, NULL, NULL);
    }
  printf("\n+++ exited with %d +++\n", WEXITSTATUS(status_wait4));
  return (0);
}

int child_process(char **av, char **ev)
{
  if (ptrace(PT_TRACE_ME, 0, NULL, NULL) == -1)
    return (perror("ptrace"), EXIT_FAILURE);
  if (execve(av[0], av, ev) == -1)
    return (perror("execve"), EXIT_FAILURE);
  return (0);
}

int parsing(t_opt *opt, int ac, char **av, int *fork_pid)
{
  int i;
  int t;

  i = 1;
  t = 1;
  opt->sys_mod = 0;
  opt->has_pid = 0;
  while (i < ac)
    {
      if (!strcmp("-s", av[i]))
	{
	  opt->sys_mod = 1;
	  t++;
	}
      else if (!strcmp("-p", av[i]) && (i + 1) < ac)
	{
	  opt->has_pid = 1;
	  *fork_pid = atoi(av[i + 1]);
	  if (*fork_pid == 0)
	    return (EXIT_FAILURE);
	  t += 2;
	}
      i++;
    }
  return (t);
}

int main(int ac, char **av, char **ev)
{
  pid_t fork_pid;
  t_opt opt;
  int t;

  setbuf(stdout, NULL);
  t = parsing(&opt, ac, av, &fork_pid);
  if (opt.has_pid)
    {
      if (ptrace(PT_ATTACH, fork_pid, NULL, NULL) == -1)
	return (perror("ptrace(PT_ATTACH)"), EXIT_FAILURE);
    }
  else
    {
      if ((fork_pid = fork()) == -1)
	return (perror("fork"), EXIT_FAILURE);
    }
  
  if (fork_pid)
    parent_process(fork_pid, opt.sys_mod);
  else
    child_process(&av[t], ev);
  return (EXIT_SUCCESS);
}
