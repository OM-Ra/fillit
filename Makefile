# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 11:14:20 by mdelphia          #+#    #+#              #
#    Updated: 2019/05/21 11:14:22 by mdelphia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

WAY = ./libft/

SRC = ./src/

INC = ./includ/

C_FILE = main.c get_next_line.c ft_fdopen_rdonly.c\
		 ft_errorfile.c ft_fileread.c ft_freemas.c\
		 ft_map.c ft_tetris.c ft_count_abs.c

FILE_C = $(addprefix $(SRC), $(C_FILE))

FILE_O = $(C_FILE:.c=.o)

HEAD = -I $(INC) -I $(WAY)

FLAGS = -Wall -Wextra -Werror

CMPL_O = gcc -o $(NAME) $(FILE_O) $(LIBFT)

LIBFT = -L $(WAY) -l ft

all: $(NAME)

$(NAME): $(LIBFT) $(FILE_O)
	$(CMPL_O)

%.o: $(SRC)%.c
	gcc -o $@ -c $< $(FLAGS) $(HEAD)

$(LIBFT):
	make -C ./libft/

clean:
	make clean -C $(WAY)
	rm -f $(FILE_O)

fclean: clean
	make fclean -C $(WAY)
	rm -f $(NAME)

re: fclean all
	