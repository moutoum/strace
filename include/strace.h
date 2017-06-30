/*
** strace.h for  in /home/moutou_m/c/PSU_2016_strace/include
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Wed Apr 12 10:52:34 2017 moutoum
** Last update Wed Apr 12 10:52:35 2017 moutoum
*/

#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/user.h>
#include <syscall.h>
#include <stdio.h>
#include <stddef.h>

typedef unsigned long long t_syscall_id;

typedef void (*t_callback)();

typedef struct s_syscall
{
	const t_syscall_id id;
	const char *name;
	const uint8_t nparams;
	const t_callback params[6];
	const uint8_t nreturn;
	const t_callback returnt;
} t_syscall;

extern t_syscall g_syscall_tab[];

#define SYSCALL_TAB_SIZE 6

int begin_syscall(int sys_mod, struct user_regs_struct *regs, pid_t fork_pid,
		  int *syscall);
void print_syscall(t_syscall *syscall, void *regs, pid_t pid, int sys_mod);
void print_integer(int *nb);
void print_str(long long *addr, pid_t pid);
void print_ptr(long long *p);
void print_str_write(long long *addr, pid_t pid,
		     struct user_regs_struct *regs);
void print_open_flag(int *_nb);
void print_access_flag(int *_nb);
void print_mmap_prot(int *_nb);
void print_mmap_map(int *_nb);
void print_hexa(long long *p);
int print_errno(int nb);
void print_fstat(long long *addr, pid_t pid);

typedef struct s_flag
{
	const int flag;
	const char *to_str;
} t_flag;

#define FLAG(f)       \
	{             \
		f, #f \
	}

typedef struct s_opt
{
	int has_pid;
	int sys_mod;
} t_opt;
