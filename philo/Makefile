NAME = philo

INCLUDE = philo.h

CFLAGS =  -Wall -Wextra -Werror #-g -fsanitize=address

RM = rm -f

CC = cc

SRC = synchro_utils.c filling.c parsing.c safe.c dining.c getters_stters.c monitor.c utils.c write.c philo_main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
