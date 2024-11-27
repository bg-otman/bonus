SRCS =  ft_strlen.c ft_putbefore.c ft_get_arglen.c ft_atoi.c ft_nbr_len.c ft_count_chars.c ft_putspace_after.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c ft_puthex.c ft_putunsint.c ft_putadresse.c
OBJECTS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = libftprintf.h
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
.SECONDARY : $(OBJECTS)