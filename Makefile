NAME = push_swap
CC = cc
CFLAGS =  -Wall -Wextra -Werror
RM = rm -f
BONUS = checker

P_SRC = srcs/push_swap/push_swap.c

C_SRC = srcs/checker/checker.c \
		srcs/checker/checker_utils.c \
		srcs/checker/ps_strcmp.c

SRC = \
	srcs/push_swap/ac2case.c \
	srcs/push_swap/find_way.c \
	srcs/push_swap/get_index.c \
	srcs/push_swap/is_sorted.c \
	srcs/push_swap/papb.c \
	srcs/push_swap/print_error.c \
	srcs/push_swap/ps_atoi.c \
	srcs/push_swap/ps_lstadd_back.c \
	srcs/push_swap/ps_lstadd_front.c \
	srcs/push_swap/ps_lstnew.c \
	srcs/push_swap/ps_split.c \
	srcs/push_swap/push_to.c \
	srcs/push_swap/rotation_times.c \
	srcs/push_swap/rr.c \
	srcs/push_swap/rrr.c \
	srcs/push_swap/sasb.c \
	srcs/push_swap/set_rotation.c \
	srcs/push_swap/set_stack_a.c \
	srcs/push_swap/sort_atob.c \
	srcs/push_swap/sort_btoa.c \
	srcs/push_swap/sort.c \
	srcs/push_swap/stack_size.c \
	srcs/push_swap/tail_number.c

P_OBJS = $(P_SRC:.c=.o)
C_OBJS = $(C_SRC:.c=.o)
OBJS = $(SRC:.c=.o)

$(NAME): $(P_OBJS) $(OBJS)
	$(CC) $(P_OBJS) $(OBJS) -o $(NAME)

$(BONUS): $(C_OBJS) $(OBJS)
	$(CC) $(C_OBJS) $(OBJS) -o $(BONUS)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	$(RM) $(P_OBJS) $(C_OBJS) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus