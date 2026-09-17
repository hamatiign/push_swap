NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	main.c \
	parse.c \
	operations/push_operations.c \
	operations/swap_operations.c \
	operations/rotate_operations.c \
	operations/rev_rotate_operations.c \
	lst_utils/node_new.c \
	lst_utils/stack_add_back.c \
	lst_utils/stack_add_front.c \
	lst_utils/stack_clear.c \
	lst_utils/stack_init.c \
	lst_utils/stack_pop_back.c \
	lst_utils/stack_pop_front.c \
	lst_utils/set_rank.c \
	lst_utils/stats_init.c \
	utils/ps_atoi.c \
	utils/ps_isdigit.c \
	utils/ps_strcmp.c \
	sort/utils.c \
	sort/complex_sort.c \
	sort/medium_sort.c \
	sort/simple_sort.c \
	bench.c \
	disorder.c \
	print_disorder.c

PRINTF_SRCS = \
	ft_printf/ft_print_char.c \
	ft_printf/ft_print_hex.c \
	ft_printf/ft_print_int.c \
	ft_printf/ft_print_percent.c \
	ft_printf/ft_print_ptr.c \
	ft_printf/ft_print_string.c \
	ft_printf/ft_print_uint.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putnbr_base.c


OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_OBJS) -lm -o $(NAME)

%.o: %.c push_swap.h ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
