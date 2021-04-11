C_FILES = sort_small.c mamaciita_fill_memo.c free_tab.c  split_shit.c mamaciita.c valid_arg.c swap_stack.c gen_list.c get_info.c make_decision.c read_input.c test_swap.c is_sorted.c get_name.c add_inst.c stack_fun.c rrr.c rra.c rrb.c ra.c rb.c rr.c sa.c sb.c ss.c pa.c pb.c apply_instructions.c sort_3.c sort_3b.c merge_inst.c

C_OBJS = $(C_FILES:.c=.o)

C_FILE_CHECKER = checker.c

O_FILE_CHECKER = checker.o

C_FILE_PUSH_SWAP=push_swap.c

O_FILE_PUSH_SWAP=push_swap.o

HEADER = push_swap.h

LIB = libft.a

LIB_PATH = libft

NAME_1 = checker

NAME_2 = push_swap

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

all : $(NAME_1) $(NAME_2)

$(NAME_1) : $(LIB_PATH)/$(LIB) $(C_OBJS) $(O_FILE_CHECKER)
	$(CC) -o $(NAME_1)  $(C_OBJS) $(O_FILE_CHECKER) $(LIB_PATH)/$(LIB)

$(NAME_2) : $(LIB_PATH)/$(LIB) $(C_OBJS) $(O_FILE_PUSH_SWAP)
	    $(CC) -o $(NAME_2) $(C_OBJS) $(O_FILE_PUSH_SWAP) $(LIB_PATH)/$(LIB)

$(C_OBJS) : %.o : %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

$(O_FILE_CHECKER) : %.o : %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

$(O_FILE_PUSH_SWAP) : %.o : %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

$(LIB_PATH)/$(LIB):
	make -C $(LIB_PATH)


clean :
	make clean -C $(LIB_PATH)
	rm -rf $(C_OBJS) $(O_FILE_PUSH_SWAP) $(O_FILE_CHECKER)

fclean : clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME_1) $(NAME_2)

re : fclean all	
