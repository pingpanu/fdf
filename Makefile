#variables
PLAY = play_mlx
CC = gcc
FLAGS = -Wall -Wextra -Werror
SDIR = srcs/
MLINUX = mlx_Linux

#color
DCL = '\033[0m'
RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'
PURPLE = '\033[0;35m'
CYAN = '\033[0;36m'

#sources
SRC_NAME = play_mlx.c 

SRCS = $(addprefix $(SDIR), $(SRC_NAME))
OBJS = $(SRC_NAME:.c=.o)

%.o: $(SDIR)%.c
		@ $(CC) $(FLAGS) -I/usr/include -Imlx_Linux -c $< -o $@

all : $(PLAY)

$(PLAY) : $(OBJS)
		@ make -C $(MLINUX)
		@ echo "$(YELLOW)libmlx_Linux created$(DCL)"
		@ $(CC) $(OBJS) -L $(MLINUX) -lmlx_Linux -L/usr/lib -I $(MLINUX) -lXext -lX11 -lm -lz -o $(PLAY)
		@ echo "$(GREEN)done$(DCL)"

clean:
		@ rm *.o
		@ echo "$(RED)object file deleted$(DCL)"

fclean: clean
		@ rm -f $(PLAY)
		@ make clean -C $(MLINUX)
		@ echo "$(RED)libmlx_Linux and play_mlx deleted$(DCL)"

re: fclean all

.PHONY: all clean fclean re