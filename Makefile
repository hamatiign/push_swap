NAME = push_swap TEST_NAME = test_push_swap

	CC = cc CFLAGS = -Wall - Wextra -
	Werror

		SRCS = main.c print_stack.c push_operations.c swap_operations.c lst_utils
			/ node_clear.c lst_utils / node_new.c lst_utils
			/ stack_add_back.c lst_utils / stack_add_front.c lst_utils
			/ stack_clear.c lst_utils / stack_init.c lst_utils
			/ stack_pop_back.c lst_utils / stack_pop_front.c utils
			/ ps_atoi.c utils /
	ps_isdigit.c utils\ps_strcmp.c

		TEST_SRCS = testmain.c print_stack.c push_operations.c swap_operations.c lst_utils
			/ node_new.c lst_utils / stack_add_back.c lst_utils
			/ stack_add_front.c lst_utils / stack_clear.c lst_utils
			/ stack_init.c lst_utils / stack_pop_back.c lst_utils /
	stack_pop_front.c

		OBJS = $(SRCS
					:.c =.o) TEST_OBJS = $(TEST_SRCS
											:.c =.o)

												all : $(NAME)

														$(NAME)
	: $(OBJS) $(CC) $(CFLAGS) $(OBJS) -
		o $(NAME)

			test : $(TEST_NAME)

						$(TEST_NAME)
	: $(TEST_OBJS) $(CC) $(CFLAGS) $(TEST_OBJS) -
		o $(TEST_NAME)

			%.o : %.c push_swap.h $(CC) $(CFLAGS) -
		c $ <
	-o $ @

		clean : rm -
		f $(OBJS) $(TEST_OBJS)

			fclean : clean rm -
						f $(NAME) $(TEST_NAME)

							re : fclean all

									.PHONY : all clean fclean re test
