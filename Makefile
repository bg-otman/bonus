SRCS = ft_putchar.c ft_valid_flag.c ft_skip_chars.c ft_nbr_len.c ft_valid_specifier.c ft_putspace_after.c ft_putstr.c ft_atoi.c ft_putnbr.c ft_printf_bonus.c ft_puthex.c ft_putunsint.c ft_putadresse.c
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