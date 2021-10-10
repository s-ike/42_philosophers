NAME		:= philo

SRCDIR		:= ./srcs/
SRCS		:= main.c \
				init_info.c \
				init_philos.c \
				start_philos.c \
				terminate.c \
				time.c \
				utils/ft_atoi.c \
				utils/ft_isdigit.c \
				utils/ft_isnumeric.c \
				utils/ft_isover_intrange.c \
				utils/ft_isspace.c
SRCS		:= $(addprefix $(SRCDIR), $(SRCS))
OBJS		:= $(SRCS:.c=.o)

INCLUDE 	:= -I./includes/

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
