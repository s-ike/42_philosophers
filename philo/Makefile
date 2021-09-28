NAME		:= philo

SRCDIR		:= ./srcs/
SRCS		:= main.c \
				utils.c
SRCS		:= $(addprefix $(SRCDIR), $(SRCS))
OBJS		:= $(SRCS:.c=.o)

INCLUDE 	:= -I./includes/

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

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

.PHONY:		all clean fclean re bonus
