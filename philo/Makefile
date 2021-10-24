NAME		:= philo

SRCDIR		:= ./srcs/
OBJDIR		:= ./objs/
UTILDIR		:= ft_utils/
VPATH		:= $(SRCDIR):$(SRCDIR)$(UTILDIR)

SRCS		:= main.c \
				ft_init_info.c \
				ft_init_philos.c \
				ft_is_valid_arg_nums.c \
				ft_mutex_print.c \
				ft_philo_routine.c \
				ft_philo_routine2.c \
				ft_puterror.c \
				ft_start_philos.c \
				ft_terminate.c \
				ft_time.c \
				$(UTILDIR)ft_atoi.c \
				$(UTILDIR)ft_isdigit.c \
				$(UTILDIR)ft_iseven.c \
				$(UTILDIR)ft_isnumeric.c \
				$(UTILDIR)ft_isover_intrange.c \
				$(UTILDIR)ft_ispositive.c \
				$(UTILDIR)ft_isspace.c
SRCS		:= $(addprefix $(SRCDIR), $(SRCS))
OBJS		:= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
DEPENDS		:= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.d)))

INCLUDE 	:= -I./includes/ -I./includes/defs/ -I./includes/types/

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -pthread -MMD -MP

ifdef TH
DEBUG		:= -g -fsanitize=thread
else
DEBUG		:= -g
endif
ifdef MEM
DEBUG2		:= -fsanitize=address
else
DEBUG2		:=
endif

RM			:= rm -f
C_GREEN		:= "\033[32m"
C_DEFAULT	:= "\033[39m"
C_RESET		:= "\033[m"


$(OBJDIR)%.o:	%.c
			@if [ ! -d $(OBJDIR) ]; then \
				echo ";; mkdir $(OBJDIR)"; mkdir $(OBJDIR); \
			fi
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(DEBUG) $(DEBUG2) $(OBJS) -o $@
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

bonus:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(DEPENDS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

leaks:
			$(MAKE) CFLAGS="$(CFLAGS) -D LEAKS=1" LEAKS=TRUE

mem:
			$(MAKE) MEM=TRUE

th:
			$(MAKE) TH=TRUE

-include	$(DEPENDS)

.PHONY:		all clean fclean re bonus
.PHONY:		leaks mem th
