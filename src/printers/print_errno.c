/*
** print_errno.c for  in /home/moutou_m/c/PSU_2016_strace/src/printers
** 
** Made by moutoum
** Login   <maxence.moutoussamy@epitech.eu>
** 
** Started on  Wed Apr 12 10:51:25 2017 moutoum
** Last update Wed Apr 12 10:51:26 2017 moutoum
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "strace.h"

static const t_flag errno_tab[] = {
    FLAG(E2BIG),
    FLAG(EACCES),
    FLAG(EADDRINUSE),
    FLAG(EADDRNOTAVAIL),
    FLAG(EADV),
    FLAG(EAFNOSUPPORT),
    FLAG(EAGAIN),
    FLAG(EALREADY),
    FLAG(EBADE),
    FLAG(EBADF),
    FLAG(EBADFD),
    FLAG(EBADMSG),
    FLAG(EBADR),
    FLAG(EBADRQC),
    FLAG(EBADSLT),
    FLAG(EBFONT),
    FLAG(EBUSY),
    FLAG(ECANCELED),
    FLAG(ECHILD),
    FLAG(ECHRNG),
    FLAG(ECOMM),
    FLAG(ECONNABORTED),
    FLAG(ECONNREFUSED),
    FLAG(ECONNRESET),
    FLAG(EDEADLK),
    FLAG(EDEADLOCK),
    FLAG(EDESTADDRREQ),
    FLAG(EDOM),
    FLAG(EDQUOT),
    FLAG(EEXIST),
    FLAG(EFAULT),
    FLAG(EFBIG),
    FLAG(EHOSTDOWN),
    FLAG(EHOSTUNREACH),
    FLAG(EIDRM),
    FLAG(EILSEQ),
    FLAG(EINPROGRESS),
    FLAG(EINTR),
    FLAG(EINVAL),
    FLAG(EIO),
    FLAG(EISCONN),
    FLAG(EISDIR),
    FLAG(EL2HLT),
    FLAG(EL2NSYNC),
    FLAG(EL3HLT),
    FLAG(EL3RST),
    FLAG(ELIBACC),
    FLAG(ELIBBAD),
    FLAG(ELIBEXEC),
    FLAG(ELIBMAX),
    FLAG(ELIBSCN),
    FLAG(ELNRNG),
    FLAG(ELOOP),
    FLAG(EMFILE),
    FLAG(EMLINK),
    FLAG(EMSGSIZE),
    FLAG(EMULTIHOP),
    FLAG(ENAMETOOLONG),
    FLAG(ENETDOWN),
    FLAG(ENETRESET),
    FLAG(ENETUNREACH),
    FLAG(ENFILE),
    FLAG(ENOANO),
    FLAG(ENOBUFS),
    FLAG(ENOCSI),
    FLAG(ENODATA),
    FLAG(ENODEV),
    FLAG(ENOENT),
    FLAG(ENOEXEC),
    FLAG(ENOLCK),
    FLAG(ENOLINK),
    FLAG(ENOMEM),
    FLAG(ENOMSG),
    FLAG(ENONET),
    FLAG(ENOPKG),
    FLAG(ENOPROTOOPT),
    FLAG(ENOSPC),
    FLAG(ENOSR),
    FLAG(ENOSTR),
    FLAG(ENOSYS),
    FLAG(ENOTBLK),
    FLAG(ENOTCONN),
    FLAG(ENOTDIR),
    FLAG(ENOTEMPTY),
    FLAG(ENOTSOCK),
    FLAG(ENOTSUP),
    FLAG(ENOTTY),
    FLAG(ENOTUNIQ),
    FLAG(ENXIO),
    FLAG(EOPNOTSUPP),
    FLAG(EOVERFLOW),
    FLAG(EOWNERDEAD),
    FLAG(EPERM),
    FLAG(EPFNOSUPPORT),
    FLAG(EPIPE),
    FLAG(EPROTO),
    FLAG(EPROTONOSUPPORT),
    FLAG(EPROTOTYPE),
    FLAG(ERANGE),
    FLAG(EREMCHG),
    FLAG(EREMOTE),
    FLAG(ERESTART),
    FLAG(EROFS),
    FLAG(ESHUTDOWN),
    FLAG(ESOCKTNOSUPPORT),
    FLAG(ESPIPE),
    FLAG(ESRCH),
    FLAG(ESRMNT),
    FLAG(ESTALE),
    FLAG(ESTRPIPE),
    FLAG(ETIME),
    FLAG(ETIMEDOUT),
    FLAG(ETOOMANYREFS),
    FLAG(ETXTBSY),
    FLAG(EUNATCH),
    FLAG(EUSERS),
    FLAG(EWOULDBLOCK),
    FLAG(EXDEV),
    FLAG(EXFULL),
    FLAG(-1)};

static const char *get_errno_macro_str(int flag)
{
	int i;

	i = 0;
	while (errno_tab[i].flag != -1)
	{
		if (errno_tab[i].flag == flag)
			break;
		i++;
	}
	return (errno_tab[i].to_str);
}

int print_errno(int nb)
{
	if (nb < 0 && nb >= -4095)
	{
		printf("-1");
		nb *= -1;
		printf(" %s (%s)", get_errno_macro_str(nb), strerror(nb));
		return (1);
	}
	return (0);
}
