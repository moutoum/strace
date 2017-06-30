#
# Binary name
#
NAME		=	strace

#
# Sources
#
SRC		=	src/main.c \
			src/syscall_tab.c \
			src/printers.c \
			src/printers/print_errno.c \
			src/printers/print_integer.c \
			src/printers/print_open_flag.c \
			src/printers/print_access_flag.c \
			src/printers/print_hexa.c \
			src/printers/print_mmap_flag.c \
			src/printers/print_syscall.c \
			src/begin_syscall.c \
			src/printers/print_fstat.c

#
# Compilator
#
CC		=	gcc

#
# Compilation flags
#
CFLAGS	+=	-W \
			-Wall \
			-Werror \
			-Wextra -g

#
# Include flags
#
CFLAGS		+=	-I./include

#
# Linking flags
#
LDFLAGS		+=

#
# .cpp to .o
#
OBJ		=	$(SRC:.c=.o)

#
# Rm
#
RM		=	@rm -f

#####################################################


all: $(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@  && \
	/bin/echo -e "\033[32;1m"$<"\033[0m" || \
	/bin/echo -e "\033[31;1m"$<"\033[0m"
