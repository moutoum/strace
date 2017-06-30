/*
** main.c for  in /home/moutou_m/c/PSU_2015_strace
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Sun Apr  9 14:02:41 2017 moutoum
** Last update Sun Apr  9 14:02:42 2017 moutoum
*/

#include <unistd.h>

int main()
{
	char str[11] = { 'T', 'o', 't', 'o', 32, 31, 30, 25, 12, 1, 0};
	write(1, str, 11);
}
