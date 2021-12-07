NAME	= cub3d

SRCDIR	= src

SRCS	= $(shell find $(SRCDIR)/*.c)\
			src/gnl/get_next_line.c src/gnl/get_next_line_utils.c
HEADERS	= $(shell find $(INCDIR)/*.h);

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))

INCDIR	= inc

MLXDIR	= mlx

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

API		= -lmlx -framework OpenGL -framework AppKit

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HEADERS)
				$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLXDIR) -c $< -o $@
                
all:		$(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)
			mkdir -p $(OBJDIR)/gnl

$(NAME):	$(OBJDIR) $(OBJS)
			make -C mlx
			$(CC) $(CFLAGS) $(OBJS) $(API) -o $(NAME)

install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c
			cp ~/Desktop/Proj_init/inc.h $(INCIDR)/${NAME}.h
clean:
			$(RM) -r $(OBJDIR) $(NAME).dSYM .DS_Store

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re install
