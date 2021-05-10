SRCS_PUSH	=	srcs/push_swap/check_sort.c \
				srcs/push_swap/five_swap.c \
				srcs/push_swap/get_closest_nb.c \
				srcs/push_swap/get_lowest_nb.c \
				srcs/push_swap/get_lowest_operation.c \
				srcs/push_swap/get_nth_nb.c \
				srcs/push_swap/get_up_down.c \
				srcs/push_swap/hundreds_swap.c \
				srcs/push_swap/main.c \
				srcs/push_swap/push_swap.c \
				srcs/push_swap/put_to.c \
				srcs/push_swap/var_edit.c

SRCS_CHECK	=	srcs/checker/checker.c \
				srcs/checker/main.c

SRCS_BOTH	=	srcs/operations/pa.c \
				srcs/operations/pb.c \
				srcs/operations/ra.c \
				srcs/operations/rb.c \
				srcs/operations/rra.c \
				srcs/operations/rrb.c \
				srcs/operations/rr.c \
				srcs/operations/rrr.c \
				srcs/operations/sa.c \
				srcs/operations/sb.c \
				srcs/operations/ss.c \
				srcs/utils/error.c \
				srcs/utils/fill_tab.c \
				srcs/utils/ft_atoi.c \
				srcs/utils/ft_isdigit.c \
				srcs/utils/ft_lstnew.c \
				srcs/utils/ft_putnbr.c \
				srcs/utils/ft_strcmp.c \
				srcs/utils/ft_strlen.c \
				srcs/utils/get_min_max_abso.c \
				srcs/utils/is_sorted.c \
				srcs/utils/lists.c \
				srcs/utils/lst_size.c \
				srcs/utils/print_list.c	\
				srcs/utils/print_operations.c	\
				srcs/utils/get_options.c	\
				srcs/utils/ft_strstr.c	\
				srcs/utils/read_array.c

INCLUDES	=	-I./includes

OBJS_PUSH	=$(SRCS_PUSH:.c=.o)

OBJS_CHECK	=$(SRCS_CHECK:.c=.o)

OBJS_BOTH	=$(SRCS_BOTH:.c=.o)

PUSH		=	push_swap

CHECK		=	checker

CFLAGS      =   -Wall -Werror -Wextra

CC			=	gcc

RM			=	rm -f

.c.o:
				${CC} ${CFLAGS} -c ${INCLUDES} $< -o ${<:.c=.o}

all:			push_swap checker

checker:		${OBJS_CHECK} ${OBJS_BOTH}
				${CC} ${CFLAGS} -o ${CHECK} ${OBJS_CHECK} ${OBJS_BOTH}

push_swap:		${OBJS_PUSH} ${OBJS_BOTH}
				${CC}  ${CFLAGS} -o ${PUSH} ${OBJS_PUSH} ${OBJS_BOTH}

clean:
				${RM} ${OBJS_PUSH} ${OBJS_CHECK} ${OBJS_BOTH}

fclean:			clean
				${RM} ${PUSH} ${CHECK}

re:				fclean all

.PHONY:			all clean fclean re
