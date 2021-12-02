NAME	= cub3d

SRCDIR	= src

SRCS	= $(shell find $(SRCDIR)/*.c)\
			src/gnl/get_next_line.c src/gnl/get_next_line_utils.c

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))

INCDIR	= inc

GNLDIR	= src/gnl

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
			$(CC) $(CFLAGS) -I$(INCDIR) -I$(GNLDIR) -c $^ -o $@
                
all:		$(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)
			mkdir -p $(OBJDIR)/gnl

$(NAME):	$(OBJDIR) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c
			cp ~/Desktop/Proj_init/inc.h $(INCIDR)/${NAME}.h
clean:
			$(RM) -r $(OBJDIR)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re install
