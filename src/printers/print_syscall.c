/*
** print_syscall.c for  in /home/moutou_m/c/PSU_2016_strace/src/printers
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Wed Apr 12 10:52:09 2017 moutoum
** Last update Wed Apr 12 10:52:21 2017 moutoum
*/

#include "strace.h"

void print_syscall(t_syscall *syscall, void *regs, pid_t pid, int sys_mod)
{
	static size_t offsets[] = {
	    offsetof(struct user_regs_struct, rdi),
	    offsetof(struct user_regs_struct, rsi),
	    offsetof(struct user_regs_struct, rdx),
	    offsetof(struct user_regs_struct, r10),
	    offsetof(struct user_regs_struct, r8),
	    offsetof(struct user_regs_struct, r9)};
	int i;

	i = 0;
	printf("%s(", syscall->name);
	while (i < syscall->nparams)
	{
		if (sys_mod)
			syscall->params[i](regs + offsets[i], pid, regs);
		else
			print_hexa(regs + offsets[i]);
		if (i < syscall->nparams - 1)
			printf(", ");
		i++;
	}
}
