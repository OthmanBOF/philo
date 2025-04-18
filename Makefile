NAME = philo

INCLUDE = philo.h

CFLAGS = -g -fsanitize=address

RM = rm -f

CC = cc

SRC = ./mand/synchro_utils.c ./mand/filling.c ./mand/parsing.c ./mand/safe.c ./mand/dining.c ./mand/getters_stters.c ./mand/monitor.c ./mand/utils.c ./mand/write.c ./mand/philo.c

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
