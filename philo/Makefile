NAME		:= philo

SRCDIR		:= ./srcs/
SRCS		:= main.c \
				ft_init_info.c \
				ft_init_philos.c \
				ft_mutex_print.c \
				ft_start_philos.c \
				ft_terminate.c \
				ft_time.c \
				ft_utils/ft_atoi.c \
				ft_utils/ft_isdigit.c \
				ft_utils/ft_isnumeric.c \
				ft_utils/ft_isodd.c \
				ft_utils/ft_isover_intrange.c \
				ft_utils/ft_isspace.c
SRCS		:= $(addprefix $(SRCDIR), $(SRCS))
OBJS		:= $(SRCS:.c=.o)

INCLUDE 	:= -I./includes/ -I./includes/defs/ -I./includes/types/

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -pthread

DEBUG		:= -g
ifdef LEAKS
DEBUG2		:=
else
DEBUG2		:= -fsanitize=address
endif

RM			:= rm -f
C_GREEN		:= "\x1b[32m"
C_DEFAULT	:= "\x1b[39m"
C_RESET		:= "\x1b[0m"


.c.o:
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(OBJS) -o $@
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

bonus:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

leaks:
			$(MAKE) CFLAGS="$(CFLAGS) -D LEAKS=1" LEAKS=TRUE

.PHONY:		all clean fclean re bonus
.PHONY:		leaks
